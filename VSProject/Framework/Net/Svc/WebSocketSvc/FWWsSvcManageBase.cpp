#include "FWWsSvcManageBase.h"
#include "FWWsSvcSocket.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"
#include "../../../Common/FWString.h"

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#endif // !HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <libwebsockets.h>

FW_NS_BEGIN

#define FREE_FOREVER_SOCKET_COUNT	5


static bool _GetPeerAddresses(SOCKET s, char * ip46Buf, size_t bufSize, unsigned short * port)
{
	struct sockaddr_storage addr;
	addr.ss_family = 0;
	int len = sizeof(struct sockaddr_storage);
	if (getpeername(s, (sockaddr*)&addr, &len) == SOCKET_ERROR)
	{
		return false;
	}
	if (addr.ss_family == AF_INET)
	{
		inet_ntop(addr.ss_family, &((struct sockaddr_in*)&addr)->sin_addr, ip46Buf, bufSize);
		*port = ::ntohs(((struct sockaddr_in*)&addr)->sin_port);
		return true;
	}
	else if (addr.ss_family == AF_INET6)
	{
		inet_ntop(addr.ss_family, &((struct sockaddr_in6*)&addr)->sin6_addr, ip46Buf, bufSize);
		*port = ::ntohs(((struct sockaddr_in6*)&addr)->sin6_port);
		return true;
	}
	else
	{
		return false;
	}
}

struct WSSessionData
{
	unsigned int Index;
	FW_NET_ACTIVITY_ID ActivityID;
};

static int _WS_Callback_Function2(FWWsSvcManageBase * self, void * argWsi, int argReason, void * user, void * in, size_t len)
{
	struct lws * wsi = (struct lws*)argWsi;
	enum lws_callback_reasons reason = (enum lws_callback_reasons)argReason;
	WSSessionData * sessionData = (WSSessionData*)user;

	switch (reason)
	{
	case LWS_CALLBACK_ESTABLISHED:
	{
		if (!sessionData || sessionData->ActivityID != 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_ESTABLISHED: (!sessionData || sessionData->ActivityID != 0LL)");
			return -1;
		}
		char ip46[64] = { 0 };
		unsigned short port = 0;
		if (!_GetPeerAddresses(lws_get_socket_fd(wsi), ip46, sizeof(ip46), &port))
			return -1;
		if (self->_onWsSvcReject(ip46, port))
			return -1;
		FWWsSvcSocket * pWsSvcSocket = self->_newSocket();
		if (!pWsSvcSocket)
			return -1;
		if (!pWsSvcSocket->_initSocket(wsi, ip46, port))
		{
			self->_deleteSocket(pWsSvcSocket);
			return -1;
		}
		FWNetMatch netMatch(pWsSvcSocket->GetIndex(), pWsSvcSocket->GetActivityID());
		FWSvcSocketInfo svcSocketInfo;
		pWsSvcSocket->GetSocketInfo(netMatch.ActivityID, &svcSocketInfo);
		sessionData->Index = netMatch.Index;
		sessionData->ActivityID = netMatch.ActivityID;
		self->_onWsSvcEstablishe(netMatch, svcSocketInfo);
		return 0;
	}
		break;
	case LWS_CALLBACK_RECEIVE:
	{
		if (!sessionData || sessionData->ActivityID == 0LL)
			return -1;
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		FWWsSvcSocket * pWsSvcSocket = self->_getSocket(netMatch.Index);
		if (!pWsSvcSocket)
			return -1;
		if (!pWsSvcSocket->_onReceiveWSI(netMatch.ActivityID, lws_is_first_fragment(wsi) != 0, lws_is_final_fragment(wsi) != 0, lws_frame_is_binary(wsi) != 0, (char*)in, len))
			return -1;
		return 0;
	}
		break;
	case LWS_CALLBACK_SERVER_WRITEABLE:
	{
		if (!sessionData || sessionData->ActivityID == 0LL)
			return -1;
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		FWWsSvcSocket * pWsSvcSocket = self->_getSocket(netMatch.Index);
		if (!pWsSvcSocket)
			return -1;
		if (!pWsSvcSocket->_onWriteableWSI(netMatch.ActivityID))
			return -1;
		return 0;
	}
		break;
	case LWS_CALLBACK_CLOSED:
	{
		if (!sessionData || sessionData->ActivityID == 0LL)
			return 0;
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		sessionData->ActivityID = 0LL;
		FWWsSvcSocket * pWsSvcSocket = self->_getSocket(netMatch.Index);
		if (pWsSvcSocket)
			pWsSvcSocket->_onCloseSocketWSI(netMatch.ActivityID);
		return 0;
	}
		break;
	case LWS_CALLBACK_WSI_DESTROY:
	{
		if (!sessionData || sessionData->ActivityID == 0LL)
			return 0;
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		sessionData->ActivityID = 0LL;
		FWWsSvcSocket * pWsSvcSocket = self->_getSocket(netMatch.Index);
		if (pWsSvcSocket)
			pWsSvcSocket->_onCloseSocketWSI(netMatch.ActivityID);
		return 0;
	}
		break;
	default:
		break;
	}
	return lws_callback_http_dummy(wsi, reason, user, in, len);
}

static int _WS_Callback_Function(struct lws * wsi, enum lws_callback_reasons reason, void * user, void * in, size_t len)
{
	FWWsSvcManageBase * self = nullptr;
	if (wsi)
		self = (FWWsSvcManageBase*)lws_context_user(lws_get_context(wsi));
	return _WS_Callback_Function2(self, wsi, reason, user, in, len);
}

static void _Log_Emit_Function(int level, const char * line)
{
	switch (level)
	{
	case LLL_ERR:
	{
		FW_LOG_ERROR("%s", line);
	}
		break;
	case LLL_WARN:
	{
		FW_LOG_WRNING("%s", line);
	}
		break;
	default:
	{
		FW_PRINT("%s", line);
	}
		break;
	}
}

static struct lws_protocols _Protocols[] = {
	{ "", _WS_Callback_Function, sizeof(WSSessionData), FW_WSSVC_RECV_BUF_SIZE, 0, NULL, FW_WSSVC_SEND_BUF_SIZE },
	{ NULL, NULL, 0, 0, 0, NULL, 0 }
};

static const struct lws_extension _Extensions[] = {
	{
		"permessage-deflate",
		lws_extension_callback_pm_deflate,
		"permessage-deflate"
	},
	{ NULL, NULL, NULL /* terminator */ }
};

struct ThreadSvcArgs
{
	FWWsSvcManageBase * Self;
	unsigned short Port;
	unsigned int MaxConnectedCount;
	unsigned int ThreadCountRS;
	FWWsSvcManageBase::WSAddrFamily AddrFamily;
	bool IsTLS;
	FWString CertFilePath;
	FWString KeyFilePath;
	FWString KeyFilePassword;
	std::promise<int> * PromisePollStart;
};

struct ThreadSubSvcArgs
{
	ThreadSvcArgs * TsArgs;
	struct lws_context * Context;
	int ThreadIndex;
};

static void * PTW32_CDECL _Thread_Sub_Svc(void * args)
{
	ThreadSubSvcArgs * tssArgs = (ThreadSubSvcArgs*)args;
	FWLifeCycleExecute<std::function<void(void)>, std::function<void(void)>> lifeCycleExecute(nullptr, [tssArgs](void)->void {
		delete tssArgs;
	});
	while (lws_service_tsi(tssArgs->Context, 1000, tssArgs->ThreadIndex) >= 0
		&& tssArgs->TsArgs->Self->_running)
		;
	return NULL;
}

static void * PTW32_CDECL _Thread_Svc(void * args)
{
	ThreadSvcArgs * tsArgs = (ThreadSvcArgs*)args;
	FWLifeCycleExecute<std::function<void(void)>, std::function<void(void)>> lifeCycleExecute(nullptr, [tsArgs](void)->void {
		delete tsArgs;
	});
	lws_set_log_level(LLL_ERR | LLL_WARN | LLL_NOTICE, &_Log_Emit_Function);
	struct lws_context_creation_info info;
	memset(&info, 0, sizeof(struct lws_context_creation_info));
	info.user = tsArgs->Self;
	info.port = tsArgs->Port;
	info.iface = NULL; // 在所有网络接口上监听
	info.protocols = _Protocols;
	info.gid = -1;
	info.uid = -1;
	info.ka_time = 60;
	info.ka_interval = 2;
	info.ka_probes = 5;
	info.max_http_header_data = 3072;
	info.max_http_header_pool = (tsArgs->MaxConnectedCount > 64) ? (64) : (tsArgs->MaxConnectedCount);
	info.count_threads = tsArgs->ThreadCountRS;
	info.fd_limit_per_thread = tsArgs->MaxConnectedCount / tsArgs->ThreadCountRS;
	info.timeout_secs = 15;
	info.server_string = "FWWebSocketSvc";
	info.pt_serv_buf_size = FW_WSSVC_SERV_SEND_BUF_SIZE;
	info.ws_ping_pong_interval = 45;
	info.timeout_secs_ah_idle = 10;
	info.extensions = _Extensions;
	if (tsArgs->IsTLS)
	{
		info.ssl_cert_filepath = tsArgs->CertFilePath.C_Str();
		info.ssl_private_key_filepath = tsArgs->KeyFilePath.C_Str();
		if (tsArgs->KeyFilePassword.Compare("") != 0)
		{
			info.ssl_private_key_password = tsArgs->KeyFilePassword.C_Str();
		}
		info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
		info.options |= LWS_SERVER_OPTION_PEER_CERT_NOT_REQUIRED;
	}
	/*
	如果使用libuv将无法跨线程调用lws_callback_on_writable
	所以在编译websockets.dll的时候就没有把libuv引入
	*/
	//info.options |= LWS_SERVER_OPTION_LIBUV | LWS_SERVER_OPTION_UV_NO_SIGSEGV_SIGFPE_SPIN;
	switch (tsArgs->AddrFamily)
	{
	case FWWsSvcManageBase::WSAF_V4ONLY:
	{
		info.options |= LWS_SERVER_OPTION_DISABLE_IPV6;
	}
		break;
	case FWWsSvcManageBase::WSAF_V6ONLY:
	{
		info.options |= LWS_SERVER_OPTION_IPV6_V6ONLY_MODIFY;
		info.options |= LWS_SERVER_OPTION_IPV6_V6ONLY_VALUE;
	}
		break;
	case FWWsSvcManageBase::WSAF_V46MAPPED:
	{
		info.options |= LWS_SERVER_OPTION_IPV6_V6ONLY_MODIFY;
	}
		break;
	default:
	{
		assert(false);
	}
		break;
	}
	struct lws_context * context = lws_create_context(&info);
	if (!context) {
		FW_LOG_ERROR("%s", "lws_create_context failed");
		tsArgs->PromisePollStart->set_value(0);
		return NULL;
	}
	std::vector<pthread_t> threads;
	threads.resize(lws_get_count_threads(context));
	for (int i = 0; i < lws_get_count_threads(context); i++)
	{
		ThreadSubSvcArgs * tssArgs = new ThreadSubSvcArgs();
		tssArgs->TsArgs = tsArgs;
		tssArgs->Context = context;
		tssArgs->ThreadIndex = i;
		pthread_attr_t tAttr;
		pthread_attr_init(&tAttr);
		pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_JOINABLE);
		pthread_create(&(threads[i]), &tAttr, &_Thread_Sub_Svc, tssArgs);
		pthread_attr_destroy(&tAttr);
	}
	FW_PRINT("[%s] %s", tsArgs->Self->_getTitle(), "WebSocket服务poll已启动。");
	tsArgs->PromisePollStart->set_value(0);
	while (tsArgs->Self->_running)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
	lws_cancel_service(context);
	for (std::vector<pthread_t>::iterator it = threads.begin(); it != threads.end(); it++)
	{
		pthread_join(*it, NULL);
	}
	lws_context_destroy(context);
	tsArgs->Self->_closeAllUsingSocket();
	return NULL;
}

static unsigned int _CalculateWebSocketSvcThreadCount(unsigned int maxConnectedCount, unsigned int threadCountRS)
{
	if (threadCountRS > 0)
		return threadCountRS;
	const unsigned int cpuCount = FW_NumberOfProcessors();
	threadCountRS = cpuCount * 2 / 3;
	if (threadCountRS == 0)
		threadCountRS = 1;
	if (threadCountRS > LWS_MAX_SMP)
		threadCountRS = LWS_MAX_SMP;
	return threadCountRS;
}

static unsigned int _CalculateWebSocketSvcMaxConnectedCount(unsigned int maxConnectedCount, unsigned int realThreadCountRS)
{
	return (maxConnectedCount / realThreadCountRS + 2) * realThreadCountRS;
}

FWWsSvcManageBase::FWWsSvcManageBase()
	:_running(false)
	, _rSinglePackageMax(INT_MAX)
	, _dataProtocol(WSDP_TEXT)
	, _connectedCount(0)
	, _pthread(NULL)
{
	_socketVector = new std::vector<FWWsSvcSocket*>();
	_socketFreeIndexDeque = new std::deque<unsigned int>();
	_socketFreeIndexSet = new std::set<unsigned int>();
}

FWWsSvcManageBase::~FWWsSvcManageBase()
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "运行中的管理对象被析构");
	}

	delete ((std::vector<FWWsSvcSocket*>*)_socketVector);
	delete ((std::deque<unsigned int>*)_socketFreeIndexDeque);
	delete ((std::set<unsigned int>*)_socketFreeIndexSet);
}

bool FWWsSvcManageBase::Start(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, int rSinglePackageMax /*= INT_MAX*/, WSDataProtocol dataProtocol /*= WSDP_TEXT*/, WSAddrFamily wsAddrFamily /*= WSAF_V4ONLY*/)
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "重复 Start");
		return false;
	}
	if (maxConnectedCount < threadCountRS)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "maxConnectedCount < threadCountRS");
		return false;
	}
	_running = true;

	_rSinglePackageMax = rSinglePackageMax;

	_dataProtocol = dataProtocol;

	_connectedCount = 0;

	threadCountRS = _CalculateWebSocketSvcThreadCount(maxConnectedCount, threadCountRS);
	maxConnectedCount = _CalculateWebSocketSvcMaxConnectedCount(maxConnectedCount, threadCountRS);

	for (unsigned int index = 0; index < maxConnectedCount + FREE_FOREVER_SOCKET_COUNT; index++)
	{
		((std::vector<FWWsSvcSocket*>*)_socketVector)->push_back(new FWWsSvcSocket(index, this));
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
		((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	}

	ThreadSvcArgs * tsArgs = new ThreadSvcArgs();
	tsArgs->Self = this;
	tsArgs->Port = port;
	tsArgs->MaxConnectedCount = maxConnectedCount;
	tsArgs->ThreadCountRS = threadCountRS;
	tsArgs->AddrFamily = wsAddrFamily;
	tsArgs->IsTLS = false;

	_pthread = new pthread_t();
	pthread_attr_t tAttr;
	pthread_attr_init(&tAttr);
	pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_JOINABLE);
	std::promise<int> promisePollStart;
	std::future<int> futurePollStart = promisePollStart.get_future();
	tsArgs->PromisePollStart = &promisePollStart;
	pthread_create((pthread_t*)_pthread, &tAttr, &_Thread_Svc, tsArgs);
	pthread_attr_destroy(&tAttr);
	futurePollStart.get();

	return true;
}

bool FWWsSvcManageBase::StartTLS(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, const char * certFilePath, const char * keyFilePath, const char * keyFilePassword /*= ""*/, int rSinglePackageMax /*= INT_MAX*/, WSDataProtocol dataProtocol /*= WSDP_TEXT*/, WSAddrFamily wsAddrFamily /*= WSAF_V4ONLY*/)
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "重复 Start");
		return false;
	}
	if (maxConnectedCount < threadCountRS)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "maxConnectedCount < threadCountRS");
		return false;
	}
	_running = true;

	_rSinglePackageMax = rSinglePackageMax;

	_dataProtocol = dataProtocol;

	_connectedCount = 0;

	threadCountRS = _CalculateWebSocketSvcThreadCount(maxConnectedCount, threadCountRS);
	maxConnectedCount = _CalculateWebSocketSvcMaxConnectedCount(maxConnectedCount, threadCountRS);

	for (unsigned int index = 0; index < maxConnectedCount + FREE_FOREVER_SOCKET_COUNT; index++)
	{
		((std::vector<FWWsSvcSocket*>*)_socketVector)->push_back(new FWWsSvcSocket(index, this));
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
		((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	}

	ThreadSvcArgs * tsArgs = new ThreadSvcArgs();
	tsArgs->Self = this;
	tsArgs->Port = port;
	tsArgs->MaxConnectedCount = maxConnectedCount;
	tsArgs->ThreadCountRS = threadCountRS;
	tsArgs->AddrFamily = wsAddrFamily;
	tsArgs->IsTLS = true;
	tsArgs->CertFilePath = certFilePath;
	tsArgs->KeyFilePath = keyFilePath;
	tsArgs->KeyFilePassword = keyFilePassword;

	_pthread = new pthread_t();
	pthread_attr_t tAttr;
	pthread_attr_init(&tAttr);
	pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_JOINABLE);
	pthread_create((pthread_t*)_pthread, &tAttr, &_Thread_Svc, tsArgs);
	pthread_attr_destroy(&tAttr);

	return true;
}

void FWWsSvcManageBase::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;

	pthread_join(*((pthread_t*)_pthread), NULL);
	delete ((pthread_t*)_pthread);

	//清理FWWsSvcSocket池
	{
		FW_PRINT("[%s] %s", this->_getTitle(), "开始清理FWWsSvcSocket内存池，此过程可能需要几秒钟……");
		std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //稍微等待从其他线程调用到本类中对FWWsSvcSocket进行操作并已经通过_running判断的执行代码运行完毕（并非绝对安全，如需绝对安区只能考虑操作中加锁）
		for (unsigned int index = 0; index < ((std::vector<FWWsSvcSocket*>*)_socketVector)->size(); index++)
		{
			delete ((*((std::vector<FWWsSvcSocket*>*)_socketVector))[index]);
		}
		((std::vector<FWWsSvcSocket*>*)_socketVector)->clear();
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->clear();
		((std::set<unsigned int>*)_socketFreeIndexSet)->clear();
		FW_PRINT("[%s] %s", this->_getTitle(), "FWWsSvcSocket内存池清理完成。");
	}
}

bool FWWsSvcManageBase::SendDataWsSvcSocket(const FWNetMatch & netMatch, const char * pData, int size)
{
	if (!_running)
	{
		return false;
	}
	if (size < 0 || (size > 0 && !pData))
	{
		return false;
	}

	FWWsSvcSocket * pWsSvcSocket = this->_getSocket(netMatch.Index);
	if (!pWsSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pWsSvcSocket->SendData(netMatch.ActivityID, pData, size);
}

void FWWsSvcManageBase::SendDataWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size)
{
	if (!_running)
	{
		return;
	}
	if (size < 0 || (size > 0 && !pData))
	{
		return;
	}
	if (!netMatches || count == 0)
	{
		return;
	}

	for (unsigned int i = 0; i < count; i++)
	{
		FWWsSvcSocket * pWsSvcSocket = this->_getSocket(netMatches[i].Index);
		if (!pWsSvcSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pWsSvcSocket->SendData(netMatches[i].ActivityID, pData, size);
	}
}

void FWWsSvcManageBase::CloseWsSvcSocket(const FWNetMatch & netMatch)
{
	if (!_running)
	{
		return;
	}

	FWWsSvcSocket * pWsSvcSocket = this->_getSocket(netMatch.Index);
	if (!pWsSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return;
	}
	pWsSvcSocket->CloseSocket(netMatch.ActivityID);
}

void FWWsSvcManageBase::CloseWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count)
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
		FWWsSvcSocket * pWsSvcSocket = this->_getSocket(netMatches[i].Index);
		if (!pWsSvcSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pWsSvcSocket->CloseSocket(netMatches[i].ActivityID);
	}
}

bool FWWsSvcManageBase::GetWsSvcSocketInfo(const FWNetMatch & netMatch, FWSvcSocketInfo * out_svcSocketInfo)
{
	if (!_running)
	{
		return false;
	}

	FWWsSvcSocket * pWsSvcSocket = this->_getSocket(netMatch.Index);
	if (!pWsSvcSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pWsSvcSocket->GetSocketInfo(netMatch.ActivityID, out_svcSocketInfo);
}

int FWWsSvcManageBase::GetConnectedCount()
{
	if (!_running)
	{
		return 0;
	}
	return (int)_connectedCount;
}

const char * FWWsSvcManageBase::_getTitle() const
{
	return typeid(*this).name();
}

bool FWWsSvcManageBase::_onWsSvcReject(const char * ip46, unsigned short port)
{
	return false;
}

FWWsSvcSocket * FWWsSvcManageBase::_newSocket()
{
	FWPTW32LockScopeController lsc(&_freeIndexContainerLock);

	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() == FREE_FOREVER_SOCKET_COUNT)
	{
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

	return (*((std::vector<FWWsSvcSocket*>*)_socketVector))[index];
}

void FWWsSvcManageBase::_deleteSocket(FWWsSvcSocket * pWsSvcSocket)
{
	FWPTW32LockScopeController lsc(&_freeIndexContainerLock);

	unsigned int index = pWsSvcSocket->GetIndex();

	if (((std::vector<FWWsSvcSocket*>*)_socketVector)->size() <= index)
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

FWWsSvcSocket * FWWsSvcManageBase::_getSocket(unsigned int index)
{
	if (((std::vector<FWWsSvcSocket*>*)_socketVector)->size() <= index)
	{
		return nullptr;
	}
	return (*((std::vector<FWWsSvcSocket*>*)_socketVector))[index];
}

void FWWsSvcManageBase::_closeAllUsingSocket()
{
	FW_PRINT("[%s] %s", this->_getTitle(), "开始通知FWWsSvcSocket离线，此过程可能需要几秒钟……");
	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "预料之外的BUG，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
	}
	for (unsigned int index = 0; index < ((std::vector<FWWsSvcSocket*>*)_socketVector)->size(); index++)
	{
		if (((std::set<unsigned int>*)_socketFreeIndexSet)->find(index) == ((std::set<unsigned int>*)_socketFreeIndexSet)->end())
		{
			FW_LOG_ERROR("%s", "预料之外的情况，_socketFreeIndexSet->find(index) == _socketFreeIndexSet->end()");
			FWWsSvcSocket * pWsSvcSocket = (*((std::vector<FWWsSvcSocket*>*)_socketVector))[index];
			pWsSvcSocket->_onCloseSocketWSI(pWsSvcSocket->GetActivityID());
		}
	}
	FW_PRINT("[%s] %s", this->_getTitle(), "通知FWWsSvcSocket离线完成。");
}


FW_NS_END