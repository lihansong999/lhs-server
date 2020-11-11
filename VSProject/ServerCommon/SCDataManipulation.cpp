#include "SCDataManipulation.h"
#include "SCTools.h"

SC_NS_BEGIN

FW_NS_USEING;


DataManipulation::DataManipulation()
{

}

DataManipulation::~DataManipulation()
{

}

RedisHelper * DataManipulation::GetRedisHelper()
{
	return &_redisHelper;
}

MySQLHelper * DataManipulation::GetMySQLHelper()
{
	return &_mySQLHelper;
}

bool DataManipulation::LoadRedisScriptSha1ToMySQL(const char * scriptName, const char * scriptContent)
{
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, "SCRIPT LOAD %s", scriptContent);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() != FWRedisCR::REDIS_CR_TYPE_STRING)
	{
		return false;
	}
	std::string sha1 = redisCR.GetString();
	if (sha1.size() != 40)
	{
		return false;
	}
	char sqlBuf[256];
	sprintf_s(sqlBuf, sizeof(sqlBuf), "REPLACE INTO `redis_script_info`(`filename`, `sha1`) VALUES('%s', '%s')", scriptName, sha1.c_str());
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
	{
		return false;
	}
	return true;
}

bool DataManipulation::ResetRedisScriptSha1Manage(RedisScriptSha1Manage * redisScriptSha1Manage)
{
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute("SELECT `filename`, `sha1` FROM `redis_script_info`", &mySQLQR, 1);
	if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
	{
		return false;
	}
	std::vector<const char*> filenameVector;
	std::vector<const char*> sha1Vector;
	for (size_t i = 0; i < mySQLQR.Size(); i++)
	{
		const FWMySQLQRRow * qrr = mySQLQR.GetRow(i);
		const char * filename = qrr->GetColumnValue("filename");
		const char * sha1 = qrr->GetColumnValue("sha1");
		if (!filename || filename[0] == '\0' || !sha1 || sha1[0] == '\0')
		{
			return false;
		}
		filenameVector.push_back(filename);
		sha1Vector.push_back(sha1);
	}
	if (filenameVector.size() == 0)
	{
		return true;
	}
	return redisScriptSha1Manage->Reset(&(filenameVector[0]), &(sha1Vector[0]), (int)filenameVector.size());
}

int DataManipulation::SelectionLobbyService(RedisScriptSha1Manage * redisScriptSha1Manage, LobbyServerSelectionInfo * out_lobbyServerSelectionInfo)
{
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, "EVALSHA %s %d", redisScriptSha1Manage->Find("SelectionLobbyService.lua").C_Str(), 0);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return -2;
	}
	if (redisCR.GetArrayCount() != 4)
	{
		return -1;
	}
	if (out_lobbyServerSelectionInfo)
	{
		(*out_lobbyServerSelectionInfo).Address = redisCR.GetArrayElement(0)->GetString();
		(*out_lobbyServerSelectionInfo).TcpPort = atoi(redisCR.GetArrayElement(1)->GetString());
		(*out_lobbyServerSelectionInfo).WsPort = atoi(redisCR.GetArrayElement(2)->GetString());
		(*out_lobbyServerSelectionInfo).LobbyServerID = atoi(redisCR.GetArrayElement(3)->GetString());
	}
	return 0;
}

int DataManipulation::SelectionLogicalService(RedisScriptSha1Manage * redisScriptSha1Manage, LogicalServerSelectionInfo * out_logicalServerSelectionInfo)
{
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, "EVALSHA %s %d", redisScriptSha1Manage->Find("SelectionLogicalService.lua").C_Str(), 0);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return -2;
	}
	if (redisCR.GetArrayCount() != 4)
	{
		return -1;
	}
	if (out_logicalServerSelectionInfo)
	{
		(*out_logicalServerSelectionInfo).Address = redisCR.GetArrayElement(0)->GetString();
		(*out_logicalServerSelectionInfo).TcpPort = atoi(redisCR.GetArrayElement(1)->GetString());
		(*out_logicalServerSelectionInfo).WsPort = atoi(redisCR.GetArrayElement(2)->GetString());
		(*out_logicalServerSelectionInfo).LogicalServerID = atoi(redisCR.GetArrayElement(3)->GetString());
	}
	return 0;
}

bool DataManipulation::ResetLobbyServerInfoToRedis(int lobbyServerID)
{
	char sqlBuf[256];
	sprintf_s(sqlBuf, sizeof(sqlBuf), "SELECT `address`, `tcpPort`, `wsPort`, `testAddress`, `tcpTestPort`, `wsTestPort` FROM `lobby_server_info` WHERE lobbyID = %d;", lobbyServerID);
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
	{
		return false;
	}
	const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
	if (!qrr)
	{
		return false;
	}
	const char * address = qrr->GetColumnValue("address");
	const char * tcpPortStr = qrr->GetColumnValue("tcpPort");
	const char * wsPortStr = qrr->GetColumnValue("wsPort");
	const char * testAddress = qrr->GetColumnValue("testAddress");
	const char * tcpTestPortStr = qrr->GetColumnValue("tcpTestPort");
	const char * wsTestPortStr = qrr->GetColumnValue("wsTestPort");
	if (!address || !tcpPortStr || !wsPortStr || !testAddress || !tcpTestPortStr || !wsTestPortStr)
	{
		return false;
	}
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, "SADD %s %d", RKN_LOBBY_SERVER_ID_SET, lobbyServerID);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return false;
	}
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HMSET %s%d %s", RKN_LOBBY_SERVER_INFO_HASH, lobbyServerID, "address %s tcpPort %s wsPort %s testAddress %s tcpTestPort %s wsTestPort %s active %d connectedCount %d enableInvolveBalance %d");
	redisCmdRet = _redisHelper.Command(&redisCR, cmdBuf, address, tcpPortStr, wsPortStr, testAddress, tcpTestPortStr, wsTestPortStr, 1, 0, 1);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return false;
	}
	return true;
}

bool DataManipulation::ResetLogicalServerInfoToRedis(int logicalServerID)
{
	char sqlBuf[256];
	sprintf_s(sqlBuf, sizeof(sqlBuf), "SELECT `address`, `tcpPort`, `wsPort`, `testAddress`, `tcpTestPort`, `wsTestPort` FROM `logical_server_info` WHERE logicalID = %d;", logicalServerID);
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
	{
		return false;
	}
	const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
	if (!qrr)
	{
		return false;
	}
	const char * address = qrr->GetColumnValue("address");
	const char * tcpPortStr = qrr->GetColumnValue("tcpPort");
	const char * wsPortStr = qrr->GetColumnValue("wsPort");
	const char * testAddress = qrr->GetColumnValue("testAddress");
	const char * tcpTestPortStr = qrr->GetColumnValue("tcpTestPort");
	const char * wsTestPortStr = qrr->GetColumnValue("wsTestPort");
	if (!address || !tcpPortStr || !wsPortStr || !testAddress || !tcpTestPortStr || !wsTestPortStr)
	{
		return false;
	}
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, "SADD %s %d", RKN_LOGICAL_SERVER_ID_SET, logicalServerID);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return false;
	}
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HMSET %s%d %s", RKN_LOGICAL_SERVER_INFO_HASH, logicalServerID, "address %s tcpPort %s wsPort %s testAddress %s tcpTestPort %s wsTestPort %s active %d connectedCount %d enableInvolveBalance %d");
	redisCmdRet = _redisHelper.Command(&redisCR, cmdBuf, address, tcpPortStr, wsPortStr, testAddress, tcpTestPortStr, wsTestPortStr, 1, 0, 1);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return false;
	}
	return true;
}

void DataManipulation::UpdateLobbyServerConnectedCountToRedis(int lobbyServerID, int connectedCount)
{
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HSET %s%d %s", RKN_LOBBY_SERVER_INFO_HASH, lobbyServerID, "connectedCount %d");
	_redisHelper.Command(nullptr, cmdBuf, connectedCount);
}

void DataManipulation::UpdateLogicalServerConnectedCountToRedis(int logicalServerID, int connectedCount)
{
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HSET %s%d %s", RKN_LOGICAL_SERVER_INFO_HASH, logicalServerID, "connectedCount %d");
	_redisHelper.Command(nullptr, cmdBuf, connectedCount);
}

int DataManipulation::GetLobbyServerRedisInfo(int lobbyServerID, LobbyServerRedisInfo * out_lobbyServerRedisInfo)
{
	const int AttrCount = 9;
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HMGET %s%d %s", RKN_LOBBY_SERVER_INFO_HASH, lobbyServerID, "%s %s %s %s %s %s %s %s %s");
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, cmdBuf, "address", "tcpPort", "wsPort", "testAddress", "tcpTestPort", "wsTestPort", "active", "connectedCount", "enableInvolveBalance");
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return -2;
	}
	if (redisCR.GetArrayCount() != AttrCount)
	{
		return -1;
	}
	for (int i = 0; i < AttrCount; i++)
	{
		if (!redisCR.GetArrayElement(i)->GetString())
			return -1;
	}
	if (out_lobbyServerRedisInfo)
	{
		(*out_lobbyServerRedisInfo).Address = redisCR.GetArrayElement(0)->GetString();
		(*out_lobbyServerRedisInfo).TcpPort = atoi(redisCR.GetArrayElement(1)->GetString());
		(*out_lobbyServerRedisInfo).WsPort = atoi(redisCR.GetArrayElement(2)->GetString());
		(*out_lobbyServerRedisInfo).TestAddress = redisCR.GetArrayElement(3)->GetString();
		(*out_lobbyServerRedisInfo).TcpTestPort = atoi(redisCR.GetArrayElement(4)->GetString());
		(*out_lobbyServerRedisInfo).WsTestPort = atoi(redisCR.GetArrayElement(5)->GetString());
		(*out_lobbyServerRedisInfo).Active = atoi(redisCR.GetArrayElement(6)->GetString());
		(*out_lobbyServerRedisInfo).ConnectedCount = atoi(redisCR.GetArrayElement(7)->GetString());
		(*out_lobbyServerRedisInfo).EnableInvolveBalance = atoi(redisCR.GetArrayElement(8)->GetString());
	}
	return 0;
}

int DataManipulation::GetLogicalServerRedisInfo(int logicalServerID, LogicalServerRedisInfo * out_logicalServerRedisInfo)
{
	const int AttrCount = 9;
	char cmdBuf[256];
	sprintf_s(cmdBuf, sizeof(cmdBuf), "HMGET %s%d %s", RKN_LOGICAL_SERVER_INFO_HASH, logicalServerID, "%s %s %s %s %s %s %s %s %s");
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper.Command(&redisCR, cmdBuf, "address", "tcpPort", "wsPort", "testAddress", "tcpTestPort", "wsTestPort", "active", "connectedCount", "enableInvolveBalance");
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return -2;
	}
	if (redisCR.GetArrayCount() != AttrCount)
	{
		return -1;
	}
	for (int i = 0; i < AttrCount; i++)
	{
		if (!redisCR.GetArrayElement(i)->GetString())
			return -1;
	}
	if (out_logicalServerRedisInfo)
	{
		(*out_logicalServerRedisInfo).Address = redisCR.GetArrayElement(0)->GetString();
		(*out_logicalServerRedisInfo).TcpPort = atoi(redisCR.GetArrayElement(1)->GetString());
		(*out_logicalServerRedisInfo).WsPort = atoi(redisCR.GetArrayElement(2)->GetString());
		(*out_logicalServerRedisInfo).TestAddress = redisCR.GetArrayElement(3)->GetString();
		(*out_logicalServerRedisInfo).TcpTestPort = atoi(redisCR.GetArrayElement(4)->GetString());
		(*out_logicalServerRedisInfo).WsTestPort = atoi(redisCR.GetArrayElement(5)->GetString());
		(*out_logicalServerRedisInfo).Active = atoi(redisCR.GetArrayElement(6)->GetString());
		(*out_logicalServerRedisInfo).ConnectedCount = atoi(redisCR.GetArrayElement(7)->GetString());
		(*out_logicalServerRedisInfo).EnableInvolveBalance = atoi(redisCR.GetArrayElement(8)->GetString());
	}
	return 0;
}

bool DataManipulation::ResetSinglePlayerLobbyServerIDToMySQL(PlayerID_t playerID, int matchLobbyServerID)
{
	char sqlBuf[256];
	sprintf_s(sqlBuf, sizeof(sqlBuf), "UPDATE `player_info` SET `lobbyServerID` = 0 WHERE `playerID` = %lld AND `lobbyServerID` = %d;", playerID, matchLobbyServerID);
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	return ((FWMySQLExeRet::ExeRetType)mySQLExeRet) == FWMySQLExeRet::MSQL_EXE_COMPLETED && ((FWMySQLQR::QRRetType)mySQLQR) == FWMySQLQR::MSQL_QR_COMPLETED;
}

bool DataManipulation::ResetSinglePlayerLogicalServerInfoToMySQL(PlayerID_t playerID, int matchLogicalServerID, bool force)
{
	char sqlBuf[256];
	if (force)
	{
		sprintf_s(sqlBuf, sizeof(sqlBuf), "UPDATE `player_info` SET `logicalServerID` = 0, `logicalServerStationID` = 0 WHERE `playerID` = %lld AND `logicalServerID` = %d;", playerID, matchLogicalServerID);
	}
	else 
	{
		sprintf_s(sqlBuf, sizeof(sqlBuf), "UPDATE `player_info` SET `logicalServerID` = 0 WHERE `playerID` = %lld AND `logicalServerID` = %d AND `logicalServerStationID` = 0;", playerID, matchLogicalServerID);
	}
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	return ((FWMySQLExeRet::ExeRetType)mySQLExeRet) == FWMySQLExeRet::MSQL_EXE_COMPLETED && ((FWMySQLQR::QRRetType)mySQLQR) == FWMySQLQR::MSQL_QR_COMPLETED;
}

int DataManipulation::GetPlayerInfo(PlayerID_t playerID, PlayerInfo * out_playerInfo)
{
	if (!out_playerInfo)
	{
		return -2;
	}
	char sqlBuf[512];
	sprintf_s(sqlBuf, sizeof(sqlBuf), "SELECT `nickname`, `sex`, `golds`, `diamonds`, `lobbyServerID`, `lobbyServerNetType`, `lobbyServerNetIndex`, `lobbyServerNetActivityID`, `logicalServerID`, `logicalServerNetType`, `logicalServerNetIndex`, `logicalServerNetActivityID` FROM `player_info` WHERE `playerID` = %lld;", playerID);
	FWMySQLQR mySQLQR;
	FWMySQLExeRet mySQLExeRet = _mySQLHelper.Execute(sqlBuf, &mySQLQR, 1);
	if (((FWMySQLExeRet::ExeRetType)mySQLExeRet) != FWMySQLExeRet::MSQL_EXE_COMPLETED || ((FWMySQLQR::QRRetType)mySQLQR) != FWMySQLQR::MSQL_QR_COMPLETED)
	{
		return -2;
	}
	const FWMySQLQRRow * qrr = mySQLQR.GetRow(0);
	if (!qrr)
	{
		return -1;
	}
	const char * nickname = qrr->GetColumnValue("nickname");
	const char * sexStr = qrr->GetColumnValue("sex");
	const char * goldsStr = qrr->GetColumnValue("golds");
	const char * diamondsStr = qrr->GetColumnValue("diamonds");
	const char * lobbyServerIDStr = qrr->GetColumnValue("lobbyServerID");
	const char * lobbyServerNetTypeStr = qrr->GetColumnValue("lobbyServerNetType");
	const char * lobbyServerNetIndexStr = qrr->GetColumnValue("lobbyServerNetIndex");
	const char * lobbyServerNetActivityIDStr = qrr->GetColumnValue("lobbyServerNetActivityID");
	const char * logicalServerIDStr = qrr->GetColumnValue("logicalServerID");
	const char * logicalServerNetTypeStr = qrr->GetColumnValue("logicalServerNetType");
	const char * logicalServerNetIndexStr = qrr->GetColumnValue("logicalServerNetIndex");
	const char * logicalServerNetActivityIDStr = qrr->GetColumnValue("logicalServerNetActivityID");
	if (!nickname || !sexStr || !goldsStr || !diamondsStr || !lobbyServerIDStr || !lobbyServerNetTypeStr || !lobbyServerNetIndexStr || !lobbyServerNetActivityIDStr || !logicalServerIDStr || !logicalServerNetTypeStr || !logicalServerNetIndexStr || !logicalServerNetActivityIDStr)
	{
		return -2;
	}
	out_playerInfo->PlayerID = playerID;
	FWData nicknameData = FWURIBase64Decode(nickname);
	if (nicknameData.GetSize() > 0)
		out_playerInfo->Nickname.Assign(nicknameData.GetPointer(), nicknameData.GetSize());
	else
		out_playerInfo->Nickname = "";
	out_playerInfo->Sex = atoi(sexStr);
	out_playerInfo->Golds = atoll(goldsStr);
	out_playerInfo->Diamonds = atoll(diamondsStr);
	out_playerInfo->LobbyServerID = atoi(lobbyServerIDStr);
	out_playerInfo->LobbySvcNetMatch.Type = (SvcNetMatchType)atoi(lobbyServerNetTypeStr);
	out_playerInfo->LobbySvcNetMatch.NetMatch.Index = (unsigned int)atoll(lobbyServerNetIndexStr);
	out_playerInfo->LobbySvcNetMatch.NetMatch.ActivityID = atoll(lobbyServerNetActivityIDStr);
	out_playerInfo->LogicalServerID = atoi(logicalServerIDStr);
	out_playerInfo->LogicalSvcNetMatch.Type = (SvcNetMatchType)atoi(logicalServerNetTypeStr);
	out_playerInfo->LogicalSvcNetMatch.NetMatch.Index = (unsigned int)atoll(logicalServerNetIndexStr);
	out_playerInfo->LogicalSvcNetMatch.NetMatch.ActivityID = atoll(logicalServerNetActivityIDStr);
	return 0;
}


SC_NS_END