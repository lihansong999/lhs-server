#ifndef __FRAMEWORK_SCHEDULE_H__
#define __FRAMEWORK_SCHEDULE_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWString.h"
#include "FWLock.h"

FW_NS_BEGIN


/*
定时事件
线程安全的
*/
template <class T>
class FWSchedule
{
	struct ScheduleData {
		bool			_pause;
		bool			_hpFirst;
		bool			_hpCount;
		unsigned int	_count;
		long long		_msInvl;
		long long		_iteration;
		T				_func;
	};
public:
	FWSchedule() :_running(false), _runMsInvl(0), _scheduleIDBase(0), _iteration(Framework::FW_TIME()) {};
	FWSchedule(const FWSchedule & other) = delete;
	FWSchedule& operator=(const FWSchedule & other) = delete;
	FWSchedule(FWSchedule && other) = delete;
	FWSchedule& operator=(FWSchedule && other) = delete;
	~FWSchedule() 
	{
		this->Stop();
	}

	/*
	加入到队列
	本函数返回值是这次添加所生成的ID，通过此ID可在之后进行其他操作。
	func：模版实例化的类型必须支持func(long long msInvl, Framework::FW_ID id)的调用方式
	msInvl：间隔调用时间（毫秒）
	count：调用次数
	hpFirst：首次func调用的时间是否需要尽量精确
	hpCount：调用次数是否需要精确，例如情况：msInvl设置为10 ，但实际间隔了30才调用Update，非精确调用方式为func(30, id)，精确调用方式为func(30, id);func(0, id);func(0, id);共floor(实际经过时间/msInvl)次调用
	pause：是否要处于暂停状态
	*/
	FW_ID Add(T func, long long msInvl, unsigned int count = UINT_MAX, bool hpFirst = false, bool hpCount = false, bool pause = false)
	{
		if (msInvl <= 0)
		{
			FW_LOG_ERROR("%s", "msInvl <= 0");
			return 0;
		}
		if (func == nullptr)
		{
			FW_LOG_ERROR("%s", "func == nullptr");
			return 0;
		}
		FW_ID id = InterlockedIncrement64(&_scheduleIDBase);
		ScheduleData * psd = new ScheduleData();
		psd->_pause = pause;
		psd->_hpFirst = hpFirst;
		psd->_hpCount = hpCount;
		psd->_count = count;
		psd->_msInvl = msInvl;
		psd->_iteration = (psd->_hpFirst ? Framework::FW_TIME() : _iteration);
		psd->_func = func;
		_addContainerLock.Lock();
		_addMap.insert(std::pair<FW_ID, ScheduleData*>(id, psd));
		_addContainerLock.UnLock();
		return id;
	}

	/*
	从队列中删除
	*/
	void Remove(FW_ID id)
	{
		_finalContainerLock.Lock();
		std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.find(id);
		if (it != _finalMap.end())
		{
			it->second->_count = 0;
		}
		else
		{
			_addContainerLock.Lock();
			std::map<FW_ID, ScheduleData*>::iterator it2 = _addMap.find(id);
			if (it2 != _addMap.end())
			{
				delete (it2->second);
				_addMap.erase(it2);
			}
			_addContainerLock.UnLock();
		}
		_finalContainerLock.UnLock();
	}

	/*
	暂停
	*/
	void Pause(FW_ID id)
	{
		_finalContainerLock.Lock();
		std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.find(id);
		if (it != _finalMap.end())
		{
			it->second->_pause = true;
		}
		else
		{
			_addContainerLock.Lock();
			std::map<FW_ID, ScheduleData*>::iterator it2 = _addMap.find(id);
			if (it2 != _addMap.end())
			{
				it2->second->_pause = true;
			}
			_addContainerLock.UnLock();
		}
		_finalContainerLock.UnLock();
	}

	/*
	恢复
	*/
	void Resume(FW_ID id)
	{
		_finalContainerLock.Lock();
		std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.find(id);
		if (it != _finalMap.end())
		{
			it->second->_iteration = (it->second->_hpFirst ? Framework::FW_TIME() : _iteration);
			it->second->_pause = false;
		}
		else
		{
			_addContainerLock.Lock();
			std::map<FW_ID, ScheduleData*>::iterator it2 = _addMap.find(id);
			if (it2 != _addMap.end())
			{
				it2->second->_iteration = (it2->second->_hpFirst ? Framework::FW_TIME() : _iteration);
				it2->second->_pause = false;
			}
			_addContainerLock.UnLock();
		}
		_finalContainerLock.UnLock();
	}

	/*
	开始启动独立线程调用Update
	也可以不使用本函数，自行另找合适的地方反复调用Update
	不可在已加入队列的回调中调用本函数
	msInvl：间隔时间（毫秒），频率越快，结果越精确，性能消耗也更大
	*/
	void Start(long long msInvl)
	{
		FWLockScopeController lsc(&_runningLock);
		_runMsInvl = msInvl;
		if (_running)
			return;
		_running = true;
		std::thread t = std::thread([this]() {
			while (_running)
			{
				Update();
				std::this_thread::sleep_for(std::chrono::milliseconds(_runMsInvl));
			}
		});
		t.detach();
	}

	/*
	关闭调用Update的独立线程
	不可在已加入队列的回调中调用本函数
	*/
	void Stop()
	{
		FWLockScopeController lsc(&_runningLock);
		if (!_running)
			return;
		_running = false;
		_finalContainerLock.Lock();
		_addContainerLock.Lock();
		for (std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.begin(); it != _finalMap.end(); it++)
			delete (it->second);
		for (std::map<FW_ID, ScheduleData*>::iterator it = _addMap.begin(); it != _addMap.end(); it++)
			delete (it->second);
		_addContainerLock.UnLock();
		_finalContainerLock.UnLock();
	}

	/*
	更新
	如果没有使用Start，可自行找合适的地方反复调用本函数，调用频率越快，结果越精确，性能消耗也更大
	*/
	void Update()
	{
		_finalContainerLock.Lock();
		_addContainerLock.Lock();
		_iteration = Framework::FW_TIME();
		for (std::map<FW_ID, ScheduleData*>::iterator it = _addMap.begin(); it != _addMap.end(); it++)
		{
			_finalMap.insert(std::pair<FW_ID, ScheduleData*>(it->first, it->second));
		}
		_addMap.clear();
		_addContainerLock.UnLock();
		for (std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.begin(); it != _finalMap.end(); it++)
		{
			if (it->second->_count == 0 || it->second->_pause)
				continue;
			long long invl = _iteration - it->second->_iteration;
			if (invl <= 0)
			{
				it->second->_iteration = _iteration;
				continue;
			}
			if (invl < it->second->_msInvl)
				continue;
			it->second->_iteration = _iteration;
			if (it->second->_hpCount)
			{
				long long c = invl / it->second->_msInvl;
				for (int i = 0; i < (int)c; i++)
				{
					--(it->second->_count);
					it->second->_func(i == 0 ? invl : 0, it->first);
					if (it->second->_count == 0 || it->second->_pause)
						break;
				}
			}
			else
			{
				--(it->second->_count);
				it->second->_func(invl, it->first);
			}
		}
		for (std::map<FW_ID, ScheduleData*>::iterator it = _finalMap.begin(); it != _finalMap.end();)
		{
			if (it->second->_count == 0)
			{
				delete (it->second);
				_finalMap.erase(it++);
			}
			else
			{
				it++;
			}
		}
		_finalContainerLock.UnLock();
	}

private:
	volatile bool					_running;
	FWLock							_runningLock;
	volatile long long				_runMsInvl;
	volatile FW_ID					_scheduleIDBase;
	volatile long long				_iteration;
	std::map<FW_ID, ScheduleData*>	_addMap;
	FWLock							_addContainerLock;
	std::map<FW_ID, ScheduleData*>	_finalMap;
	FWLockRecursive					_finalContainerLock;

};



FW_NS_END


#endif //!__FRAMEWORK_SCHEDULE_H__