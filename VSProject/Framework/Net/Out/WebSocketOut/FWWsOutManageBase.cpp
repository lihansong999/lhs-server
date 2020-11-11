#include "FWWsOutManageBase.h"
#include "FWWsOutSocket.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"
#include "../../../Common/FWString.h"

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#endif // !HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <libwebsockets.h>

FW_NS_BEGIN

#define FREE_FOREVER_SOCKET_COUNT	2


struct WSSessionData
{
	unsigned int Index;
	FW_NET_ACTIVITY_ID ActivityID;
	FW_ID Custom;
};

static int _WS_Callback_Function2(FWWsOutManageBase * self, void * argWsi, int argReason, void * user, void * in, size_t len)
{
	struct lws * wsi = (struct lws*)argWsi;
	enum lws_callback_reasons reason = (enum lws_callback_reasons)argReason;
	WSSessionData * sessionData = nullptr;
	if (0 != (intptr_t)user)
	{
		std::map<intptr_t, WSSessionData>::iterator it = ((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->find((intptr_t)user);
		if (it != ((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->end())
			sessionData = &(it->second);
	}

	switch (reason)
	{
	case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
	{
		if (!sessionData)
			return 0;
		if (sessionData->ActivityID != 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_CONNECTION_ERROR: (sessionData->ActivityID != 0LL)");
			return 0;
		}
		FW_ID custom = sessionData->Custom;
		((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase((intptr_t)user);
		lws_set_wsi_user(wsi, NULL);
		self->_onWsOutConnectResult(false, FWNetMatch(), custom);
		return 0;
	}
		break;
	case LWS_CALLBACK_CLIENT_ESTABLISHED:
	{
		if (!sessionData)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_ESTABLISHED: (!sessionData)");
			return -1;
		}
		if (sessionData->ActivityID != 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_ESTABLISHED: (sessionData->ActivityID != 0LL)");
			return -1;
		}
		FWWsOutSocket * pWsOutSocket = self->_newSocket();
		if (!pWsOutSocket)
		{
			FW_ID custom = sessionData->Custom;
			((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase((intptr_t)user);
			lws_set_wsi_user(wsi, NULL);
			self->_onWsOutOverloaded(custom);
			return -1;
		}
		if (!pWsOutSocket->_initSocket(wsi, sessionData->Custom))
		{
			FW_ID custom = sessionData->Custom;
			((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase((intptr_t)user);
			lws_set_wsi_user(wsi, NULL);
			self->_onWsOutConnectResult(false, FWNetMatch(), custom);
			self->_deleteSocket(pWsOutSocket);
			return -1;
		}
		FWNetMatch netMatch(pWsOutSocket->GetIndex(), pWsOutSocket->GetActivityID());
		sessionData->Index = netMatch.Index;
		sessionData->ActivityID = netMatch.ActivityID;
		self->_onWsOutConnectResult(true, netMatch, sessionData->Custom);
		return 0;
	}
		break;
	case LWS_CALLBACK_CLIENT_RECEIVE:
	{
		if (!sessionData)
			return -1;
		if (sessionData->ActivityID == 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_RECEIVE: (sessionData->ActivityID == 0LL)");
			return -1;
		}
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		FWWsOutSocket * pWsOutSocket = self->_getSocket(netMatch.Index);
		if (!pWsOutSocket)
			return -1;
		if (!pWsOutSocket->_onReceiveWSI(netMatch.ActivityID, lws_is_first_fragment(wsi) != 0, lws_is_final_fragment(wsi) != 0, lws_frame_is_binary(wsi) != 0, (char*)in, len))
			return -1;
		return 0;
	}
		break;
	case LWS_CALLBACK_CLIENT_WRITEABLE:
	{
		if (!sessionData)
			return -1;
		if (sessionData->ActivityID == 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_WRITEABLE: (sessionData->ActivityID == 0LL)");
			return -1;
		}
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		FWWsOutSocket * pWsOutSocket = self->_getSocket(netMatch.Index);
		if (!pWsOutSocket)
			return -1;
		if (!pWsOutSocket->_onWriteableWSI(netMatch.ActivityID))
			return -1;
		return 0;
	}
		break;
	case LWS_CALLBACK_CLIENT_CLOSED:
	{
		if (!sessionData)
			return 0;
		if (sessionData->ActivityID == 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_CLIENT_CLOSED: (sessionData->ActivityID == 0LL)");
			return 0;
		}
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase((intptr_t)user);
		lws_set_wsi_user(wsi, NULL);
		FWWsOutSocket * pWsOutSocket = self->_getSocket(netMatch.Index);
		if (pWsOutSocket)
			pWsOutSocket->_onCloseSocketWSI(netMatch.ActivityID);
		return 0;
	}
		break;
	case LWS_CALLBACK_WSI_DESTROY:
	{
		if (!sessionData)
			return 0;
		if (sessionData->ActivityID == 0LL)
		{
			FW_LOG_ERROR("%s", "预料之外的情况，case LWS_CALLBACK_WSI_DESTROY: (sessionData->ActivityID == 0LL)");
			return 0;
		}
		FWNetMatch netMatch(sessionData->Index, sessionData->ActivityID);
		((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase((intptr_t)user);
		lws_set_wsi_user(wsi, NULL);
		FWWsOutSocket * pWsOutSocket = self->_getSocket(netMatch.Index);
		if (pWsOutSocket)
			pWsOutSocket->_onCloseSocketWSI(netMatch.ActivityID);
		return 0;
	}
		break;
	case LWS_CALLBACK_GET_THREAD_ID:
	{
#if defined(PTW32_VERSION)
		return (int)(unsigned long long)pthread_getw32threadid_np(pthread_self());
#else
		return (int)(unsigned long long)pthread_self();
#endif
	}
		break;
	default:
		break;
	}
	return 0;
}

static int _WS_Callback_Function(struct lws * wsi, enum lws_callback_reasons reason, void * user, void * in, size_t len)
{
	FWWsOutManageBase * self = nullptr;
	if (wsi)
		self = (FWWsOutManageBase*)lws_context_user(lws_get_context(wsi));
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
	{ "", _WS_Callback_Function, 0, FW_WSOUT_RECV_BUF_SIZE, 0, NULL, FW_WSOUT_SEND_BUF_SIZE },
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

struct ThreadOutArgs
{
	FWWsOutManageBase * Self;
	unsigned int MaxConnectedCount;
	bool DisableIPv6;
	std::promise<int> * PromisePollStart;
};

struct ConnectEventData
{
	ConnectEventData(const char * host, FW_ID custom, bool allowCertVerify)
		:Host(host)
		, Custom(custom)
		, AllowCertVerify(allowCertVerify)
	{}
	std::string Host;
	FW_ID Custom;
	bool AllowCertVerify;
};

static void _Connect(FWWsOutManageBase * self, void * context)
{
	std::list<ConnectEventData> tempConnectEventList;
	self->_connectEventContainerLock.Lock();
	for (std::list<ConnectEventData>::iterator it = ((std::list<ConnectEventData>*)self->_connectEventList)->begin(); it != ((std::list<ConnectEventData>*)self->_connectEventList)->end(); it++)
	{
		tempConnectEventList.push_back(std::move(*it));
	}
	((std::list<ConnectEventData>*)self->_connectEventList)->clear();
	self->_connectEventContainerLock.UnLock();
	char host[256];
	for (std::list<ConnectEventData>::iterator it = tempConnectEventList.begin(); it != tempConnectEventList.end(); it++)
	{
		strcpy_s(host, sizeof(host), it->Host.c_str());
		const char *prot;
		const char *ads;
		int port;
		const char *p;
		lws_parse_uri(host, &prot, &ads, &port, &p);
		struct lws_client_connect_info ccinfo;
		memset(&ccinfo, 0, sizeof(ccinfo));
		char path[256] = {};
		if (p[0] != '/') 
		{
			path[0] = '/';
			lws_strncpy(path + 1, p, sizeof(path) - 1);
			ccinfo.path = path;
		}
		else
		{
			ccinfo.path = p;
		}
		ccinfo.context = (struct lws_context *)context;
		ccinfo.address = ads;
		ccinfo.port = port;
		if (strcmp(prot, "wss") == 0)
		{
			ccinfo.ssl_connection = LCCSCF_USE_SSL;
			if (it->AllowCertVerify)
				ccinfo.ssl_connection |= LCCSCF_ALLOW_SELFSIGNED | LCCSCF_SKIP_SERVER_CERT_HOSTNAME_CHECK | LCCSCF_ALLOW_EXPIRED;
		}
		ccinfo.host = ads;
		ccinfo.origin = ads;
		ccinfo.protocol = _Protocols[0].name;
		ccinfo.ietf_version_or_minus_one = -1;
		WSSessionData sessionData;
		memset(&sessionData, 0, sizeof(WSSessionData));
		sessionData.Custom = it->Custom;
		const intptr_t key = ++self->_wsiSessionDataActivity;
		std::pair<std::map<intptr_t, WSSessionData>::iterator, bool> insertRet = ((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->insert(std::pair<intptr_t, WSSessionData>(key, sessionData));
		if (!insertRet.second)
		{
			FW_LOG_ERROR("%s%p", "框架出现严重BUG，_wsiSessionDataMap->insert失败，key = ", key);
			self->_onWsOutConnectResult(false, FWNetMatch(), it->Custom);
			continue;
		}
		ccinfo.userdata = (void*)key;
		struct lws * wsi = lws_client_connect_via_info(&ccinfo);
		if (wsi == NULL)
		{
			std::map<intptr_t, WSSessionData>::iterator it = ((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->find(key);
			if (it != ((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->end())
			{
				FW_ID custom = it->second.Custom;
				((std::map<intptr_t, WSSessionData>*)self->_wsiSessionDataMap)->erase(it);
				self->_onWsOutConnectResult(false, FWNetMatch(), custom);
			}
		}
	}
}

static void * PTW32_CDECL _Thread_Out(void * args)
{
	ThreadOutArgs * tsArgs = (ThreadOutArgs*)args;
	FWLifeCycleExecute<std::function<void(void)>, std::function<void(void)>> lifeCycleExecute(nullptr, [tsArgs](void)->void {
		delete tsArgs;
	});
	lws_set_log_level(LLL_ERR | LLL_WARN | LLL_NOTICE, &_Log_Emit_Function);
	struct lws_context_creation_info info;
	memset(&info, 0, sizeof(struct lws_context_creation_info));
	info.user = tsArgs->Self;
	info.port = CONTEXT_PORT_NO_LISTEN;
	info.protocols = _Protocols;
	info.gid = -1;
	info.uid = -1;
	info.ka_time = 60;
	info.ka_interval = 2;
	info.ka_probes = 5;
	info.count_threads = 1;
	info.fd_limit_per_thread = tsArgs->MaxConnectedCount + 4;
	info.timeout_secs = 15;
	info.pt_serv_buf_size = FW_WSOUT_SERV_SEND_BUF_SIZE;
	info.ws_ping_pong_interval = 45;
	info.extensions = _Extensions;
	info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
	if (tsArgs->DisableIPv6)
		info.options |= LWS_SERVER_OPTION_DISABLE_IPV6;
	struct lws_context * context = lws_create_context(&info);
	if (!context) {
		FW_LOG_ERROR("%s", "lws_create_context failed");
		tsArgs->PromisePollStart->set_value(0);
		return NULL;
	}
	FW_PRINT("[%s] %s", tsArgs->Self->_getTitle(), "WebSocket向外连接poll已启动。");
	tsArgs->PromisePollStart->set_value(0);
	while (tsArgs->Self->_running && lws_service_tsi(context, 3, 0) >= 0)
	{
		_Connect(tsArgs->Self, context);
		std::this_thread::sleep_for(std::chrono::milliseconds(7));
	}
	lws_cancel_service(context);
	lws_context_destroy(context);
	tsArgs->Self->_cancelAllConnectEvent();
	tsArgs->Self->_closeAllUsingSocket();
	if (((std::map<intptr_t, WSSessionData>*)tsArgs->Self->_wsiSessionDataMap)->size() > 0)
	{
		FW_LOG_ERROR("%s", "框架设计有BUG，退出时 _wsiSessionDataMap->size() > 0");
	}
	return NULL;
}

FWWsOutManageBase::FWWsOutManageBase()
	:_running(false)
	, _rSinglePackageMax(INT_MAX)
	, _dataProtocol(WSDP_TEXT)
	, _pthread(NULL)
	, _wsiSessionDataActivity(0)
{
	_connectEventList = new std::list<ConnectEventData>();
	_wsiSessionDataMap = new std::map<intptr_t, WSSessionData>();
	_socketVector = new std::vector<FWWsOutSocket*>();
	_socketFreeIndexDeque = new std::deque<unsigned int>();
	_socketFreeIndexSet = new std::set<unsigned int>();
}

FWWsOutManageBase::~FWWsOutManageBase()
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "运行中的管理对象被析构");
	}
	delete ((std::list<ConnectEventData>*)_connectEventList);
	delete ((std::map<intptr_t, WSSessionData>*)_wsiSessionDataMap);
	delete ((std::vector<FWWsOutSocket*>*)_socketVector);
	delete ((std::deque<unsigned int>*)_socketFreeIndexDeque);
	delete ((std::set<unsigned int>*)_socketFreeIndexSet);
}

bool FWWsOutManageBase::Start(unsigned int maxConnectedCount, int rSinglePackageMax /*= INT_MAX*/, WSDataProtocol dataProtocol /*= WSDP_TEXT*/, bool disableIPv6 /*= true*/)
{
	if (_running)
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "重复 Start");
		return false;
	}
	_running = true;

	_rSinglePackageMax = rSinglePackageMax;

	_dataProtocol = dataProtocol;

	_wsiSessionDataActivity = 0;
	((std::map<intptr_t, WSSessionData>*)_wsiSessionDataMap)->clear();

	for (unsigned int index = 0; index < maxConnectedCount + FREE_FOREVER_SOCKET_COUNT; index++)
	{
		((std::vector<FWWsOutSocket*>*)_socketVector)->push_back(new FWWsOutSocket(index, this));
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->push_back(index);
		((std::set<unsigned int>*)_socketFreeIndexSet)->insert(index);
	}

	ThreadOutArgs * tsArgs = new ThreadOutArgs();
	tsArgs->Self = this;
	tsArgs->MaxConnectedCount = maxConnectedCount;
	tsArgs->DisableIPv6 = disableIPv6;

	_pthread = new pthread_t();
	pthread_attr_t tAttr;
	pthread_attr_init(&tAttr);
	pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_JOINABLE);
	std::promise<int> promisePollStart;
	std::future<int> futurePollStart = promisePollStart.get_future();
	tsArgs->PromisePollStart = &promisePollStart;
	pthread_create((pthread_t*)_pthread, &tAttr, &_Thread_Out, tsArgs);
	pthread_attr_destroy(&tAttr);
	futurePollStart.get();

	return true;
}

void FWWsOutManageBase::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;

	pthread_join(*((pthread_t*)_pthread), NULL);
	delete ((pthread_t*)_pthread);

	//清理FWWsOutSocket池
	{
		FW_PRINT("[%s] %s", this->_getTitle(), "开始清理FWWsOutSocket内存池，此过程可能需要几秒钟……");
		std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //稍微等待从其他线程调用到本类中对FWWsOutSocket进行操作并已经通过_running判断的执行代码运行完毕（并非绝对安全，如需绝对安区只能考虑操作中加锁）
		for (unsigned int index = 0; index < ((std::vector<FWWsOutSocket*>*)_socketVector)->size(); index++)
		{
			delete ((*((std::vector<FWWsOutSocket*>*)_socketVector))[index]);
		}
		((std::vector<FWWsOutSocket*>*)_socketVector)->clear();
		((std::deque<unsigned int>*)_socketFreeIndexDeque)->clear();
		((std::set<unsigned int>*)_socketFreeIndexSet)->clear();
		FW_PRINT("[%s] %s", this->_getTitle(), "FWWsOutSocket内存池清理完成。");
	}

	_wsiSessionDataActivity = 0;
	((std::map<intptr_t, WSSessionData>*)_wsiSessionDataMap)->clear();
}

void FWWsOutManageBase::Connect(const char * host, FW_ID custom /*= 0LL*/, bool allowCertVerify /*= true*/)
{
	if (!_running)
	{
		return;
	}
	if (!host)
	{
		return;
	}

	_connectEventContainerLock.Lock();
	((std::list<ConnectEventData>*)_connectEventList)->push_back(ConnectEventData(host, custom, allowCertVerify));
	_connectEventContainerLock.UnLock();
}

bool FWWsOutManageBase::SendDataWsOutSocket(const FWNetMatch & netMatch, const char * pData, int size)
{
	if (!_running)
	{
		return false;
	}
	if (size < 0 || (size > 0 && !pData))
	{
		return false;
	}

	FWWsOutSocket * pWsOutSocket = this->_getSocket(netMatch.Index);
	if (!pWsOutSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return false;
	}
	return pWsOutSocket->SendData(netMatch.ActivityID, pData, size);
}

void FWWsOutManageBase::SendDataWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size)
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
		FWWsOutSocket * pWsOutSocket = this->_getSocket(netMatches[i].Index);
		if (!pWsOutSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pWsOutSocket->SendData(netMatches[i].ActivityID, pData, size);
	}
}

void FWWsOutManageBase::CloseWsOutSocket(const FWNetMatch & netMatch)
{
	if (!_running)
	{
		return;
	}

	FWWsOutSocket * pWsOutSocket = this->_getSocket(netMatch.Index);
	if (!pWsOutSocket)
	{
		FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatch.Index);
		return;
	}
	pWsOutSocket->CloseSocket(netMatch.ActivityID);
}

void FWWsOutManageBase::CloseWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count)
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
		FWWsOutSocket * pWsOutSocket = this->_getSocket(netMatches[i].Index);
		if (!pWsOutSocket)
		{
			FW_LOG_ERROR("[%s] %s%u", this->_getTitle(), "_getSocket(index) return NULL, index = ", netMatches[i].Index);
			continue;
		}
		pWsOutSocket->CloseSocket(netMatches[i].ActivityID);
	}
}

const char * FWWsOutManageBase::_getTitle() const
{
	return typeid(*this).name();
}

FWWsOutSocket * FWWsOutManageBase::_newSocket()
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

	return (*((std::vector<FWWsOutSocket*>*)_socketVector))[index];
}

void FWWsOutManageBase::_deleteSocket(FWWsOutSocket * pWsOutSocket)
{
	FWPTW32LockScopeController lsc(&_freeIndexContainerLock);

	unsigned int index = pWsOutSocket->GetIndex();

	if (((std::vector<FWWsOutSocket*>*)_socketVector)->size() <= index)
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

FWWsOutSocket * FWWsOutManageBase::_getSocket(unsigned int index)
{
	if (((std::vector<FWWsOutSocket*>*)_socketVector)->size() <= index)
	{
		return nullptr;
	}
	return (*((std::vector<FWWsOutSocket*>*)_socketVector))[index];
}

void FWWsOutManageBase::_closeAllUsingSocket()
{
	FW_PRINT("[%s] %s", this->_getTitle(), "开始通知FWWsOutSocket离线，此过程可能需要几秒钟……");
	if (((std::deque<unsigned int>*)_socketFreeIndexDeque)->size() != ((std::set<unsigned int>*)_socketFreeIndexSet)->size())
	{
		FW_LOG_ERROR("[%s] %s", this->_getTitle(), "预料之外的BUG，_socketFreeIndexDeque->size() != _socketFreeIndexSet->size()");
	}
	for (unsigned int index = 0; index < ((std::vector<FWWsOutSocket*>*)_socketVector)->size(); index++)
	{
		if (((std::set<unsigned int>*)_socketFreeIndexSet)->find(index) == ((std::set<unsigned int>*)_socketFreeIndexSet)->end())
		{
			FW_LOG_ERROR("%s", "预料之外的情况，_socketFreeIndexSet->find(index) == _socketFreeIndexSet->end()");
			FWWsOutSocket * pWsOutSocket = (*((std::vector<FWWsOutSocket*>*)_socketVector))[index];
			pWsOutSocket->_onCloseSocketWSI(pWsOutSocket->GetActivityID());
		}
	}
	FW_PRINT("[%s] %s", this->_getTitle(), "通知FWWsOutSocket离线完成。");
}

void FWWsOutManageBase::_cancelAllConnectEvent()
{
	FWPTW32LockScopeController lsc(&_connectEventContainerLock);
	for (std::list<ConnectEventData>::iterator it = ((std::list<ConnectEventData>*)_connectEventList)->begin(); it != ((std::list<ConnectEventData>*)_connectEventList)->end(); it++)
	{
		this->_onWsOutConnectResult(false, FWNetMatch(), it->Custom);
	}
	((std::list<ConnectEventData>*)_connectEventList)->clear();
}


FW_NS_END