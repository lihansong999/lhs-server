#include "stdafx.h"
#include "DataHandle.h"
#include "QuickHandle.h"
#include "../LogicalMain.h"
#include "../LogicalNetwork/NetworkTools.h"
#include "../LogicalNetwork/TcpOutManage.h"
#include "../LogicalNetwork/TcpSvcManage.h"
#include "../LogicalNetwork/WsSvcManage.h"

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
			LogicalMain::GetInstance()->GetSchedule()->Add([svcNetMatch](long long invl, Framework::FW_ID id)->void {
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
		if (dataManipulation->ResetRedisScriptSha1Manage(LogicalMain::GetInstance()->GetRedisScriptSha1Manage()))
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
		if (dataManipulation->ResetLogicalServerInfoToRedis(LogicalMain::GetInstance()->GetLogicalID()))
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
		dataManipulation->UpdateLogicalServerConnectedCountToRedis(LogicalMain::GetInstance()->GetLogicalID(), GetSvcConnectedCount());
	}
		break;
	case DATA_H_INSIDE_CLIENT_SOCKET_CLOSE:
	{
		SvcNetMatch svcNetMatch = logicDataGeneral->PopFrontValue<SvcNetMatch>();
		PlayerBindInfo playerBindInfo;
		if (LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(svcNetMatch);
			dataManipulation->ResetSinglePlayerLogicalServerInfoToMySQL(playerBindInfo.PlayerID, LogicalMain::GetInstance()->GetLogicalID(), false);
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
	case Message::Logical::MSG_MAIN_LOGIN:
	{
		return this->_clientLogin(dataManipulation, svcNetMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral);
	}
		break;
	case Message::Logical::MSG_MAIN_MATCH:
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
	if (assistantID == Message::Logical::MSG_ASS_LOGIN_DYNAMIC_PASSWORD)
	{
		if (LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, nullptr))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_LOGIN_REPEAT, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		PlayerID_t playerID = logicDataGeneral->PopFrontValue<PlayerID_t>();
		const char * dynaPwd = logicDataGeneral->PopFrontString();
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "CALL login_logical('%lld','%s', %d, %d, %u, %lld);", playerID, dynaPwd, LogicalMain::GetInstance()->GetLogicalID(), svcNetMatch.Type, svcNetMatch.NetMatch.Index, svcNetMatch.NetMatch.ActivityID);
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
		const char * retStr = qrr->GetColumnValue("`ret`");
		if (retStr)
		{
			if (strcmp(retStr, "-4") == 0)
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Logical::ERR_LOGIN_BAD2, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Logical::ERR_LOGIN_BAD1, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			}
			return DELAY_CLOSE_SOCKET_TIME_FOR_SENT;
		}
		const char * last_logicalServerIDStr = qrr->GetColumnValue("last_logicalServerID");
		const char * logicalServerStationIDStr = qrr->GetColumnValue("logicalServerStationID");
		if (!last_logicalServerIDStr || !logicalServerStationIDStr)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_UNKNOWN, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return DELAY_CLOSE_SOCKET_TIME_FOR_SENT;
		}
		int lastlogicalID = atoi(last_logicalServerIDStr);
		if (lastlogicalID > 0)
		{
			if (LogicalMain::GetInstance()->GetLogicalID() == lastlogicalID)
			{
				PlayerBindInfo lastPlayerBindInfo;
				if (LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(playerID, &lastPlayerBindInfo))
				{
					LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Remove(lastPlayerBindInfo.SvcNetMatch);
					CloseSvcSocket(lastPlayerBindInfo.SvcNetMatch);
				}
			}
			else
			{
				Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_UNKNOWN, nullptr);
				SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
				return DELAY_CLOSE_SOCKET_TIME_FOR_SENT;
			}
		}
		PlayerBindInfo playerBindInfo;
		playerBindInfo.SvcNetMatch = svcNetMatch;
		playerBindInfo.PlayerID = playerID;
		if (!LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Add(playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_UNKNOWN, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return DELAY_CLOSE_SOCKET_TIME_FOR_SENT;
		}
		int logicalServerStationID = atoi(logicalServerStationIDStr);
		Message::Logical::LoginRes loginRes;
		loginRes.LogicalServerStationID = logicalServerStationID;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &loginRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		if (logicalServerStationID > 0)
		{
			//已在比赛站中，直接推加入消息
			Message::Logical::AddMatchRes addMatchRes;
			addMatchRes.LogicalServerStationID = logicalServerStationID;
			Message::MsgPackageSend msgPackageSend(Message::Logical::MSG_MAIN_MATCH, Message::Logical::MSG_ASS_MATCH_REQ_ADD, &addMatchRes);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
		return 0;
	}

	return -1;
}

long long DataHandle::_clientMatch(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	if (assistantID == Message::Logical::MSG_ASS_MATCH_REQ_ADD)
	{
		PlayerBindInfo playerBindInfo;
		if (!LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_NOT_LOGGED, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		const int newLogicalServerStationID = 1; //临时写死比赛站ID
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "UPDATE `player_info` SET `logicalServerStationID` = %d WHERE `playerID` = %lld AND `logicalServerID` = %d AND `logicalServerStationID` = 0;", newLogicalServerStationID, playerBindInfo.PlayerID, LogicalMain::GetInstance()->GetLogicalID());
		FWMySQLQR mySQLQR;
		FWMySQLExeRet mySQLExeRet = dataManipulation->GetMySQLHelper()->Execute(sqlBuf, &mySQLQR, 1);
		if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		if (mySQLQR.GetAffectedRows() != 1)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Logical::ERR_MATCH_ADD_BAD1, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		Message::Logical::AddMatchRes addMatchRes;
		addMatchRes.LogicalServerStationID = newLogicalServerStationID;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &addMatchRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}
	else if (assistantID == Message::Logical::MSG_ASS_MATCH_REQ_QUIT)
	{
		PlayerBindInfo playerBindInfo;
		if (!LogicalMain::GetInstance()->GetOnlinePlayerBindInfoManage()->Find(svcNetMatch, &playerBindInfo))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_NOT_LOGGED, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		char sqlBuf[256];
		sprintf_s(sqlBuf, sizeof(sqlBuf), "UPDATE `player_info` SET `logicalServerStationID` = 0 WHERE `playerID` = %lld AND `logicalServerID` = %d AND `logicalServerStationID` > 0;", playerBindInfo.PlayerID, LogicalMain::GetInstance()->GetLogicalID());
		FWMySQLQR mySQLQR;
		FWMySQLExeRet mySQLExeRet = dataManipulation->GetMySQLHelper()->Execute(sqlBuf, &mySQLQR, 1);
		if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Common::ERR_SERVER_BUSY, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		if (mySQLQR.GetAffectedRows() != 1)
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Logical::ERR_MATCH_QUIT_BAD1, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return 0;
		}
		Message::Logical::QuitMatchRes quitMatchRes;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &quitMatchRes);
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
	default:
		return false;
		break;
	}
}