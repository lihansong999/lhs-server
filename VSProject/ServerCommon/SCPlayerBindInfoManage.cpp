#include "SCPlayerBindInfoManage.h"

SC_NS_BEGIN

FW_NS_USEING;


PlayerBindInfoManage::PlayerBindInfoManage()
{
	_playerBindInfoMap = new std::map<PlayerID_t, PlayerBindInfo>();
	_playerIDMap = new std::map<SvcNetMatch, PlayerID_t>();
}

PlayerBindInfoManage::~PlayerBindInfoManage()
{
	delete _playerBindInfoMap;
	delete _playerIDMap;
}

bool PlayerBindInfoManage::Add(const PlayerBindInfo & playerBindInfo)
{
	FWLockScopeController lsc(&_playerContainerLock);
	std::pair<std::map<SvcNetMatch, PlayerID_t>::iterator, bool> r = _playerIDMap->insert(std::pair<SvcNetMatch, PlayerID_t>(playerBindInfo.SvcNetMatch, playerBindInfo.PlayerID));
	if (!r.second)
	{
		return false;
	}
	std::pair<std::map<PlayerID_t, PlayerBindInfo>::iterator, bool> r2 = _playerBindInfoMap->insert(std::pair<PlayerID_t, PlayerBindInfo>(playerBindInfo.PlayerID, playerBindInfo));
	if (!r2.second)
	{
		_playerIDMap->erase(r.first);
		return false;
	}
	return true;
}

bool PlayerBindInfoManage::Find(const SvcNetMatch & svcNetMatch, PlayerBindInfo * out_playerBindInfo)
{
	FWLockScopeController lsc(&_playerContainerLock);
	std::map<SvcNetMatch, PlayerID_t>::iterator it = _playerIDMap->find(svcNetMatch);
	if (it != _playerIDMap->end())
	{
		std::map<PlayerID_t, PlayerBindInfo>::iterator it2 = _playerBindInfoMap->find(it->second);
		if(out_playerBindInfo)
			*out_playerBindInfo = it2->second;
		return true;
	}
	return false;
}

bool PlayerBindInfoManage::Find(PlayerID_t playerID, PlayerBindInfo * out_playerBindInfo)
{
	FWLockScopeController lsc(&_playerContainerLock);
	std::map<PlayerID_t, PlayerBindInfo>::iterator it = _playerBindInfoMap->find(playerID);
	if (it != _playerBindInfoMap->end())
	{
		if (out_playerBindInfo)
			*out_playerBindInfo = it->second;
		return true;
	}
	return false;
}

bool PlayerBindInfoManage::Remove(const SvcNetMatch & svcNetMatch)
{
	FWLockScopeController lsc(&_playerContainerLock);
	std::map<SvcNetMatch, PlayerID_t>::iterator it = _playerIDMap->find(svcNetMatch);
	if (it != _playerIDMap->end())
	{
		_playerBindInfoMap->erase(it->second);
		_playerIDMap->erase(it);
		return true;
	}
	return false;
}

bool PlayerBindInfoManage::Remove(PlayerID_t playerID)
{
	FWLockScopeController lsc(&_playerContainerLock);
	std::map<PlayerID_t, PlayerBindInfo>::iterator it = _playerBindInfoMap->find(playerID);
	if (it != _playerBindInfoMap->end())
	{
		_playerIDMap->erase(it->second.SvcNetMatch);
		_playerBindInfoMap->erase(it);
		return true;
	}
	return false;
}

void PlayerBindInfoManage::Clear()
{
	FWLockScopeController lsc(&_playerContainerLock);
	_playerBindInfoMap->clear();
	_playerIDMap->clear();
}


SC_NS_END