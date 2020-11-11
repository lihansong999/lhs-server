#pragma once
#include "CenterBase/Local.h"
#include "CenterBase/TypeDefine.h"
#include "CenterBase/ServerInfoManage.h"
#include "CenterNetwork/TcpSvcManage.h"
#include "CenterHandle/DataHandle.h"
#include "CenterHandle/QuickHandle.h"

class CenterMain
{
public:
	CenterMain();
	~CenterMain();

	static CenterMain * GetInstance();

	bool Start();

	void Stop();

	int GetPort();

	int GetMaxclients();

	Schedule * GetSchedule();

	RedisScriptSha1Manage * GetRedisScriptSha1Manage();

	ServerInfoManage * GetOnlineServerInfoManage();

private:
	int						_port;
	int						_maxclients;
	volatile bool			_running;
	Schedule				_schedule;
	TcpSvcManage			_tcpSvcManage;
	RedisScriptSha1Manage	_redisScriptSha1Manage;
	QuickHandle				_quickHandle;
	DataHandle				_dataHandle;
	ServerInfoManage		_onlineServerInfoManage;
};