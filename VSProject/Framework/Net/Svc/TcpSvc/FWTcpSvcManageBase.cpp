#include "FWTcpSvcManageBase.h"
#include "FWTcpSvcSocket.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"

FW_NS_BEGIN

#define FREE_FOREVER_SOCKET_COUNT	5


FWTcpSvcManageBase::FWTcpSvcManageBase()
	:_running(false)
	, _connectedCount(0)
	, _pThreadAccept(nullptr)
	, _completionPortRS(NULL)
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	_pThreadSocketRSVector = new std::vector<std::thread*>();
	_socketVector = new std::vector<FWTcpSvcSocket*>();
	_socketFreeIndexDeque = new std::deque<unsigned int>();
	_socketFreeIndexSet = new std::set<unsigned int>();
}

FWTcpSvcManageBase::~FWTcpSvcManageBase()
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "运行中的管理对象被析构");
	}
	
	delete ((std::vector<std::thread*>*)_pThreadSocketRSVector);
	delete ((std::vector<FWTcpSvcSocket*>*)_socketVector);
	delete ((std::deque<unsigned int>*)_socketFreeIndexDeque);
	delete ((std::set<unsigned int>*)_socketFreeIndexSet);

	WSACleanup();
}

bool FWTcpSvcManageBase::Start(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, FWTcpListenSocket::AddrFamily addrFamily /*= FWTcpListenSocket::AF_V4ONLY*/)
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "重复 Start");
		return false;
	}

	if (threadCountRS == 0)
	{
		unsigned int numberOfProcessors = FW_NumberOfProcessors();
		threadCountRS = (numberOfProcessors > 1) ? (numberOfProcessors - 1) : (1);
	}
	
	_completionPortRS = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, (DWORD)threadCountRS);
	if (_completionPortRS == NULL)
	{
		FW_LOG_ERROR("[%s] %s%d", this->_getTitle(), "创建完成端口失败，错误码：", (int)GetLastError());
		return false;
	}

	if (!_tcpListenSocket.InitSocket(port, addrFamily))
	{
		return false;
	}

	for (unsigned int index = 0; index < maxConnectedCount + FREE_FOREVER_SOCKET_COUNT; index++)
	{
		((std::vector<FWTcpSvcSocket*>*)_socketVector)->push_back(new FWTcpSvcSocket(index, this));
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
		((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	}

	_connectedCount = 0;

	_running = true;
	
	for (unsigned int i = 0; i < threadCountRS; i++)
	{
		std::promise<int> promiseSocketRSStart;
		std::future<int> futureSocketRSStart = promiseSocketRSStart.get_future();
		((std::vector<std::thread*>*)_pThreadSocketRSVector)->push_back(new std::thread(std::bind(&FWTcpSvcManageBase::_threadSocketRS, this, &promiseSocketRSStart)));
		futureSocketRSStart.get();
		FW_PRINT("[%s] %s%u%s", this->_getTitle(), "_threadSocketRS 线程已启动", i + 1, "个。");
	}
	
	std::promise<int> promiseAcceptStart;
	std::future<int> futureAcceptStart  = promiseAcceptStart.get_future();
	_pThreadAccept = new std::thread(std::bind(&FWTcpSvcManageBase::_threadAccept, this, &promiseAcceptStart));
	futureAcceptStart.get();
	FW_PRINT("[%s] %s", this->_getTitle(), "_threadAccept 线程已启动。");

	return true;
}

void FWTcpSvcManageBase::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;
	
	_tcpListenSocket.CloseSocket();
	((std::thread*)_pThreadAccept)->join();
	delete ((std::thread*)_pThreadAccept);
	_pThreadAccept = nullptr;
	FW_PRINT("[%s] %s", this->_getTitle(), "_threadAccept 线程已退出。");

	for (size_t i = 0; i < ((std::vector<std::thread*>*)_pThreadSocketRSVector)->size(); i++)
	{
		PostQueuedCompletionStatus(_completionPortRS, 0, NULL, NULL);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	CloseHandle(_completionPortRS);
	_completionPortRS = NULL;
	for (std::vector<std::thread*>::iterator it = ((std::vector<std::thread*>*)_pThreadSocketRSVector)->begin(); it != ((std::vector<std::thread*>*)_pThreadSocketRSVector)->end(); it++)
	{
		(*it)->join();
		delete (*it);
	}
	((std::vector<std::thread*>*)_pThreadSocketRSVector)->clear();
	FW_PRINT("[%s] %s", this->_getTitle(), "_threadSocketRS 线程已退出。");

	//清理FWTcpSvcSocket池
	{
		FW_PRINT("[%s] %s", this->_getTitle(), "开始清理FWTcpSvcSocket内存池，此过程可能需要十几秒钟……");
		if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
		{
			FW_LOG_ERROR("[%s] %s", this->_getTitle(), "预料之外的BUG，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
		}
		for (unsigned int index = 0; index < ((std::vector<FWTcpSvcSocket*>*)_socketVector)->size(); index++)
		{
			if (((std::set<unsigned int>*)_socketFreeIndexSet)->find(index) == ((std::set<unsigned int>*)_socketFreeIndexSet)->end())
			{
				FWTcpSvcSocket * pTcpSvcSocket = (*((std::vector<FWTcpSvcSocket*>*)_socketVector))[index];
				FW_NET_ACTIVITY_ID activityID = pTcpSvcSocket->GetActivityID();
				pTcpSvcSocket->CloseSocket(activityID);
				FWNetMatch netMatch(index, activityID);
				FWSvcSocketInfo svcSocketInfo;
				if (!pTcpSvcSocket->GetSocketInfo(activityID, &svcSocketInfo))
				{
					FW_LOG_ERROR("[%s]%s", this->_getTitle(), "预料之外的BUG，pTcpSvcSocket->GetSocketInfo(activityID, &svcSocketInfo) == false");
				}
				this->_onTcpSvcClose(netMatch, svcSocketInfo);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //稍微等待从其他线程调用到本类中对FWTcpSvcSocket进行操作并已经通过_running判断的执行代码运行完毕（并非绝对安全，如需绝对安区只能考虑操作中加锁）
		for (unsigned int index = 0; index < ((std::vector<FWTcpSvcSocket*>*)_socketVector)->size(); index++)
		{
			delete ((*((std::vector<FWTcpSvcSocket*>*)_socketVector))[index]);
		}
		((std::vector<FWTcpSvcSocket*>*)_socketVector)->clear();
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->clear();
		((std::set<unsigned int>*)_socketFreeIndexSet)->clear();
		FW_PRINT("[%s] %s", this->_getTitle(), "FWTcpSvcSocket内存池清理完成。");
	}
}

bool FWTcpSvcManageBase::SendDataTcpSvcSocket(const FWNetMatch & netMatch, const char * pData, int size)
{
	if (!_running)
	{
		return false;
	}
	if (!pData || size <= 0)
	{
		return false;
	}

	FWTcpSvcSocket * pTcpSvcSocket = this->_getSocket(netMatch.Index);
	if (!pTcpSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pTcpSvcSocket->SendData(netMatch.ActivityID, pData, size);
}

void FWTcpSvcManageBase::SendDataTcpSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size)
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
		FWTcpSvcSocket * pTcpSvcSocket = this->_getSocket(netMatches[i].Index);
		if (!pTcpSvcSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pTcpSvcSocket->SendData(netMatches[i].ActivityID, pData, size);
	}
}

void FWTcpSvcManageBase::CloseTcpSvcSocket(const FWNetMatch & netMatch)
{
	if (!_running)
	{
		return;
	}

	FWTcpSvcSocket * pTcpSvcSocket = this->_getSocket(netMatch.Index);
	if (!pTcpSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return;
	}
	pTcpSvcSocket->CloseSocket(netMatch.ActivityID);
}

void FWTcpSvcManageBase::CloseTcpSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count)
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
		FWTcpSvcSocket * pTcpSvcSocket = this->_getSocket(netMatches[i].Index);
		if (!pTcpSvcSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pTcpSvcSocket->CloseSocket(netMatches[i].ActivityID);
	}
}

bool FWTcpSvcManageBase::GetTcpSvcSocketInfo(const FWNetMatch & netMatch, FWSvcSocketInfo * out_svcSocketInfo)
{
	if (!_running)
	{
		return false;
	}

	FWTcpSvcSocket * pTcpSvcSocket = this->_getSocket(netMatch.Index);
	if (!pTcpSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pTcpSvcSocket->GetSocketInfo(netMatch.ActivityID, out_svcSocketInfo);
}

int FWTcpSvcManageBase::GetConnectedCount()
{
	if (!_running)
	{
		return 0;
	}
	return (int)_connectedCount;
}

const char * FWTcpSvcManageBase::_getTitle() const
{
	return typeid(*this).name();
}

bool FWTcpSvcManageBase::_onTcpSvcReject(const char * ip46, unsigned short port)
{
	return false;
}

void FWTcpSvcManageBase::_onTcpSvcOverloaded()
{

}

FWTcpSvcSocket * FWTcpSvcManageBase::_newSocket(bool * out_overloaded)
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

	InterlockedIncrement(&_connectedCount);

	return (*((std::vector<FWTcpSvcSocket*>*)_socketVector))[index];
}

void FWTcpSvcManageBase::_deleteSocket(FWTcpSvcSocket * pTcpSvcSocket)
{
	FWLockScopeController lsc(&_freeIndexContainerLock);

	unsigned int index = pTcpSvcSocket->GetIndex();

	if (((std::vector<FWTcpSvcSocket*>*)_socketVector)->size() <= index)
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

	InterlockedDecrement(&_connectedCount);

	((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
}

FWTcpSvcSocket * FWTcpSvcManageBase::_getSocket(unsigned int index)
{
	if (((std::vector<FWTcpSvcSocket*>*)_socketVector)->size() <= index)
	{
		return nullptr;
	}
	return (*((std::vector<FWTcpSvcSocket*>*)_socketVector))[index];
}

void FWTcpSvcManageBase::_threadAccept(void * pPromiseStart)
{
	((std::promise<int>*)pPromiseStart)->set_value(0);

	srand((unsigned int)time(NULL));

	while (_running)
	{
		struct sockaddr_storage addr;
		addr.ss_family = 0;
		SOCKET s = _tcpListenSocket.Accept(&addr);
		if (s == INVALID_SOCKET)
		{
			continue;
		}
		char ip46[64] = { 0 };
		unsigned short port = 0;
		if (addr.ss_family == AF_INET)
		{
			inet_ntop(addr.ss_family, &((struct sockaddr_in*)&addr)->sin_addr, ip46, sizeof(ip46));
			port = ::ntohs(((struct sockaddr_in*)&addr)->sin_port);
		}
		else if (addr.ss_family == AF_INET6)
		{
			inet_ntop(addr.ss_family, &((struct sockaddr_in6*)&addr)->sin6_addr, ip46, sizeof(ip46));
			port = ::ntohs(((struct sockaddr_in6*)&addr)->sin6_port);
		}
		if (this->_onTcpSvcReject(ip46, port))
		{
			::closesocket(s);
			continue;
		}
		bool overloaded = false;
		FWTcpSvcSocket * pTcpSvcSocket = this->_newSocket(&overloaded);
		if (!pTcpSvcSocket)
		{
			::closesocket(s);
			if (overloaded)
			{
				this->_onTcpSvcOverloaded();
			}
			continue;
		}
		if (!pTcpSvcSocket->_initSocket(s, _completionPortRS, ip46, port))
		{
			::closesocket(s);
			this->_deleteSocket(pTcpSvcSocket);
			continue;
		}
		FWNetMatch netMatch(pTcpSvcSocket->GetIndex(), pTcpSvcSocket->GetActivityID());
		FWSvcSocketInfo svcSocketInfo;
		pTcpSvcSocket->GetSocketInfo(netMatch.ActivityID, &svcSocketInfo);

		pTcpSvcSocket->_postRecvForAcceptReadying();

		this->_onTcpSvcAccepted(netMatch, svcSocketInfo);

		pTcpSvcSocket->_postRecvForAccept();
	}
}

void FWTcpSvcManageBase::_threadSocketRS(void * pPromiseStart)
{
	((std::promise<int>*)pPromiseStart)->set_value(0);

	srand((unsigned int)time(NULL));

	while (_running)
	{
		FWTcpSvcSocket * pTcpSvcSocket = NULL;
		OVERLAPPED * pOverlapped = NULL;
		DWORD numberOfBytesTransferred = 0;
		BOOL r = GetQueuedCompletionStatus(_completionPortRS, &numberOfBytesTransferred, (PULONG_PTR)&pTcpSvcSocket, &pOverlapped, INFINITE);
		if (r == FALSE)
		{
			DWORD e = GetLastError();
			if (e == ERROR_CONNECTION_ABORTED || e == ERROR_NETNAME_DELETED || e == ERROR_SEM_TIMEOUT)
			{
				numberOfBytesTransferred = 0;
			}
			else
			{
				if (e != ERROR_ABANDONED_WAIT_0 && (pTcpSvcSocket || pOverlapped))
				{
					FW_LOG_WRNING("[%s] %s%d%s%d%s%p%s%p", this->_getTitle()
						, "GetQueuedCompletionStatus 出现未预见错误后 pTcpSvcSocket 或 pOverlapped 依然正常取得，错误码：", (int)e
						, " NumberOfBytes：", (int)numberOfBytesTransferred
						, " pTcpSvcSocket：", pTcpSvcSocket
						, " pOverlapped：", pOverlapped
					);
				}
			}
		}
		if (!pTcpSvcSocket || !pOverlapped)
		{
			continue;
		}

		FWOverLappedContext * pOverLappedContext = CONTAINING_RECORD(pOverlapped, FWOverLappedContext, Overlapped);
		
		switch (pOverLappedContext->Type)
		{
		case FW_OLCT_RECV:
			pTcpSvcSocket->_onRecvCompleted(numberOfBytesTransferred);
			break;
		case FW_OLCT_SEND:
			pTcpSvcSocket->_onSendCompleted(numberOfBytesTransferred);
			break;
		default:
			break;
		}
	}
}



FW_NS_END