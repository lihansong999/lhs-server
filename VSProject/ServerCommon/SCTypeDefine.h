#ifndef __SERVERCOMMON_TYPEDEFINE_H__
#define __SERVERCOMMON_TYPEDEFINE_H__

#include "SCLocal.h"

SC_NS_BEGIN

//redis key name
//lobby server
extern SC_DLL const char * RKN_LOBBY_SERVER_ID_SET;
extern SC_DLL const char * RKN_LOBBY_SERVER_INFO_HASH;
//logical server
extern SC_DLL const char * RKN_LOGICAL_SERVER_ID_SET;
extern SC_DLL const char * RKN_LOGICAL_SERVER_INFO_HASH;


//多久没有收到一个完整的消息包就断线
extern SC_DLL const long long SERVICE_PACKAGE_RECV_OUT_TIME;

//调用Send之后延迟关闭Socket的等待时间（并不能百分之百保证Send完成）
extern SC_DLL const long long DELAY_CLOSE_SOCKET_TIME_FOR_SENT;

//延迟关闭Socket的等待时间最大值
extern SC_DLL const long long DELAY_CLOSE_SOCKET_TIME_MAX;

//探测包检测字符串
extern SC_DLL const char * MESSAGE_PROBE_CHECK;


enum SvcNetMatchType
{
	SCSNMT_TCP = 1,	//TCP
	SCSNMT_WS,		//WebSocket

	SCSNMT_MAX = INT_MAX,
};

//服务NetMatch
struct SC_DLL SvcNetMatch {
	SvcNetMatch();
	SvcNetMatch(SvcNetMatchType type, const Framework::FWNetMatch & netMatch);
	SvcNetMatch(int type, unsigned int index, Framework::FW_NET_ACTIVITY_ID activityID);
	bool operator<(const SvcNetMatch & other) const;
	bool operator==(const SvcNetMatch & other) const;
	SvcNetMatchType			Type;
	Framework::FWNetMatch	NetMatch;
};


typedef long long PlayerID_t;
typedef long long Golds_t;
typedef long long Diamonds_t;

struct SC_DLL PlayerBindInfo
{
	PlayerID_t					PlayerID;
	SvcNetMatch					SvcNetMatch;
};

struct SC_DLL PlayerInfo
{
	PlayerID_t					PlayerID;
	Framework::FWString			Nickname;
	int							Sex;
	Golds_t						Golds;
	Diamonds_t					Diamonds;
	int							LobbyServerID;
	SvcNetMatch					LobbySvcNetMatch;
	int							LogicalServerID;
	SvcNetMatch					LogicalSvcNetMatch;
};

struct SC_DLL LobbyServerRedisInfo
{
	Framework::FWString			Address;
	int							TcpPort;
	int							WsPort;
	Framework::FWString			TestAddress;
	int							TcpTestPort;
	int							WsTestPort;
	int							Active;
	int							ConnectedCount;
	int							EnableInvolveBalance;
};

struct SC_DLL LogicalServerRedisInfo
{
	Framework::FWString			Address;
	int							TcpPort;
	int							WsPort;
	Framework::FWString			TestAddress;
	int							TcpTestPort;
	int							WsTestPort;
	int							Active;
	int							ConnectedCount;
	int							EnableInvolveBalance;
};

struct SC_DLL LobbyServerSelectionInfo
{
	int						LobbyServerID;
	Framework::FWString		Address;
	int						TcpPort;
	int						WsPort;
};

struct SC_DLL LogicalServerSelectionInfo
{
	int						LogicalServerID;
	Framework::FWString		Address;
	int						TcpPort;
	int						WsPort;
};


SC_NS_END


#endif //!__SERVERCOMMON_TYPEDEFINE_H__