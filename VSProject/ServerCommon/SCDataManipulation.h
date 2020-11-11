#ifndef __SERVERCOMMON_DATAMANIPULATION_H__
#define __SERVERCOMMON_DATAMANIPULATION_H__

#include "SCLocal.h"
#include "SCTypeDefine.h"
#include "SCMySQLHelper.h"
#include "SCRedisHelper.h"
#include "SCRedisScriptSha1Manage.h"

SC_NS_BEGIN


class SC_DLL DataManipulation
{
public:
	DataManipulation();
	~DataManipulation();

	RedisHelper * GetRedisHelper();

	MySQLHelper * GetMySQLHelper();

public:
	bool LoadRedisScriptSha1ToMySQL(const char * scriptName, const char * scriptContent);

	bool ResetRedisScriptSha1Manage(RedisScriptSha1Manage * redisScriptSha1Manage);

	//return: 0成功, -1没有查询到匹配的服务器信息, -2错误
	int SelectionLobbyService(RedisScriptSha1Manage * redisScriptSha1Manage, LobbyServerSelectionInfo * out_lobbyServerSelectionInfo);

	//return: 0成功, -1没有查询到匹配的服务器信息, -2错误
	int SelectionLogicalService(RedisScriptSha1Manage * redisScriptSha1Manage, LogicalServerSelectionInfo * out_logicalServerSelectionInfo);

	bool ResetLobbyServerInfoToRedis(int lobbyServerID);

	bool ResetLogicalServerInfoToRedis(int logicalServerID);

	void UpdateLobbyServerConnectedCountToRedis(int lobbyServerID, int connectedCount);

	void UpdateLogicalServerConnectedCountToRedis(int logicalServerID, int connectedCount);

	//return: 0成功, -1没有查询到匹配的服务器信息, -2错误
	int GetLobbyServerRedisInfo(int lobbyServerID, LobbyServerRedisInfo * out_lobbyServerRedisInfo);

	//return: 0成功, -1没有查询到匹配的服务器信息, -2错误
	int GetLogicalServerRedisInfo(int logicalServerID, LogicalServerRedisInfo * out_logicalServerRedisInfo);

	bool ResetSinglePlayerLobbyServerIDToMySQL(PlayerID_t playerID, int matchLobbyServerID);

	bool ResetSinglePlayerLogicalServerInfoToMySQL(PlayerID_t playerID, int matchLogicalServerID, bool force);

	//return: 0成功, -1没有查询到匹配的玩家信息, -2错误
	int GetPlayerInfo(PlayerID_t playerID, PlayerInfo * out_playerInfo);

private:
	RedisHelper _redisHelper;
	MySQLHelper _mySQLHelper;
};


SC_NS_END


#endif //!__SERVERCOMMON_DATAMANIPULATION_H__