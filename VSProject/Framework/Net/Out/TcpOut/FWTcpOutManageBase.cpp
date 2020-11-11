#include "FWTcpOutManageBase.h"
#include "FWTcpOutSocket.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"

FW_NS_BEGIN

#define FREE_FOREVER_SOCKET_COUNT	2


FWTcpOutManageBase::FWTcpOutManageBase()
	:_running(false)
	, _completionPortRS(NULL)
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	_pThreadSocketRSVector = new std::vector<std::thread*>();
	_pThreadConnectIDSet = new std::set<FW_ID>();
	_threadConnectIDContainerMutex = new std::recursive_mutex();
	_socketVector = new std::vector<FWTcpOutSocket*>();
	_socketFreeIndexDeque = new std::deque<unsigned int>();
	_socketFreeIndexSet = new std::set<unsigned int>();
}

FWTcpOutManageBase::~FWTcpOutManageBase()
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "运行中的管理对象被析构");
	}
	
	delete ((std::vector<std::thread*>*)_pThreadSocketRSVector);
	delete ((std::set<FW_ID>*)_pThreadConnectIDSet);
	delete ((std::recursive_mutex*)_threadConnectIDContainerMutex);
	delete ((std::vector<FWTcpOutSocket*>*)_socketVector);
	delete ((std::deque<unsigned int>*)_socketFreeIndexDeque);
	delete ((std::set<unsigned int>*)_socketFreeIndexSet);

	WSACleanup();
}

bool FWTcpOutManageBase::Start(unsigned int maxConnectedCount, unsigned int threadCountRS /*= 0*/)
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "重复 Start");
		return false;
	}

	if (threadCountRS == 0)
	{
		threadCountRS = 1;
	}
	
	_completionPortRS = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, (DWORD)threadCountRS);
	if (_completionPortRS == NULL)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "创建完成端口失败，错误码：", (int)GetLastError());
		return false;
	}

	for (unsigned int index = 0; index < maxConnectedCount + FREE_FOREVER_SOCKET_COUNT; index++)
	{
		((std::vector<FWTcpOutSocket*>*)_socketVector)->push_back(new FWTcpOutSocket(index, this));
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
		((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	}

	_running = true;
	
	for (unsigned int i = 0; i < threadCountRS; i++)
	{
		std::promise<int> promiseSocketRSStart;
		std::future<int> futureSocketRSStart = promiseSocketRSStart.get_future();
		((std::vector<std::thread*>*)_pThreadSocketRSVector)->push_back(new std::thread(std::bind(&FWTcpOutManageBase::_threadSocketRS, this, &promiseSocketRSStart)));
		futureSocketRSStart.get();
		FW_PRINT("[%s] %s%u%s", this->_getTitle(), "_threadSocketRS 线程已启动", i + 1, "个。");
	}

	return true;
}

void FWTcpOutManageBase::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;
	
	FW_PRINT("[%s] %s", this->_getTitle(), "开始停止所有向外连接请求，此过程可能需要十几秒钟……");
	while (true)
	{
		if (!((std::recursive_mutex*)_threadConnectIDContainerMutex)->try_lock())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			continue;
		}
		size_t s = ((std::set<FW_ID>*)_pThreadConnectIDSet)->size();
		((std::recursive_mutex*)_threadConnectIDContainerMutex)->unlock();
		if (s > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			continue;
		}
		break;
	}
	FW_PRINT("[%s] %s", this->_getTitle(), "所有向外连接请求已停止， _threadConnect 线程已退出。");

	for (size_t i = 0; i < ((std::vector<std::thread*>*)_pThreadSocketRSVector)->size(); i++)
	{
		PostQueuedCompletionStatus(_completionPortRS, 0, NULL, NULL);
	}
	CloseHandle(_completionPortRS);
	_completionPortRS = NULL;
	for (std::vector<std::thread*>::iterator it = ((std::vector<std::thread*>*)_pThreadSocketRSVector)->begin(); it != ((std::vector<std::thread*>*)_pThreadSocketRSVector)->end(); it++)
	{
		(*it)->join();
		delete (*it);
	}
	((std::vector<std::thread*>*)_pThreadSocketRSVector)->clear();
	FW_PRINT("[%s] %s", this->_getTitle(), "_threadSocketRS 线程已退出。");

	//清理FWTcpOutSocket池
	{
		FW_PRINT("[%s] %s", this->_getTitle(), "开始清理FWTcpOutSocket内存池，此过程可能需要十几秒钟……");
		if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
		{
			FW_LOG_ERROR("[%s] %s", this->_getTitle(), "预料之外的BUG，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
		}
		for (unsigned int index = 0; index < ((std::vector<FWTcpOutSocket*>*)_socketVector)->size(); index++)
		{
			if (((std::set<unsigned int>*)_socketFreeIndexSet)->find(index) == ((std::set<unsigned int>*)_socketFreeIndexSet)->end())
			{
				FWTcpOutSocket * pTcpOutSocket = (*((std::vector<FWTcpOutSocket*>*)_socketVector))[index];
				FW_NET_ACTIVITY_ID activityID = pTcpOutSocket->GetActivityID();
				FW_ID custom = pTcpOutSocket->GetCustom();
				pTcpOutSocket->CloseSocket(activityID);
				FWNetMatch netMatch(index, activityID);
				this->_onTcpOutClose(netMatch, custom);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //稍微等待从其他线程调用到本类中对FWTcpOutSocket进行操作并已经通过_running判断的执行代码运行完毕（并非绝对安全，如需绝对安区只能考虑操作中加锁）
		for (unsigned int index = 0; index < ((std::vector<FWTcpOutSocket*>*)_socketVector)->size(); index++)
		{
			delete ((*((std::vector<FWTcpOutSocket*>*)_socketVector))[index]);
		}
		((std::vector<FWTcpOutSocket*>*)_socketVector)->clear();
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->clear();
		((std::set<unsigned int>*)_socketFreeIndexSet)->clear();
		FW_PRINT("[%s] %s", this->_getTitle(), "FWTcpOutSocket内存池清理完成。");
	}
}

void FWTcpOutManageBase::Connect(const char * addr, unsigned short port, FW_ID custom /*= 0LL*/)
{
	((std::recursive_mutex*)_threadConnectIDContainerMutex)->lock();
	if (!_running)
	{
		((std::recursive_mutex*)_threadConnectIDContainerMutex)->unlock();
		return;
	}
	volatile static FW_ID ID = 0;
	FW_ID id = InterlockedIncrement64(&ID);
	std::pair<std::set<FW_ID>::iterator, bool> r = ((std::set<FW_ID>*)_pThreadConnectIDSet)->insert(id);
	if (!r.second)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "严重错误，_pThreadConnectIDSet->insert 失败");
		((std::recursive_mutex*)_threadConnectIDContainerMutex)->unlock();
		return;
	}
	((std::recursive_mutex*)_threadConnectIDContainerMutex)->unlock();
	std::promise<int> promiseConnectStart;
	std::future<int> futureConnectStart = promiseConnectStart.get_future();
	std::thread t = std::thread(std::bind(&FWTcpOutManageBase::_threadConnect, this, &promiseConnectStart, id, addr, port, custom));
	t.detach();
	futureConnectStart.get();
}

bool FWTcpOutManageBase::SendDataTcpOutSocket(const FWNetMatch & netMatch, const char * pData, int size)
{
	if (!_running)
	{
		return false;
	}
	if (!pData || size <= 0)
	{
		return false;
	}

	FWTcpOutSocket * pTcpOutSocket = this->_getSocket(netMatch.Index);
	if (!pTcpOutSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pTcpOutSocket->SendData(netMatch.ActivityID, pData, size);
}

void FWTcpOutManageBase::SendDataTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size)
{
	if (!_running)
	{
		return;
	}
	if (!pData || size <= 0)
	{
		return;
	}
	if (!netMatches || count == 0)
	{
		return;
	}

	for (unsigned int i = 0; i < count; i++)
	{
		FWTcpOutSocket * pTcpOutSocket = this->_getSocket(netMatches[i].Index);
		if (!pTcpOutSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pTcpOutSocket->SendData(netMatches[i].ActivityID, pData, size);
	}
}

void FWTcpOutManageBase::CloseTcpOutSocket(const FWNetMatch & netMatch)
{
	if (!_running)
	{
		return;
	}

	FWTcpOutSocket * pTcpOutSocket = this->_getSocket(netMatch.Index);
	if (!pTcpOutSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return;
	}
	pTcpOutSocket->CloseSocket(netMatch.ActivityID);
}

void FWTcpOutManageBase::CloseTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count)
{
	if (!_running)
	{
		return;
	}
	if (!netMatches || count == 0)
	{
		return;
	}

	for (unsigned int i = 0; i < count; i++)
	{
		FWTcpOutSocket * pTcpOutSocket = this->_getSocket(netMatches[i].Index);
		if (!pTcpOutSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pTcpOutSocket->CloseSocket(netMatches[i].ActivityID);
	}
}

const char * FWTcpOutManageBase::_getTitle() const
{
	return typeid(*this).name();
}

void FWTcpOutManageBase::_threadConnect(void * pPromiseStart, FW_ID id, const char * addr, unsigned short port, FW_ID custom)
{
	FWLifeCycleExecute<std::function<void(void)>, std::function<void(void)>> lifeCycleExecute(nullptr, [this, id](void)->void {
		((std::recursive_mutex*)_threadConnectIDContainerMutex)->lock();
		size_t r = ((std::set<FW_ID>*)_pThreadConnectIDSet)->erase(id);
		if (r != 1)
		{
			FW_LOG_ERROR("%s%d", "严重错误 _pThreadConnectIDSet->erase 返回值：", (int)r);
		}
		((std::recursive_mutex*)_threadConnectIDContainerMutex)->unlock();
	});

	std::string theIP = addr;
	char thePort[32] = { 0 };
	sprintf_s(thePort, sizeof(thePort), "%d", (int)port);

	((std::promise<int>*)pPromiseStart)->set_value(0);

	srand((unsigned int)time(NULL));

	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo * res;
	if (0 != getaddrinfo(addr, thePort, &hints, &res))
	{
		this->_onTcpOutConnectResult(false, FWNetMatch(), custom);
		return;
	}
	if (!_running)
	{
		this->_onTcpOutConnectResult(false, FWNetMatch(), custom);
		return ;
	}

	SOCKET socket = INVALID_SOCKET;
	for (struct addrinfo * tmp = res; tmp != NULL; tmp = tmp->ai_next)
	{
		if (tmp->ai_family != AF_INET && tmp->ai_family != AF_INET6)
		{
			continue;
		}
		if (tmp->ai_socktype != SOCK_STREAM)
		{
			continue;
		}
		if (tmp->ai_protocol != 0 && tmp->ai_protocol != IPPROTO_IP && tmp->ai_protocol != IPPROTO_TCP)
		{
			continue;
		}
		socket = WSASocket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol, NULL, 0, WSA_FLAG_OVERLAPPED);
		if (socket == INVALID_SOCKET)
		{
			continue;
		}
		u_long ul = 1;
		::ioctlsocket(socket, FIONBIO, &ul);
		if (::connect(socket, tmp->ai_addr, (int)tmp->ai_addrlen) == 0)
		{
			u_long ul = 0;
			::ioctlsocket(socket, FIONBIO, &ul);
			break;
		}
		int err = WSAGetLastError();
		if (err != WSAEWOULDBLOCK && err != WSAEINTR)
		{
			closesocket(socket);
			socket = INVALID_SOCKET;
			continue;
		}
		if (_selectConnect(socket))
		{
			u_long ul = 0;
			::ioctlsocket(socket, FIONBIO, &ul);
			break;
		}
		else
		{
			closesocket(socket);
			socket = INVALID_SOCKET;
			continue;
		}
	}

	freeaddrinfo(res);

	if (socket == INVALID_SOCKET)
	{
		this->_onTcpOutConnectResult(false, FWNetMatch(), custom);
		return;
	}
	
	bool overloaded = false;
	FWTcpOutSocket * pTcpOutSocket = this->_newSocket(&overloaded);
	if (!pTcpOutSocket)
	{
		::closesocket(socket);
		if (overloaded)
		{
			this->_onTcpOutOverloaded(custom);
		}
		else
		{
			this->_onTcpOutConnectResult(false, FWNetMatch(), custom);
		}
		return;
	}
	if (!pTcpOutSocket->_initSocket(socket, _completionPortRS, custom))
	{
		::closesocket(socket);
		this->_deleteSocket(pTcpOutSocket);
		this->_onTcpOutConnectResult(false, FWNetMatch(), custom);
		return;
	}
	FW_NET_ACTIVITY_ID activityID = pTcpOutSocket->GetActivityID();
	FWNetMatch netMatch(pTcpOutSocket->GetIndex(), activityID);

	pTcpOutSocket->_postRecvForConnectResultReadying();

	this->_onTcpOutConnectResult(true, netMatch, custom);

	pTcpOutSocket->_postRecvForConnectResult();
}

bool FWTcpOutManageBase::_selectConnect(SOCKET socket)
{
	fd_set rfd;
	fd_set wfd;
	fd_set efd;
	struct timeval timeout = { 0, 0 };
	timeout.tv_sec = 1L;
	timeout.tv_usec = 0L;
	for (int i = 0; i < 12; i++)
	{
		FD_ZERO(&rfd);
		FD_ZERO(&wfd);
		FD_ZERO(&efd);
		FD_SET(socket, &rfd);
		FD_SET(socket, &wfd);
		FD_SET(socket, &efd);
		int r = ::select(socket + 1, &rfd, &wfd, &efd, &timeout);
		if (!_running)
		{
			return false;
		}
		if (r == 0)
		{
			continue;
		}
		if (r == SOCKET_ERROR)
		{
			return false;
		}
		if (FD_ISSET(socket, &efd))
		{
			volatile int err = 0;
			socklen_t l = sizeof(err);
			bool e = ::getsockopt(socket, SOL_SOCKET, SO_ERROR, (char*)&err, &l) == 0 && err == 0;
			if (!e)
			{
				return false;
			}
		}
		if (FD_ISSET(socket, &rfd))
		{
			volatile int err = 0;
			socklen_t l = sizeof(err);
			bool e = ::getsockopt(socket, SOL_SOCKET, SO_ERROR, (char*)&err, &l) == 0 && err == 0;
			if (!e)
			{
				return false;
			}
		}
		if (FD_ISSET(socket, &wfd))
		{
			return true;
		}
		return false;
	}
	return false;
}

FWTcpOutSocket * FWTcpOutManageBase::_newSocket(bool * out_overloaded)
{
	FWLockScopeController lsc(&_freeIndexContainerLock);
	
	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() == FREE_FOREVER_SOCKET_COUNT)
	{
		*out_overloaded = true;
		return nullptr;
	}

	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "分配socket，出现严重错误，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
		return nullptr;
	}

	unsigned int index = ((std::deque<unsigned int>*)_socketFreeIndexDeque)->front();
	size_t removedCount = ((std::set<unsigned int>*)_socketFreeIndexSet)->erase(index);
	if (removedCount != 1)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "分配socket，出现严重错误，removedCount == ", (int)removedCount);
		return nullptr;
	}
	((std::deque<unsigned int>*)_socketFreeIndexDeque)->pop_front();
	
	return (*((std::vector<FWTcpOutSocket*>*)_socketVector))[index];
}

void FWTcpOutManageBase::_deleteSocket(FWTcpOutSocket * pTcpOutSocket)
{
	FWLockScopeController lsc(&_freeIndexContainerLock);

	unsigned int index = pTcpOutSocket->GetIndex();

	if (((std::vector<FWTcpOutSocket*>*)_socketVector)->size() <= index)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "_socketVector.size() >= index，index == ", index);
		return;
	}

	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "删除socket，出现严重错误，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
		return;
	}

	std::pair<std::set<unsigned int>::iterator, bool> r = ((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	if (!r.second)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "企图回收一个空闲的socket，index == ", index);
		return;
	}

	((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
}

FWTcpOutSocket * FWTcpOutManageBase::_getSocket(unsigned int index)
{
	if (((std::vector<FWTcpOutSocket*>*)_socketVector)->size() <= index)
	{
		return nullptr;
	}
	return (*((std::vector<FWTcpOutSocket*>*)_socketVector))[index];
}

void FWTcpOutManageBase::_threadSocketRS(void * pPromiseStart)
{
	((std::promise<int>*)pPromiseStart)->set_value(0);

	srand((unsigned int)time(NULL));

	while (_running)
	{
		FWTcpOutSocket * pTcpOutSocket = NULL;
		OVERLAPPED * pOverlapped = NULL;
		DWORD numberOfBytesTransferred = 0;
		BOOL r = GetQueuedCompletionStatus(_completionPortRS, &numberOfBytesTransferred, (PULONG_PTR)&pTcpOutSocket, &pOverlapped, INFINITE);
		if (r == FALSE)
		{
			DWORD e = GetLastError();
			if (e == ERROR_CONNECTION_ABORTED || e == ERROR_NETNAME_DELETED || e == ERROR_SEM_TIMEOUT)
			{
				numberOfBytesTransferred = 0;
			}
			else
			{
				if (e != ERROR_ABANDONED_WAIT_0 && (pTcpOutSocket || pOverlapped))
				{
					FW_LOG_WRNING("[%s] %s%d%s%d%s%p%s%p", this->_getTitle()
						, "GetQueuedCompletionStatus 出现未预见错误后 pTcpOutSocket 或 pOverlapped 依然正常取得，错误码："
						, (int)e, " NumberOfBytes：", (int)numberOfBytesTransferred
						, " pTcpOutSocket：", pTcpOutSocket
						, " pOverlapped：", pOverlapped
					);
				}
			}
		}
		if (!pTcpOutSocket || !pOverlapped)
		{
			continue;
		}

		FWOverLappedContext * pOverLappedContext = CONTAINING_RECORD(pOverlapped, FWOverLappedContext, Overlapped);
		
		switch (pOverLappedContext->Type)
		{
		case FW_OLCT_RECV:
			pTcpOutSocket->_onRecvCompleted(numberOfBytesTransferred);
			break;
		case FW_OLCT_SEND:
			pTcpOutSocket->_onSendCompleted(numberOfBytesTransferred);
			break;
		default:
			break;
		}
	}
}



FW_NS_END