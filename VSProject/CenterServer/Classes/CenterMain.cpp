#include "stdafx.h"
#include "CenterMain.h"
#include <google/protobuf/message_lite.h>

FW_NS_USEING;


static CenterMain * _CenterMain = nullptr;

CenterMain::CenterMain()
	:_running(false)
	, _port(0)
	, _maxclients(0)
{
	_CenterMain = this;
}

CenterMain::~CenterMain()
{
	this->Stop();
	_CenterMain = nullptr;
	google::protobuf::ShutdownProtobufLibrary();
}

CenterMain * CenterMain::GetInstance()
{
	return _CenterMain;
}

bool CenterMain::Start()
{
	if (_running)
	{
		FW_LOG_ERROR("%s", "重复 Start");
		return false;
	}
	_running = true;

	FW_PRINT("%s", "开始中心服启动工作...");

	FWData fileData = FWFileIO::GetInstance()->LoadFileFromModuleFileDirectory("CenterConfig/RunConfig.json");
	if (fileData.IsNull())
	{
		FW_LOG_ERROR("%s", "无法读取中心服配置文件。");
		_running = false;
		return false;
	}
	rapidjson::GenericDocument<rapidjson::UTF8<> > configDocument;
	configDocument.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(fileData.GetPointer(), (size_t)fileData.GetSize());
	if (configDocument.HasParseError())
	{
		FW_LOG_ERROR("%s", "中心服配置文件解析出错。");
		_running = false;
		return false;
	}

	_port = configDocument["Port"].GetInt();
	_maxclients = configDocument["Maxclients"].GetInt();

	const rapidjson::GenericValue<rapidjson::UTF8<> > & mysqlConfig = configDocument["MySQL"];
	std::string mysqlHost = mysqlConfig["Host"].GetString();
	int mysqlPort = mysqlConfig["Port"].GetInt();
	std::string mysqlUsername = mysqlConfig["Username"].GetString();
	std::string mysqlPassword = mysqlConfig["Password"].GetString();
	std::string mysqlDatabase = mysqlConfig["Database"].GetString();

	const rapidjson::GenericValue<rapidjson::UTF8<> > & redisConfig = configDocument["Redis"];
	std::string redisHost = redisConfig["Host"].GetString();
	int redisPort = redisConfig["Port"].GetInt();
	std::string redisPassword = redisConfig["Password"].GetString();
	int selectIndex = redisConfig["Select"].GetInt();

	_onlineServerInfoManage.ClearLobby();
	_onlineServerInfoManage.ClearLogical();

	_dataHandle.InitMySQLConnectConfig(mysqlHost, (unsigned int)mysqlPort, mysqlUsername, mysqlPassword, mysqlDatabase);
	_dataHandle.InitRedisConnectConfig(redisHost, redisPort, redisPassword, selectIndex);
	_dataHandle.Start(1);

	{
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		logicDataGeneral->PushBackValue<int>(DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1);
		_dataHandle.PushLogicData(logicDataGeneral);
	}

	{
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		logicDataGeneral->PushBackValue<int>(DATA_H_INSIDE_INIT_DATABASE_REDIS_DATA);
		_dataHandle.PushLogicData(logicDataGeneral);
	}

	_quickHandle.Start(1);
	
	_tcpSvcManage.Start((unsigned short)_port, _maxclients, 0, FWTcpListenSocket::AF_V46MAPPED);

	_schedule.Start(50);

	FW_PRINT("%s", "中心服启动工作完成。");

	return true;
}

void CenterMain::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;

	FW_PRINT("%s", "开始中心服关闭工作...");

	_schedule.Stop();

	_tcpSvcManage.Stop();

	_quickHandle.Stop();

	_dataHandle.Stop();

	FW_PRINT("%s", "中心服关闭工作完成。");
}

int CenterMain::GetPort()
{
	return _port;
}

int CenterMain::GetMaxclients()
{
	return _maxclients;
}

Schedule * CenterMain::GetSchedule()
{
	return &_schedule;
}

RedisScriptSha1Manage * CenterMain::GetRedisScriptSha1Manage()
{
	return &_redisScriptSha1Manage;
}

ServerInfoManage * CenterMain::GetOnlineServerInfoManage()
{
	return &_onlineServerInfoManage;
}