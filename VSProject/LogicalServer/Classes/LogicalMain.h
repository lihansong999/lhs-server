#pragma once
#include "LogicalBase/Local.h"
#include "LogicalBase/TypeDefine.h"
#include "LogicalNetwork/TcpSvcManage.h"
#include "LogicalNetwork/WsSvcManage.h"
#include "LogicalNetwork/TcpOutManage.h"
#include "LogicalNetwork/NetworkTools.h"
#include "LogicalHandle/DataHandle.h"
#include "LogicalHandle/QuickHandle.h"


class LogicalMain
{
public:
	LogicalMain();
	~LogicalMain();

	static LogicalMain * GetInstance();

	bool Start();

	void Stop();

	int GetLogicalID();

	int GetTcpPort();

	int GetWsPort();

	int GetMaxClients();

	Schedule * GetSchedule();

	RedisScriptSha1Manage * GetRedisScriptSha1Manage();

	SvcNetMatchesLRU * GetSvcNetMatchesLRU();

	PlayerBindInfoManage * GetOnlinePlayerBindInfoManage();

private:
	volatile bool			_running;
	int						_logicalID;
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