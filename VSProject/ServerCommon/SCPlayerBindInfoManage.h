#ifndef __SERVERCOMMON_PLAYERBINDINFOMANAGE_H__
#define __SERVERCOMMON_PLAYERBINDINFOMANAGE_H__

#include "SCLocal.h"
#include "SCTypeDefine.h"

SC_NS_BEGIN


class SC_DLL PlayerBindInfoManage
{
public:
	PlayerBindInfoManage();
	~PlayerBindInfoManage();

	bool Add(const PlayerBindInfo & playerBindInfo);

	bool Find(const SvcNetMatch & svcNetMatch, PlayerBindInfo * out_playerBindInfo);
	bool Find(PlayerID_t playerID, PlayerBindInfo * out_playerBindInfo);

	bool Remove(const SvcNetMatch & svcNetMatch);
	bool Remove(PlayerID_t playerID);
	
	void Clear();

private:
	Framework::FWLockRecursive				_playerContainerLock;
	std::map<PlayerID_t, PlayerBindInfo>  *	_playerBindInfoMap;
	std::map<SvcNetMatch, PlayerID_t>	  *	_playerIDMap;
};


SC_NS_END


#endif //!__SERVERCOMMON_PLAYERBINDINFOMANAGE_H__