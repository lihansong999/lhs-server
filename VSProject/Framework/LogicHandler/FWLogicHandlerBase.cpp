#include "FWLogicHandlerBase.h"
#include "../Common/FWOutPut.h"

FW_NS_BEGIN

#define FW_IOCP_LOGIC_EXIT			0
#define FW_IOCP_LOGIC_NORMAL		1


FWLogicHandlerBase::FWLogicHandlerBase()
	:_running(false)
	, _completionPortHandler(NULL)
{
	_pThreadHandlerVector = new std::vector<std::thread*>();
	_logicDataDeque = new std::deque<FWLogicDataBase*>();
}

FWLogicHandlerBase::~FWLogicHandlerBase()
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "�����еĹ����������");
	}

	delete ((std::deque<FWLogicDataBase*>*)_logicDataDeque);
	delete ((std::vector<std::thread*>*)_pThreadHandlerVector);
}

bool FWLogicHandlerBase::Start(unsigned int threadCountHandler)
{
	FWLockScopeController lsc(&_lock);

	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "�ظ� Start");
		return false;
	}

	if (threadCountHandler == 0)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "threadCountHandler == 0");
		return false;
	}

	_completionPortHandler = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, (DWORD)threadCountHandler);
	if (_completionPortHandler == NULL)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "������ɶ˿�ʧ�ܣ������룺", (int)GetLastError());
		return false;
	}
	
	_running = true;

	for (unsigned int i = 0; i < threadCountHandler; i++)
	{
		std::promise<int> promiseHandlerStart;
		std::future<int> futureHandlerStart = promiseHandlerStart.get_future();
		((std::vector<std::thread*>*)_pThreadHandlerVector)->push_back(new std::thread(std::bind(&FWLogicHandlerBase::_threadHandler, this, &promiseHandlerStart)));
		futureHandlerStart.get();
		FW_PRINT("[%s] %s%u%s", this->_getTitle(), "_threadHandler �߳������� ", i + 1, " ����");
	}

	return true;
}

void FWLogicHandlerBase::Stop()
{
	_lock.Lock();

	if (!_running)
	{
		_lock.UnLock();
		return;
	}
	_running = false;

	_lock.UnLock();
	
	for (size_t i = 0; i < ((std::vector<std::thread*>*)_pThreadHandlerVector)->size(); i++)
	{
		PostQueuedCompletionStatus(_completionPortHandler, FW_IOCP_LOGIC_EXIT, NULL, NULL);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(((std::vector<std::thread*>*)_pThreadHandlerVector)->size() * 2000));	//��΢�ȴ������������԰�ȫ��ֻ�Ǿ����������Źرա�
	CloseHandle(_completionPortHandler);
	_completionPortHandler = NULL;
	for (std::vector<std::thread*>::iterator it = ((std::vector<std::thread*>*)_pThreadHandlerVector)->begin(); it != ((std::vector<std::thread*>*)_pThreadHandlerVector)->end(); it++)
	{
		(*it)->join();
		delete (*it);
	}
	((std::vector<std::thread*>*)_pThreadHandlerVector)->clear();
	FW_PRINT("[%s] %s", this->_getTitle(), "_threadHandler �߳����˳���");

	_lock.Lock();

	for (std::deque<FWLogicDataBase*>::iterator it = ((std::deque<FWLogicDataBase*>*)_logicDataDeque)->begin(); it != ((std::deque<FWLogicDataBase*>*)_logicDataDeque)->end(); it++)
	{
		delete (*it);
	}
	((std::deque<FWLogicDataBase*>*)_logicDataDeque)->clear();

	_lock.UnLock();
}

void FWLogicHandlerBase::PushLogicData(FWLogicDataBase * dataBase)
{
	FWLockScopeController lsc(&_lock);

	if (!dataBase)
	{
		return;
	}

	if (!_running)
	{
		delete dataBase;
		return;
	}
	
	((std::deque<FWLogicDataBase*>*)_logicDataDeque)->push_back(dataBase);

	PostQueuedCompletionStatus(_completionPortHandler, FW_IOCP_LOGIC_NORMAL, NULL, NULL);
}

const char * FWLogicHandlerBase::_getTitle() const
{
	return typeid(*this).name();
}

void * FWLogicHandlerBase::_onCreateThread(const char * threadID)
{
	return nullptr;
}

void FWLogicHandlerBase::_onDeleteThread(const char * threadID, void * customArg)
{

}

void FWLogicHandlerBase::_deleteLogicData(FWLogicDataBase * dataBase)
{
	delete dataBase;
}

FWLogicDataBase * FWLogicHandlerBase::_popLogicData()
{
	FWLockScopeController lsc(&_lock);

	if (((std::deque<FWLogicDataBase*>*)_logicDataDeque)->size() == 0)
	{
		return nullptr;
	}
	FWLogicDataBase * dataBase = ((std::deque<FWLogicDataBase*>*)_logicDataDeque)->front();
	((std::deque<FWLogicDataBase*>*)_logicDataDeque)->pop_front();
	return dataBase;
}

void FWLogicHandlerBase::_threadHandler(void * pPromiseStart)
{
	srand((unsigned int)time(NULL));

	std::thread::id threadID = std::this_thread::get_id();
	std::stringstream threadIDStream;
	threadIDStream << threadID;
	std::string threadIDString = threadIDStream.str();

	void * customArg = this->_onCreateThread(threadIDString.c_str());

	((std::promise<int>*)pPromiseStart)->set_value(0);

	while (_running)
	{
		ULONG_PTR pCompletionKey = 0;
		OVERLAPPED * pOverlapped = NULL;
		DWORD numberOfBytesTransferred = 0;
		BOOL r = GetQueuedCompletionStatus(_completionPortHandler, &numberOfBytesTransferred, &pCompletionKey, &pOverlapped, INFINITE);
		if (r == FALSE || numberOfBytesTransferred == FW_IOCP_LOGIC_EXIT)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
			continue;
		}

		FWLogicDataBase * dataBase = nullptr;
		while (dataBase = this->_popLogicData())
		{
			this->_onLogicDataHandler(dataBase, threadIDString.c_str(), customArg);
			this->_deleteLogicData(dataBase);
		}
	}

	_deleteThreadNotifyLock.Lock();
	this->_onDeleteThread(threadIDString.c_str(), customArg);
	_deleteThreadNotifyLock.UnLock();
}



FW_NS_END