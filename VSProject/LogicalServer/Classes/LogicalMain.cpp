#include "stdafx.h"
#include "LogicalMain.h"
#include "LogicalNetwork/NetworkTools.h"
#include <google/protobuf/message_lite.h>

FW_NS_USEING;


static LogicalMain * _LogicalMain = nullptr;

LogicalMain::LogicalMain()
	:_running(false)
	, _logicalID(0)
	, _tcpPort(0)
	, _wsPort(0)
	, _maxClients(0)
{
	_LogicalMain = this;
}

LogicalMain::~LogicalMain()
{
	this->Stop();
	_LogicalMain = nullptr;
	google::protobuf::ShutdownProtobufLibrary();
}

LogicalMain * LogicalMain::GetInstance()
{
	return _LogicalMain;
}

bool LogicalMain::Start()
{
	if (_running)
	{
		FW_LOG_ERROR("%s", "重复 Start");
		return false;
	}
	_running = true;
	
	FW_PRINT("%s", "开始逻辑服启动工作...");

	FWData fileData = FWFileIO::GetInstance()->LoadFileFromModuleFileDirectory("LogicalConfig/RunConfig.json");
	if (fileData.IsNull())
	{
		FW_LOG_ERROR("%s", "无法读取逻辑服配置文件。");
		_running = false;
		return false;
	}
	rapidjson::GenericDocument<rapidjson::UTF8<> > configDocument;
	configDocument.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(fileData.GetPointer(), (size_t)fileData.GetSize());
	if (configDocument.HasParseError())
	{
		FW_LOG_ERROR("%s", "逻辑服配置文件解析出错。");
		_running = false;
		return false;
	}

	_logicalID = configDocument["LogicalID"].GetInt();
	_tcpPort = configDocument["TcpPort"].GetInt();
	_wsPort = configDocument["WsPort"].GetInt();
	_maxClients = configDocument["MaxClients"].GetInt();

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

	const rapidjson::GenericValue<rapidjson::UTF8<> > & centerConfig = configDocument["Center"];
	std::string centerHost = centerConfig["Host"].GetString();
	int centerPort = centerConfig["Port"].GetInt();

	_svcNetMatchesLRU.Clear();
	_onlinePlayerBindInfoManage.Clear();

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

	_tcpOutManage.InitCenterConnectConfig(centerHost, centerPort);
	_tcpOutManage.Start();
	_tcpOutManage.ConnectCenter();

	_tcpSvcManage.Start((unsigned short)_tcpPort, _maxClients, 0, FWTcpListenSocket::AF_V46MAPPED);

	_wsSvcManage.Start((unsigned short)_wsPort, _maxClients, 0, MSG_PACKAGE_MAX, FWWsSvcManageBase::WSDP_TEXT, FWWsSvcManageBase::WSAF_V46MAPPED);

	_schedule.Start(50);

	_schedule.Add([this](long long msInvl, FW_ID id)->void {
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		logicDataGeneral->PushBackValue<int>(DATA_H_INSIDE_WRITE_CONNECTED_COUNT);
		DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
	}, 3500);

	_schedule.Add([this](long long msInvl, FW_ID id)->void {
		SvcNetMatch svcNetMatches[20];
		int count = _svcNetMatchesLRU.LRU(svcNetMatches, sizeof(svcNetMatches) / sizeof(SvcNetMatch));
		if (count > 0)
		{
			long long current = FW_TIME();
			FWSvcSocketInfo svcSocketInfo;
			for (int i = 0; i < count; i++)
			{
				if (GetSvcSocketInfo(svcNetMatches[i], &svcSocketInfo))
				{
					if (current - svcSocketInfo.LastReceivedTime > SERVICE_PACKAGE_RECV_OUT_TIME)
					{
						CloseSvcSocket(svcNetMatches[i]);
					}
				}
			}
		}
	}, 8000);

	FW_PRINT("%s", "逻辑服启动工作完成。");
	
	return true;
}

void LogicalMain::Stop()
{
	if (!_running)
	{
		return;
	}
	_running = false;

	FW_PRINT("%s", "开始逻辑服关闭工作...");

	_schedule.Stop();

	_tcpSvcManage.Stop();

	_wsSvcManage.Stop();

	_tcpOutManage.Stop();

	_quickHandle.Stop();

	_dataHandle.Stop();

	FW_PRINT("%s", "逻辑服关闭工作完成。");
}

int LogicalMain::GetLogicalID()
{
	return _logicalID;
}

int LogicalMain::GetTcpPort()
{
	return _tcpPort;
}

int LogicalMain::GetWsPort()
{
	return _wsPort;
}

int LogicalMain::GetMaxClients()
{
	return _maxClients;
}

Schedule * LogicalMain::GetSchedule()
{
	return &_schedule;
}

RedisScriptSha1Manage * LogicalMain::GetRedisScriptSha1Manage()
{
	return &_redisScriptSha1Manage;
}

SvcNetMatchesLRU * LogicalMain::GetSvcNetMatchesLRU()
{
	return &_svcNetMatchesLRU;
}

PlayerBindInfoManage * LogicalMain::GetOnlinePlayerBindInfoManage()
{
	return &_onlinePlayerBindInfoManage;
}