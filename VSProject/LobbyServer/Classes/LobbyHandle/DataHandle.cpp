#include "stdafx.h"
#include "DataHandle.h"
#include "QuickHandle.h"
#include "../LobbyMain.h"
#include "../LobbyNetwork/NetworkTools.h"
#include "../LobbyNetwork/TcpOutManage.h"
#include "../LobbyNetwork/TcpSvcManage.h"
#include "../LobbyNetwork/WsSvcManage.h"

FW_NS_USEING;


static DataHandle * _DataHandle = nullptr;

DataHandle::DataHandle()
	:_mysqlPort(0)
	, _redisPort(0)
	, _redisSelectIndex(0)
{
	_DataHandle = this;
}

DataHandle::~DataHandle()
{
	this->Stop();
	_DataHandle = nullptr;
}

DataHandle * DataHandle::GetInstance()
{
	return _DataHandle;
}

void DataHandle::InitMySQLConnectConfig(const std::string & host, unsigned int port, const std::string & username, const std::string & password, const std::string & database)
{
	_mysqlHost = host; _mysqlPort = port; _mysqlUsername = username; _mysqlPassword = password; _mysqlDatabase = database;
}

void DataHandle::InitRedisConnectConfig(const std::string & host, int port, const std::string & password, int selectIndex)
{
	_redisHost = host; _redisPort = port; _redisPassword = password; _redisSelectIndex = selectIndex;
}

void * DataHandle::_onCreateThread(const char * threadID)
{
	DataManipulation * dataManipulation = new DataManipulation();
	dataManipulation->GetMySQLHelper()->Init(_mysqlHost.c_str(), _mysqlUsername.c_str(), _mysqlPassword.c_str(), _mysqlDatabase.c_str(), _mysqlPort, 0, "utf8mb4", 7, 20, 20);
	if (dataManipulation->GetMySQLHelper()->Connect())
	{
		FW_PRINT("%s%s%s", "MySQL数据库连接成功，在处理线程：", threadID, "中");
	}
	else
	{
		FW_LOG_ERROR("%s%s%s", "MySQL数据库初始连接失败，在处理线程：", threadID, "中");
	}
	dataManipulation->GetRedisHelper()->Init(_redisHost.c_str(), _redisPort, _redisPassword.c_str(), _redisSelectIndex, 7, 20);
	if (dataManipulation->GetRedisHelper()->Connect())
	{
		FW_PRINT("%s%s%s", "Redis连接成功，在处理线程：", threadID, "中");
	}
	else
	{
		FW_LOG_ERROR("%s%s%s", "Redis初始连接失败，在处理线程：", threadID, "中");
	}
	return dataManipulation;
}

void DataHandle::_onDeleteThread(const char * threadID, void * customArg)
{
	if (customArg)
	{
		DataManipulation * dataManipulation = (DataManipulation*)customArg;
		dataManipulation->GetMySQLHelper()->Disconnect();
		FW_PRINT("%s%s%s", "关闭MySQL数据库连接，在处理线程：", threadID, "中");
		dataManipulation->GetRedisHelper()->Disconnect();
		FW_PRINT("%s%s%s", "关闭Redis连接，在处理线程：", threadID, "中");
		delete dataManipulation;
	}
}

void DataHandle::_deleteLogicData(FWLogicDataBase * dataBase)
{
	delete dataBase;
}

void DataHandle::_onLogicDataHandler(FWLogicDataBase * dataBase, const char * threadID, void * customArg)
{
	if (!customArg)
	{
		return;
	}
	DataManipulation * dataManipulation = (DataManipulation*)customArg;
	FWLogicDataGeneral * logicDataGeneral = dynamic_cast<FWLogicDataGeneral*>(dataBase);
	if (!logicDataGeneral)
	{
		return;
	}
	switch ((DataHandleType)logicDataGeneral->PopFrontValue<int>())
	{
	case DATA_H_CLIENT_REQUEST:
	{
		const int mainID = logicDataGeneral->PopFrontValue<int>();
		const int assistantID = logicDataGeneral->PopFrontValue<int>();
		SvcNetMatch svcNetMatch = logicDataGeneral->PopFrontValue<SvcNetMatch>();
		FWSvcSocketInfo svcSocketInfo = logicDataGeneral->PopFrontValue<FWSvcSocketInfo>();
		long long r = this->_clientMsgDispense(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
		if (r == -1)
		{
			CloseSvcSocket(svcNetMatch);
		}
		else if (r > 0)
		{
			long long invl = (r < DELAY_CLOSE_SOCKET_TIME_MAX) ? (r) : (DELAY_CLOSE_SOCKET_TIME_MAX);
			LobbyMain::GetInstance()->GetSchedule()->Add([svcNetMatch](long long invl, Framework::FW_ID id)->void {
				CloseSvcSocket(svcNetMatch);
			}, invl, 1, true);
		}
	}
		break;
	case DATA_H_CENTER_REQUEST:
	{
		if (!this->_centerMsgDispense(dataManipulation, logicDataGeneral))
		{
			TcpOutManage::GetInstance()->CloseCenter();
		}
	}
		break;
	case DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1:
	{
		if (dataManipulation->ResetRedisScriptSha1Manage(LobbyMain::GetInstance()->GetRedisScriptSha1Manage()))
		{
			FW_PRINT("%s", "Redis脚本sha1载入成功");
		}
		else
		{
			FW_LOG_ERROR("%s", "Redis脚本sha1载入失败");
		}
	}
		break;
	case DATA_H_INSIDE_INIT_DATABASE_REDIS_DATA:
	{
		if (dataManipulation->ResetLobbyServerInfoToRedis(LobbyMain::GetInstance()->GetLobbyID()))
		{
			FW_PRINT("%s", "重置服务器信息到Redis成功");
		}
		else 
		{
			FW_LOG_ERROR("%s", "重置服务器信息到Redis失败");
		}
	}
		break;
	case DATA_H_INSIDE_WRITE_CONNECTED_COUNT:
	{
		dataManipulation->UpdateLobbyServerConnectedCountToRedis(LobbyMain::GetInstance()->GetLobbyID(), GetSvcConnectedCount());
	}
		break;
	case DATA_H_INSIDE_CLIENT_SOCKET_CLOSE:
	{
		SvcNetMatch svcNetMatch = logicDataGeneral->PopFrontValue<SvcNetMatch>();
		PlayerBindInfo playerBindInfo;
		if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(svcNetMatch);
			dataManipulation->ResetSinglePlayerLobbyServerIDToMySQL(playerBindInfo.PlayerID, LobbyMain::GetInstance()->GetLobbyID());
		}
	}
		break;
	default:
		break;
	}
}

long long DataHandle::_clientMsgDispense(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	switch (mainID)
	{
	case Message::Common::MSG_MAIN_TEST:
	{
		return this->_clientTest(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
	}
		break;
	case Message::Lobby::MSG_MAIN_LOGIN:
	{
		return this->_clientLogin(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
	}
		break;
	case Message::Lobby::MSG_MAIN_REQUEST_PLAYERINFO:
	{
		return this->_clientRequestPlayerInfo(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
	}
		break;
	case Message::Lobby::MSG_MAIN_MATCH:
	{
		return this->_clientMatch(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
	}
		break;
	default:
		return -1;
		break;
	}
}

long long DataHandle::_clientTest(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Common::MSG_ASS_TEST_PROBE)
	{
		Message::Common::ProbeRes probeRes;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &probeRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}

	return -1;
}

long long DataHandle::_clientLogin(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Lobby::MSG_ASS_LOGIN_ACCOUNT)
	{
		if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, nullptr))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_LOGIN_REPEAT, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const char * account = logicDataGeneral->PopFrontString();
		const char * password = logicDataGeneral->PopFrontString();
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "CALL login_account('%s', '%s', %d, %d, %u, %lld);", account, password, LobbyMain::GetInstance()->GetLobbyID(), svcNetMatch.Type, svcNetMatch.NetMatch.Index, svcNetMatch.NetMatch.ActivityID);
		FWMySQLQR mySQLQR;
		FWMySQLExeRet mySQLExeRet = dataManipulation->GetMySQLHelper()->Execute(sqlBuf, &mySQLQR, 1);
		if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
		if (!qrr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const char * playerIDStr = qrr->GetColumnValue("playerID");
		const char * dynaPwd = qrr->GetColumnValue("dynaPwd");
		const char * logicalServerIDStr = qrr->GetColumnValue("logicalServerID");
		const char * last_lobbyServerIDStr = qrr->GetColumnValue("last_lobbyServerID");
		const char * last_lobbyServerNetTypeStr = qrr->GetColumnValue("last_lobbyServerNetType");
		const char * last_lobbyServerNetIndexStr = qrr->GetColumnValue("last_lobbyServerNetIndex");
		const char * last_lobbyServerNetActivityIDStr = qrr->GetColumnValue("last_lobbyServerNetActivityID");
		if (!playerIDStr || !dynaPwd || !logicalServerIDStr || !last_lobbyServerIDStr || !last_lobbyServerNetTypeStr || !last_lobbyServerNetIndexStr || !last_lobbyServerNetActivityIDStr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Lobby::ERR_LOGIN_BAD1, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		PlayerID_t playerID = atoll(playerIDStr);
		int lastLobbyID = atoi(last_lobbyServerIDStr);
		if (lastLobbyID > 0)
		{
			if (LobbyMain::GetInstance()->GetLobbyID() == lastLobbyID)
			{
				PlayerBindInfo lastPlayerBindInfo;
				if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(playerID, &lastPlayerBindInfo))
				{
					Message::Lobby::NotifyForceOfflineRes notifyForceOfflineRes;
					notifyForceOfflineRes.PlayerID = playerID;
					notifyForceOfflineRes.Type = Message::FOT_REPEAT_LOGIN;
					Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_NOTIFY, Message::Lobby::MSG_ASS_NOTIFY_FORCE_OFFLINE, &notifyForceOfflineRes);
					SendDataSvcSocket(lastPlayerBindInfo.SvcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
					LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(lastPlayerBindInfo.SvcNetMatch);
					LobbyMain::GetInstance()->GetSchedule()->Add([lastPlayerBindInfo](long long invl, Framework::FW_ID id)->void {
						CloseSvcSocket(lastPlayerBindInfo.SvcNetMatch);
					}, DELAY_CLOSE_SOCKET_TIME_FOR_SENT, 1, true);
				}
			}
			else
			{
				int lastNetType = atoi(last_lobbyServerNetTypeStr);
				unsigned int lastNetIndex = (unsigned int)atoll(last_lobbyServerNetIndexStr);
				FW_NET_ACTIVITY_ID lastNetActivityID = _atoi64(last_lobbyServerNetActivityIDStr);
				Message::Center::ForwardClosePlayerSocketReq forwardClosePlayerSocketReq;
				forwardClosePlayerSocketReq.Type = Message::FOT_REPEAT_LOGIN;
				forwardClosePlayerSocketReq.TargetServerID = lastLobbyID;
				forwardClosePlayerSocketReq.PlayerID = playerID;
				forwardClosePlayerSocketReq.NetType = lastNetType;
				forwardClosePlayerSocketReq.NetIndex = lastNetIndex;
				forwardClosePlayerSocketReq.NetActivityID = lastNetActivityID;
				Message::MsgPackageSend msgPackageSend(Message::Center::MSG_MAIN_FORWARD, Message::Center::MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET, &forwardClosePlayerSocketReq);
				TcpOutManage::GetInstance()->SendDataCenter(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			}
		}
		int logicalServerID = atoi(logicalServerIDStr);
		Message::Lobby::LoginRes loginRes;
		loginRes.PlayerID = playerID;
		loginRes.DynaPwd = dynaPwd;
		loginRes.LobbyServerID = LobbyMain::GetInstance()->GetLobbyID();
		if (logicalServerID > 0)
		{
			LogicalServerRedisInfo logicalServerRedisInfo;
			int r = dataManipulation->GetLogicalServerRedisInfo(logicalServerID, &logicalServerRedisInfo);
			if (r == 0)
			{
				if (logicalServerRedisInfo.Active != 0)
				{
					loginRes.LogicalServerID = logicalServerID;
					loginRes.LogicalAddr = logicalServerRedisInfo.Address.C_Str();
					loginRes.LogicalTcpPort = logicalServerRedisInfo.TcpPort;
					loginRes.LogicalWsPort = logicalServerRedisInfo.WsPort;
				}
				else
				{
					dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerID, logicalServerID, true);
				}
			}
			else if (r == -1)
			{
				dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerID, logicalServerID, true);
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return 0;
			}
		}
		PlayerBindInfo playerBindInfo;
		playerBindInfo.SvcNetMatch = svcNetMatch;
		playerBindInfo.PlayerID = playerID;
		if (!LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Add(playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_UNKNOWN, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &loginRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}
	else if (assistantID == Message::Lobby::MSG_ASS_LOGIN_UNIONID)
	{
		if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, nullptr))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_LOGIN_REPEAT, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const char * unionid = logicDataGeneral->PopFrontString();
		char sha256[FW_SHA256_STRBUF_LENGTH];
		FWSHA256_STRING(unionid, strlen(unionid), sha256);
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "CALL login_account_unionid('%s','%s', %d, %d, %u, %lld);", sha256, unionid, LobbyMain::GetInstance()->GetLobbyID(), svcNetMatch.Type, svcNetMatch.NetMatch.Index, svcNetMatch.NetMatch.ActivityID);
		FWMySQLQR mySQLQR;
		FWMySQLExeRet mySQLExeRet = dataManipulation->GetMySQLHelper()->Execute(sqlBuf, &mySQLQR, 1);
		if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
		if (!qrr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const char * playerIDStr = qrr->GetColumnValue("playerID");
		const char * dynaPwd = qrr->GetColumnValue("dynaPwd");
		const char * logicalServerIDStr = qrr->GetColumnValue("logicalServerID");
		const char * last_lobbyServerIDStr = qrr->GetColumnValue("last_lobbyServerID");
		const char * last_lobbyServerNetTypeStr = qrr->GetColumnValue("last_lobbyServerNetType");
		const char * last_lobbyServerNetIndexStr = qrr->GetColumnValue("last_lobbyServerNetIndex");
		const char * last_lobbyServerNetActivityIDStr = qrr->GetColumnValue("last_lobbyServerNetActivityID");
		if (!playerIDStr || !dynaPwd || !logicalServerIDStr || !last_lobbyServerIDStr || !last_lobbyServerNetTypeStr || !last_lobbyServerNetIndexStr || !last_lobbyServerNetActivityIDStr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Lobby::ERR_LOGIN_BAD2, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		PlayerID_t playerID = atoll(playerIDStr);
		int lastLobbyID = atoi(last_lobbyServerIDStr);
		if (lastLobbyID > 0)
		{
			if (LobbyMain::GetInstance()->GetLobbyID() == lastLobbyID)
			{
				PlayerBindInfo lastPlayerBindInfo;
				if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(playerID, &lastPlayerBindInfo))
				{
					Message::Lobby::NotifyForceOfflineRes notifyForceOfflineRes;
					notifyForceOfflineRes.PlayerID = playerID;
					notifyForceOfflineRes.Type = Message::FOT_REPEAT_LOGIN;
					Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_NOTIFY, Message::Lobby::MSG_ASS_NOTIFY_FORCE_OFFLINE, &notifyForceOfflineRes);
					SendDataSvcSocket(lastPlayerBindInfo.SvcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
					LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(lastPlayerBindInfo.SvcNetMatch);
					LobbyMain::GetInstance()->GetSchedule()->Add([lastPlayerBindInfo](long long invl, Framework::FW_ID id)->void {
						CloseSvcSocket(lastPlayerBindInfo.SvcNetMatch);
					}, DELAY_CLOSE_SOCKET_TIME_FOR_SENT, 1, true);
				}
			}
			else
			{
				int lastNetType = atoi(last_lobbyServerNetTypeStr);
				unsigned int lastNetIndex = (unsigned int)atoll(last_lobbyServerNetIndexStr);
				FW_NET_ACTIVITY_ID lastNetActivityID = _atoi64(last_lobbyServerNetActivityIDStr);
				Message::Center::ForwardClosePlayerSocketReq forwardClosePlayerSocketReq;
				forwardClosePlayerSocketReq.Type = Message::FOT_REPEAT_LOGIN;
				forwardClosePlayerSocketReq.TargetServerID = lastLobbyID;
				forwardClosePlayerSocketReq.PlayerID = playerID;
				forwardClosePlayerSocketReq.NetType = lastNetType;
				forwardClosePlayerSocketReq.NetIndex = lastNetIndex;
				forwardClosePlayerSocketReq.NetActivityID = lastNetActivityID;
				Message::MsgPackageSend msgPackageSend(Message::Center::MSG_MAIN_FORWARD, Message::Center::MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET, &forwardClosePlayerSocketReq);
				TcpOutManage::GetInstance()->SendDataCenter(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			}
		}
		int logicalServerID = atoi(logicalServerIDStr);
		Message::Lobby::LoginRes loginRes;
		loginRes.PlayerID = playerID;
		loginRes.DynaPwd = dynaPwd;
		loginRes.LobbyServerID = LobbyMain::GetInstance()->GetLobbyID();
		if (logicalServerID > 0)
		{
			LogicalServerRedisInfo logicalServerRedisInfo;
			int r = dataManipulation->GetLogicalServerRedisInfo(logicalServerID, &logicalServerRedisInfo);
			if (r == 0)
			{
				if (logicalServerRedisInfo.Active != 0)
				{
					loginRes.LogicalServerID = logicalServerID;
					loginRes.LogicalAddr = logicalServerRedisInfo.Address.C_Str();
					loginRes.LogicalTcpPort = logicalServerRedisInfo.TcpPort;
					loginRes.LogicalWsPort = logicalServerRedisInfo.WsPort;
				}
				else
				{
					dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerID, logicalServerID, true);
				}
			}
			else if (r == -1)
			{
				dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerID, logicalServerID, true);
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return 0;
			}
		}
		PlayerBindInfo playerBindInfo;
		playerBindInfo.SvcNetMatch = svcNetMatch;
		playerBindInfo.PlayerID = playerID;
		if (!LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Add(playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_UNKNOWN, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &loginRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}

	return -1;
}

long long DataHandle::_clientRequestPlayerInfo(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Lobby::MSG_ASS_REQUEST_PLAYERINFO_WITH_PLAYERID)
	{
		PlayerID_t playerID = logicDataGeneral->PopFrontValue<PlayerID_t>();
		PlayerBindInfo playerBindInfo;
		if (!LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_NOT_LOGGED, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		PlayerInfo playerInfo;
		int r = dataManipulation->GetPlayerInfo(playerID, &playerInfo);
		if (r != 0)
		{
			if (r == -1)
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Lobby::ERR_QUERY_NOT_FOUND_PLAYER_INFO, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return 0;
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return 0;
			}
		}
		Message::Lobby::PlayerInfoRes playerInfoRes;
		playerInfoRes.PlayerID = playerID;
		playerInfoRes.Nickname = playerInfo.Nickname.C_Str();
		playerInfoRes.Sex = playerInfo.Sex;
		if (playerID == playerBindInfo.PlayerID)
		{
			playerInfoRes.Golds = playerInfo.Golds;
			playerInfoRes.Diamonds = playerInfo.Diamonds;
		}
		playerInfoRes.LobbyServerID = playerInfo.LobbyServerID;
		playerInfoRes.LogicalServerID = playerInfo.LogicalServerID;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &playerInfoRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}

	return -1;
}

long long DataHandle::_clientMatch(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Lobby::MSG_ASS_MATCH_REQ_ADD_SVR)
	{
		PlayerBindInfo playerBindInfo;
		if (!LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_NOT_LOGGED, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "SELECT `logicalServerID` FROM `player_info` WHERE `playerID` = %lld;", playerBindInfo.PlayerID);
		FWMySQLQR mySQLQR;
		FWMySQLExeRet mySQLExeRet = dataManipulation->GetMySQLHelper()->Execute(sqlBuf, &mySQLQR, 1);
		if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
		if (!qrr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const char * logicalServerIDStr = qrr->GetColumnValue("logicalServerID");
		if (!logicalServerIDStr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		int logicalServerID = atoi(logicalServerIDStr);
		if (logicalServerID > 0)
		{
			LogicalServerRedisInfo logicalServerRedisInfo;
			int r = dataManipulation->GetLogicalServerRedisInfo(logicalServerID, &logicalServerRedisInfo);
			if (r == 0)
			{
				if (logicalServerRedisInfo.Active != 0)
				{
					Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Lobby::ERR_MATCH_ALREADY_PLAYING, nullptr);
					//Message::Lobby::MatchRes matchRes;
					//matchRes.LogicalServerID = logicalServerID;
					//matchRes.LogicalAddr = logicalServerRedisInfo.Address.C_Str();
					//matchRes.LogicalTcpPort = logicalServerRedisInfo.TcpPort;
					//matchRes.LogicalWsPort = logicalServerRedisInfo.WsPort;
					//Message::MsgPackageSend msgPackageSend(mainID, assistantID, &matchRes);
					SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
					return 0;
				}
				else
				{
					dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerBindInfo.PlayerID, logicalServerID, true);
				}
			}
			else if (r == -1)
			{
				dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerBindInfo.PlayerID, logicalServerID, true);
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return 0;
			}
		}
		LogicalServerSelectionInfo logicalServerSelectionInfo;
		int r = dataManipulation->SelectionLogicalService(LobbyMain::GetInstance()->GetRedisScriptSha1Manage(), &logicalServerSelectionInfo);
		if (r != 0)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		Message::Lobby::MatchRes matchRes;
		matchRes.LogicalServerID = logicalServerSelectionInfo.LogicalServerID;
		matchRes.LogicalAddr = logicalServerSelectionInfo.Address.C_Str();
		matchRes.LogicalTcpPort = logicalServerSelectionInfo.TcpPort;
		matchRes.LogicalWsPort = logicalServerSelectionInfo.WsPort;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &matchRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}

	return -1;
}

bool DataHandle::_centerMsgDispense(DataManipulation * dataManipulation, FWLogicDataGeneral * logicDataGeneral)
{
	const int mainID = logicDataGeneral->PopFrontValue<int>();
	const int assistantID = logicDataGeneral->PopFrontValue<int>();
	switch (mainID)
	{
	case Message::Center::MSG_MAIN_FORWARD:
	{
		return this->_centerForward(dataManipulation, mainID, assistantID, logicDataGeneral);
	}
		break;
	default:
		return false;
		break;
	}
}

bool DataHandle::_centerForward(DataManipulation * dataManipulation, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Center::MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET)
	{
		int	type = logicDataGeneral->PopFrontValue<int>();
		PlayerID_t	playerID = logicDataGeneral->PopFrontValue<PlayerID_t>();
		int netType = logicDataGeneral->PopFrontValue<int>();
		unsigned int netIndex = logicDataGeneral->PopFrontValue<unsigned int>();
		long long netActivityID = logicDataGeneral->PopFrontValue<long long>();
		PlayerBindInfo playerBindInfo;
		if (LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(playerID, &playerBindInfo))
		{
			if (playerBindInfo.SvcNetMatch.Type == netType && playerBindInfo.SvcNetMatch.NetMatch.Index == netIndex && playerBindInfo.SvcNetMatch.NetMatch.ActivityID == netActivityID)
			{
				if (type == Message::FOT_REPEAT_LOGIN)
				{
					Message::Lobby::NotifyForceOfflineRes notifyForceOfflineRes;
					notifyForceOfflineRes.PlayerID = playerID;
					notifyForceOfflineRes.Type = Message::FOT_REPEAT_LOGIN;
					Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_NOTIFY, Message::Lobby::MSG_ASS_NOTIFY_FORCE_OFFLINE, &notifyForceOfflineRes);
					SendDataSvcSocket(playerBindInfo.SvcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
					LobbyMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(playerID);
					LobbyMain::GetInstance()->GetSchedule()->Add([playerBindInfo](long long invl, Framework::FW_ID id)->void {
						CloseSvcSocket(playerBindInfo.SvcNetMatch);
					}, DELAY_CLOSE_SOCKET_TIME_FOR_SENT, 1, true);
				}
			}
		}
		return true;
	}

	return false;
}