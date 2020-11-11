#ifndef __FRAMEWORK_LOGICHANDLERBASE_H__
#define __FRAMEWORK_LOGICHANDLERBASE_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../Common/FWLock.h"
#include "FWLogicDataBase.h"

FW_NS_BEGIN


/*
逻辑处理器基类，
继承后使用，
外部Push逻辑数据，
内部自动选择合适的时机Pop，
Pop之后调用覆盖实现的处理函数。
*/
class FW_DLL FWLogicHandlerBase
{
public:
	FWLogicHandlerBase();
	virtual ~FWLogicHandlerBase();

	/* threadCountHandler：逻辑处理线程数（建议传1，单线程处理逻辑更有利于开发）*/
	bool Start(unsigned int threadCountHandler);
	
	void Stop();

	/* new一个数据压入队列，稍后会通过_onLogicDataHandler传入，当_onLogicDataHandler调用完毕后会自动调用_deleteLogicData进行释放 */
	void PushLogicData(FWLogicDataBase * dataBase);

protected:
	/* 可覆盖实现return一个常量字符串，打印LOG时可以区分不同的FWLogicHandlerBase子类 */
	virtual const char * _getTitle() const;

	/*
	从Start函数开始执行时，到Start函数返回的这段期间内，Start函数内部每当成功创建并运行一个处理线程时都会从这个处理线程中调用此函数一次
	返回的void*将会在之后的_onLogicDataHandler和_onDeleteThread的参数customArg中带入
	*/
	virtual void * _onCreateThread(const char * threadID);

	/* 从Stop函数开始执行时，到Stop函数返回的这段期间内，Stop函数内部每当请求杀死一个处理线程时，即将被杀死的处理线程在临死前会调用此函数一次 */
	virtual void _onDeleteThread(const char * threadID, void * customArg);

	/* 覆盖实现释放调用PushLogicData时传入的dataBase指针 */
	virtual void _deleteLogicData(FWLogicDataBase * dataBase);

	/* 覆盖实现逻辑数据的处理 */
	virtual void _onLogicDataHandler(FWLogicDataBase * dataBase, const char * threadID, void * customArg) = 0;

private:
	FWLogicDataBase * _popLogicData();

private:
	void _threadHandler(void * pPromiseStart);

private:
	volatile bool			_running;

	FWLockRecursive			_lock;

	void				*	_pThreadHandlerVector;
	
	HANDLE					_completionPortHandler;

	void				*	_logicDataDeque;

	FWLockRecursive			_deleteThreadNotifyLock;
};



FW_NS_END


#endif //!__FRAMEWORK_LOGICHANDLERBASE_H__