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


//���û���յ�һ����������Ϣ���Ͷ���
extern SC_DLL const long long SERVICE_PACKAGE_RECV_OUT_TIME;

//����Send֮���ӳٹر�Socket�ĵȴ�ʱ�䣨�����ܰٷ�֮�ٱ�֤Send��ɣ�
extern SC_DLL const long long DELAY_CLOSE_SOCKET_TIME_FOR_SENT;

//�ӳٹر�Socket�ĵȴ�ʱ�����ֵ
extern SC_DLL const long long DELAY_CLOSE_SOCKET_TIME_MAX;

//̽�������ַ���
extern SC_DLL const char * MESSAGE_PROBE_CHECK;


enum SvcNetMatchType
{
	SCSNMT_TCP = 1,	//TCP
	SCSNMT_WS,		//WebSocket

	SCSNMT_MAX = INT_MAX,
};

//����NetMatch
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