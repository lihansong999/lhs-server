#include "PTMain.h"

FW_NS_USEING;


#define PROBE_LOBBY_INTERVAL_TIME_SEC	30
#define PROBE_LOGICAL_INTERVAL_TIME_SEC	40

#define PROBE_LOBBY_QUIET_COUNT		2
#define PROBE_LOGICAL_QUIET_COUNT	3


static PTMain * _PTMain = nullptr;

PTMain::PTMain()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	_PTMain = this;

	Message::Common::ProbeReq probeReq;
	probeReq.Check = MESSAGE_PROBE_CHECK;
	_probePackage = new Message::MsgPackageSend(Message::Common::MSG_MAIN_TEST, Message::Common::MSG_ASS_TEST_PROBE, &probeReq);
}

PTMain::~PTMain()
{
	_PTMain = nullptr;

	delete _probePackage;

	WSACleanup();
}

PTMain * PTMain::GetInstance()
{
	return _PTMain;
}

void PTMain::Run()
{
	FWData fileData = FWFileIO::GetInstance()->LoadFileFromModuleFileDirectory("ProbeToolConfig/RunConfig.json");
	if (fileData.IsNull())
	{
		FW_PRINT("%s", "无法读取测试服务器工具配置文件。");
		return;
	}
	rapidjson::GenericDocument<rapidjson::UTF8<> > configDocument;
	configDocument.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(fileData.GetPointer(), (size_t)fileData.GetSize());
	if (configDocument.HasParseError())
	{
		FW_PRINT("%s", "测试服务器工具配置文件解析出错。");
		return;
	}
	const rapidjson::GenericValue<rapidjson::UTF8<> > & mysqlConfig = configDocument["MySQL"];
	_mysqlHost = mysqlConfig["Host"].GetString();
	_mysqlPort = (unsigned int)mysqlConfig["Port"].GetInt();
	_mysqlUsername = mysqlConfig["Username"].GetString();
	_mysqlPassword = mysqlConfig["Password"].GetString();
	_mysqlDatabase = mysqlConfig["Database"].GetString();

	const rapidjson::GenericValue<rapidjson::UTF8<> > & redisConfig = configDocument["Redis"];
	_redisHost = redisConfig["Host"].GetString();
	_redisPort = redisConfig["Port"].GetInt();
	_redisPassword = redisConfig["Password"].GetString();
	_redisSelectIndex = redisConfig["Select"].GetInt();

	bool probeLobbyServer = configDocument["ProbeLobbyServer"].GetBool();
	bool probeLogicalServer = configDocument["ProbeLogicalServer"].GetBool();
	if (!probeLobbyServer && !probeLogicalServer)
	{
		FW_PRINT("%s", "配置中关闭了所有测试。");
		return;
	}

	if (probeLobbyServer)
	{
		FW_PRINT("%s", "开启测试大厅服...");
		std::thread t1 = std::thread(std::bind(&PTMain::_threadProbeLobby, this));
		t1.detach();
	}

	if (probeLogicalServer)
	{
		FW_PRINT("%s", "开启测试逻辑服...");
		std::thread t2 = std::thread(std::bind(&PTMain::_threadProbeLogical, this));
		t2.detach();
	}
	
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
}

void PTMain::_threadProbeLobby()
{
	DataManipulation dataManipulation;
	dataManipulation.GetRedisHelper()->Init(_redisHost.c_str(), _redisPort, _redisPassword.c_str(), _redisSelectIndex, 7, 20);
	std::map<std::string, int> lastQuietMap;
	static time_t lastProbeTime = 0;
	while (true)
	{
		time_t currentTime = time(nullptr);
		time_t invlTime = currentTime - lastProbeTime;
		if (invlTime < PROBE_LOBBY_INTERVAL_TIME_SEC)
		{
			std::this_thread::sleep_for(std::chrono::seconds(PROBE_LOBBY_INTERVAL_TIME_SEC - invlTime));
		}
		lastProbeTime = time(nullptr);
		FWRedisCR redisCR;
		FWRedisCmdRet redisCmdRet = dataManipulation.GetRedisHelper()->Command(&redisCR, "SMEMBERS %s", RKN_LOBBY_SERVER_ID_SET);
		if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
		{
			FW_PRINT("%s", "大厅服信息查询失败。");
			continue;
		}
		std::vector<std::string> idStringVector;
		for (int i = 0; i < redisCR.GetArrayCount(); i++)
		{
			const FWRedisCR * cr = redisCR.GetArrayElement(i);
			if (cr->GetReplyType() != FWRedisCR::REDIS_CR_TYPE_STRING)
			{
				FW_PRINT("%s", "错误：cr->GetReplyType() != FWRedisCR::REDIS_CR_TYPE_STRING。");
				break;
			}
			idStringVector.push_back(cr->GetString());
		}
		if (idStringVector.size() == 0)
		{
			FW_PRINT("%s", "大厅服信息查询无结果。");
			continue;
		}
		std::map<std::string, LobbyServerRedisInfo> serverInfoMap;
		for (size_t i = 0; i < idStringVector.size(); i++)
		{
			LobbyServerRedisInfo info;
			if (dataManipulation.GetLobbyServerRedisInfo(atoi(idStringVector[i].c_str()), &info) != 0)
			{
				FW_PRINT("%s%s", "错误：查询大厅服详细信息失败，ID = ", idStringVector[i].c_str());
				continue;
			}
			serverInfoMap.insert(std::pair<std::string, LobbyServerRedisInfo>(idStringVector[i].c_str(), info));
		}
		for (std::map<std::string, int>::iterator it = lastQuietMap.begin(); it != lastQuietMap.end();)
		{
			if (serverInfoMap.find(it->first) == serverInfoMap.end())
				lastQuietMap.erase(it++);
			else
				it++;
		}
		int activeCount = 0;
		int deathCount = 0;
		for (std::map<std::string, LobbyServerRedisInfo>::iterator it = serverInfoMap.begin(); it != serverInfoMap.end(); it++)
		{
			int current_active = (this->_socketProbe(it->second.TestAddress.C_Str(), (unsigned short)it->second.TcpTestPort, it->second.Active == 0 ? false : true)) ? (1) : (0);
			if (current_active == 1)
				activeCount++;
			else 
				deathCount++;
			if (it->second.Active != current_active)
			{
				bool needWriteRedis = true;
				if (current_active == 0 && PROBE_LOBBY_QUIET_COUNT > 1)
				{
					std::map<std::string, int>::iterator it2 = lastQuietMap.find(it->first);
					if (it2 == lastQuietMap.end())
					{
						std::pair<std::map<std::string, int>::iterator, bool> r = lastQuietMap.insert(std::pair<std::string, int>(it->first, 1));
						if (r.second)
							needWriteRedis = false;
					}
					else
					{
						if (++(it2->second) < PROBE_LOBBY_QUIET_COUNT)
							needWriteRedis = false;
					}
				}
				if (needWriteRedis)
				{
					lastQuietMap.erase(it->first);
					char cmdBuf[256];
					sprintf_s(cmdBuf, sizeof(cmdBuf), "HMSET %s%s %s", RKN_LOBBY_SERVER_INFO_HASH, it->first.c_str(), "active %d");
					dataManipulation.GetRedisHelper()->Command(nullptr, cmdBuf, current_active);
				}
			}
		}
		FW_PRINT("%s%d%s%d%s%d%s", "大厅服共测试 ", (int)serverInfoMap.size(), "个，活跃 ", activeCount, "个，离线 ", deathCount, "个。");
	}
}

void PTMain::_threadProbeLogical()
{
	DataManipulation dataManipulation;
	dataManipulation.GetRedisHelper()->Init(_redisHost.c_str(), _redisPort, _redisPassword.c_str(), _redisSelectIndex, 7, 20);
	std::map<std::string, int> lastQuietMap;
	static time_t lastProbeTime = 0;
	while (true)
	{
		time_t currentTime = time(nullptr);
		time_t invlTime = currentTime - lastProbeTime;
		if (invlTime < PROBE_LOGICAL_INTERVAL_TIME_SEC)
		{
			std::this_thread::sleep_for(std::chrono::seconds(PROBE_LOGICAL_INTERVAL_TIME_SEC - invlTime));
		}
		lastProbeTime = time(nullptr);
		FWRedisCR redisCR;
		FWRedisCmdRet redisCmdRet = dataManipulation.GetRedisHelper()->Command(&redisCR, "SMEMBERS %s", RKN_LOGICAL_SERVER_ID_SET);
		if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
		{
			FW_PRINT("%s", "逻辑服信息查询失败。");
			continue;
		}
		std::vector<std::string> idStringVector;
		for (int i = 0; i < redisCR.GetArrayCount(); i++)
		{
			const FWRedisCR * cr = redisCR.GetArrayElement(i);
			if (cr->GetReplyType() != FWRedisCR::REDIS_CR_TYPE_STRING)
			{
				FW_PRINT("%s", "错误：cr->GetReplyType() != FWRedisCR::REDIS_CR_TYPE_STRING。");
				break;
			}
			idStringVector.push_back(cr->GetString());
		}
		if (idStringVector.size() == 0)
		{
			FW_PRINT("%s", "逻辑服信息查询无结果。");
			continue;
		}
		std::map<std::string, LogicalServerRedisInfo> serverInfoMap;
		for (size_t i = 0; i < idStringVector.size(); i++)
		{
			LogicalServerRedisInfo info;
			if (dataManipulation.GetLogicalServerRedisInfo(atoi(idStringVector[i].c_str()), &info) != 0)
			{
				FW_PRINT("%s%s", "错误：查询逻辑服详细信息失败，ID = ", idStringVector[i].c_str());
				continue;
			}
			serverInfoMap.insert(std::pair<std::string, LogicalServerRedisInfo>(idStringVector[i].c_str(), info));
		}
		for (std::map<std::string, int>::iterator it = lastQuietMap.begin(); it != lastQuietMap.end();)
		{
			if (serverInfoMap.find(it->first) == serverInfoMap.end())
				lastQuietMap.erase(it++);
			else
				it++;
		}
		int activeCount = 0;
		int deathCount = 0;
		for (std::map<std::string, LogicalServerRedisInfo>::iterator it = serverInfoMap.begin(); it != serverInfoMap.end(); it++)
		{
			int current_active = (this->_socketProbe(it->second.TestAddress.C_Str(), (unsigned short)it->second.TcpTestPort, it->second.Active == 0 ? false : true)) ? (1) : (0);
			if (current_active == 1)
				activeCount++;
			else
				deathCount++;
			if (it->second.Active != current_active)
			{
				bool needWriteRedis = true;
				if (current_active == 0 && PROBE_LOGICAL_QUIET_COUNT > 1)
				{
					std::map<std::string, int>::iterator it2 = lastQuietMap.find(it->first);
					if (it2 == lastQuietMap.end())
					{
						std::pair<std::map<std::string, int>::iterator, bool> r = lastQuietMap.insert(std::pair<std::string, int>(it->first, 1));
						if (r.second)
							needWriteRedis = false;
					}
					else
					{
						if (++(it2->second) < PROBE_LOGICAL_QUIET_COUNT)
							needWriteRedis = false;
					}
				}
				if (needWriteRedis)
				{
					lastQuietMap.erase(it->first);
					char cmdBuf[256];
					sprintf_s(cmdBuf, sizeof(cmdBuf), "HMSET %s%s %s", RKN_LOGICAL_SERVER_INFO_HASH, it->first.c_str(), "active %d");
					dataManipulation.GetRedisHelper()->Command(nullptr, cmdBuf, current_active);
				}
			}
		}
		FW_PRINT("%s%d%s%d%s%d%s", "逻辑服共测试 ", (int)serverInfoMap.size(), "个，活跃 ", activeCount, "个，离线 ", deathCount, "个。");
	}
}

bool PTMain::_socketProbe(const char * addr, unsigned short port, bool lastActive)
{
	BSDTcpSocket bsdTcpSocket;
	bool connected = bsdTcpSocket.connect(addr, port, (lastActive ? 10 : 5));
	if (!connected)
		return false;

	if (!bsdTcpSocket.send_full(_probePackage->GetBuffer(), _probePackage->GetSize()))
		return false;

	bool ret = false;

#define BUFF_SIZE 512
	char buff[BUFF_SIZE];
	int offset = 0;
	for (int i = 0; i < 7; i++)
	{
		if (bsdTcpSocket.isReadReady(2, 0))
		{
			if (offset == BUFF_SIZE)
				break;
			int r = bsdTcpSocket.recv(buff + offset, BUFF_SIZE - offset);
			if (r == 0)
				break;
			if (r > 0)
			{
				offset += r;
				int validSize = Message::MsgPackageRecv::TestBufferValidity(buff, offset, nullptr);
				if (validSize < 0)
					break;
				if (validSize > 0)
				{
					int outValidSize = 0;
					Message::MsgPackageRecv msgPackageRecv(buff, validSize, &outValidSize);
					if (outValidSize == 0 || msgPackageRecv.GetErrorCode() != 0)
						break;
					if (msgPackageRecv.GetMainID() != Message::Common::MSG_MAIN_TEST || msgPackageRecv.GetAssistantID() != Message::Common::MSG_ASS_TEST_PROBE)
						break;
					Message::Common::ProbeRes probeRes;
					if (!msgPackageRecv.Deserialize(&probeRes))
						break;
					ret = true;
					break;
				}
			}
		}
	}

	bsdTcpSocket.close();

	return ret;
}
