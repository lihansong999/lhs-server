#pragma once
#include "PTLocal.h"
#include "PTWsOutManage.h"


class PTMain
{
public:
	PTMain();
	~PTMain();

	static PTMain * GetInstance();

	void Run();

private:
	void _threadProbeLobby();
	void _threadProbeLogical();
	bool _socketProbe(const char * addr, unsigned short port, bool lastActive);

private:
	std::string _mysqlHost;
	unsigned int _mysqlPort;
	std::string _mysqlUsername;
	std::string _mysqlPassword;
	std::string _mysqlDatabase;
	std::string _redisHost;
	int			_redisPort;
	std::string _redisPassword;
	int			_redisSelectIndex;
	Message::MsgPackageSend * _probePackage;
};