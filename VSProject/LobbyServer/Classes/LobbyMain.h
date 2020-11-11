#pragma once
#include "LobbyBase/Local.h"
#include "LobbyBase/TypeDefine.h"
#include "LobbyNetwork/TcpSvcManage.h"
#include "LobbyNetwork/WsSvcManage.h"
#include "LobbyNetwork/TcpOutManage.h"
#include "LobbyNetwork/NetworkTools.h"
#include "LobbyHandle/DataHandle.h"
#include "LobbyHandle/QuickHandle.h"


class LobbyMain
{
public:
	LobbyMain();
	~LobbyMain();

	static LobbyMain * GetInstance();

	bool Start();

	void Stop();

	int GetLobbyID();

	int GetTcpPort();

	int GetWsPort();

	int GetMaxClients();

	Schedule * GetSchedule();

	RedisScriptSha1Manage * GetRedisScriptSha1Manage();

	SvcNetMatchesLRU * GetSvcNetMatchesLRU();

	PlayerBindInfoManage * GetOnlinePlayerBindInfoManage();

private:
	volatile bool			_running;
	int						_lobbyID;
	int						_tcpPort;
	int						_wsPort;
	int						_maxClients;
	Schedule				_schedule;
	TcpSvcManage			_tcpSvcManage;
	WsSvcManage				_wsSvcManage;
	TcpOutManage			_tcpOutManage;
	RedisScriptSha1Manage	_redisScriptSha1Manage;
	QuickHandle				_quickHandle;
	DataHandle				_dataHandle;
	SvcNetMatchesLRU		_svcNetMatchesLRU;
	PlayerBindInfoManage	_onlinePlayerBindInfoManage;
};