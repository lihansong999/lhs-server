#include "stdafx.h"
#include "ServerInfoManage.h"
#include "../../CenterServerDlg.h"

FW_NS_USEING;


ServerInfoManage::ServerInfoManage()
{

}

ServerInfoManage::~ServerInfoManage()
{

}

bool ServerInfoManage::AddLobby(const LobbyServerInfo & serverInfo)
{
	FWLockScopeController lsc(&_lobbyMapLock);
	if (serverInfo.ServerID <= 0)
	{
		FW_LOG_ERROR("%s", "serverInfo.ServerID <= 0");
		return false;
	}
	std::map<int, LobbyServerInfo>::iterator it = _lobbyInfoMap.find(serverInfo.ServerID);
	if (it != _lobbyInfoMap.end())
	{
		return false;
	}
	std::pair<std::map<FWNetMatch, int>::iterator, bool> r = _lobbyIDMap.insert(std::pair<FWNetMatch, int>(serverInfo.NetMatch, serverInfo.ServerID));
	if (!r.second)
	{
		return false;
	}
	_lobbyInfoMap.insert(std::pair<int, LobbyServerInfo>(serverInfo.ServerID, serverInfo));

	CCenterServerDlg::AddLobbyServerToList(serverInfo.ServerID);

	return true;
}

bool ServerInfoManage::FindLobby(const FWNetMatch & netMatch, LobbyServerInfo * out_serverInfo)
{
	FWLockScopeController lsc(&_lobbyMapLock);
	std::map<FWNetMatch, int>::iterator it = _lobbyIDMap.find(netMatch);
	if (it != _lobbyIDMap.end())
	{
		std::map<int, LobbyServerInfo>::iterator it2 = _lobbyInfoMap.find(it->second);
		if (out_serverInfo)
			*out_serverInfo = it2->second;
		return true;
	}
	return false;
}

bool ServerInfoManage::FindLobby(int serverID, LobbyServerInfo * out_serverInfo)
{
	FWLockScopeController lsc(&_lobbyMapLock);
	std::map<int, LobbyServerInfo>::iterator it = _lobbyInfoMap.find(serverID);
	if (it != _lobbyInfoMap.end())
	{
		if (out_serverInfo)
			*out_serverInfo = it->second;
		return true;
	}
	return false;
}

bool ServerInfoManage::RemoveLobby(const FWNetMatch & netMatch)
{
	FWLockScopeController lsc(&_lobbyMapLock);
	std::map<FWNetMatch, int>::iterator it = _lobbyIDMap.find(netMatch);
	if (it != _lobbyIDMap.end())
	{
		int id = it->second;
		_lobbyInfoMap.erase(it->second);
		_lobbyIDMap.erase(it);

		CCenterServerDlg::RemoveLobbyServerToList(id);

		return true;
	}
	return false;
}

bool ServerInfoManage::RemoveLobby(int serverID)
{
	FWLockScopeController lsc(&_lobbyMapLock);
	std::map<int, LobbyServerInfo>::iterator it = _lobbyInfoMap.find(serverID);
	if (it != _lobbyInfoMap.end())
	{
		_lobbyIDMap.erase(it->second.NetMatch);
		_lobbyInfoMap.erase(it);

		CCenterServerDlg::RemoveLobbyServerToList(serverID);

		return true;
	}
	return false;
}

void ServerInfoManage::ClearLobby()
{
	FWLockScopeController lsc(&_lobbyMapLock);
	_lobbyInfoMap.clear();
	_lobbyIDMap.clear();

	CCenterServerDlg::ClearLobbyServerToList();
}

bool ServerInfoManage::AddLogical(const LogicalServerInfo & serverInfo)
{
	FWLockScopeController lsc(&_logicalMapLock);
	if (serverInfo.ServerID <= 0)
	{
		FW_LOG_ERROR("%s", "serverInfo.ServerID <= 0");
		return false;
	}
	std::map<int, LogicalServerInfo>::iterator it = _logicalInfoMap.find(serverInfo.ServerID);
	if (it != _logicalInfoMap.end())
	{
		return false;
	}
	std::pair<std::map<FWNetMatch, int>::iterator, bool> r = _logicalIDMap.insert(std::pair<FWNetMatch, int>(serverInfo.NetMatch, serverInfo.ServerID));
	if (!r.second)
	{
		return false;
	}
	_logicalInfoMap.insert(std::pair<int, LogicalServerInfo>(serverInfo.ServerID, serverInfo));

	CCenterServerDlg::AddLogicalServerToList(serverInfo.ServerID);

	return true;
}

bool ServerInfoManage::FindLogical(const FWNetMatch & netMatch, LogicalServerInfo * out_serverInfo)
{
	FWLockScopeController lsc(&_logicalMapLock);
	std::map<FWNetMatch, int>::iterator it = _logicalIDMap.find(netMatch);
	if (it != _logicalIDMap.end())
	{
		std::map<int, LogicalServerInfo>::iterator it2 = _logicalInfoMap.find(it->second);
		if (out_serverInfo)
			*out_serverInfo = it2->second;
		return true;
	}
	return false;
}

bool ServerInfoManage::FindLogical(int serverID, LogicalServerInfo * out_serverInfo)
{
	FWLockScopeController lsc(&_logicalMapLock);
	std::map<int, LogicalServerInfo>::iterator it = _logicalInfoMap.find(serverID);
	if (it != _logicalInfoMap.end())
	{
		if (out_serverInfo)
			*out_serverInfo = it->second;
		return true;
	}
	return false;
}

bool ServerInfoManage::RemoveLogical(const FWNetMatch & netMatch)
{
	FWLockScopeController lsc(&_logicalMapLock);
	std::map<FWNetMatch, int>::iterator it = _logicalIDMap.find(netMatch);
	if (it != _logicalIDMap.end())
	{
		int id = it->second;
		_logicalInfoMap.erase(it->second);
		_logicalIDMap.erase(it);

		CCenterServerDlg::RemoveLogicalServerToList(id);

		return true;
	}
	return false;
}

bool ServerInfoManage::RemoveLogical(int serverID)
{
	FWLockScopeController lsc(&_logicalMapLock);
	std::map<int, LogicalServerInfo>::iterator it = _logicalInfoMap.find(serverID);
	if (it != _logicalInfoMap.end())
	{
		_logicalIDMap.erase(it->second.NetMatch);
		_logicalInfoMap.erase(it);

		CCenterServerDlg::RemoveLogicalServerToList(serverID);

		return true;
	}
	return false;
}

void ServerInfoManage::ClearLogical()
{
	FWLockScopeController lsc(&_logicalMapLock);
	_logicalInfoMap.clear();
	_logicalIDMap.clear();

	CCenterServerDlg::ClearLogicalServerToList();
}