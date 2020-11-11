#pragma once
#include "Local.h"
#include "TypeDefine.h"

class ServerInfoManage
{
public:
	ServerInfoManage();
	~ServerInfoManage();

public:
	bool AddLobby(const LobbyServerInfo & serverInfo);

	bool FindLobby(const Framework::FWNetMatch & netMatch, LobbyServerInfo * out_serverInfo);
	bool FindLobby(int serverID, LobbyServerInfo * out_serverInfo);

	bool RemoveLobby(const Framework::FWNetMatch & netMatch);
	bool RemoveLobby(int serverID);
	
	void ClearLobby();

public:
	bool AddLogical(const LogicalServerInfo & serverInfo);

	bool FindLogical(const Framework::FWNetMatch & netMatch, LogicalServerInfo * out_serverInfo);
	bool FindLogical(int serverID, LogicalServerInfo * out_serverInfo);

	bool RemoveLogical(const Framework::FWNetMatch & netMatch);
	bool RemoveLogical(int serverID);

	void ClearLogical();

private:
	Framework::FWLockRecursive				_lobbyMapLock;
	std::map<int, LobbyServerInfo>			_lobbyInfoMap;
	std::map<Framework::FWNetMatch, int>	_lobbyIDMap;

private:
	Framework::FWLockRecursive				_logicalMapLock;
	std::map<int, LogicalServerInfo>		_logicalInfoMap;
	std::map<Framework::FWNetMatch, int>	_logicalIDMap;
};