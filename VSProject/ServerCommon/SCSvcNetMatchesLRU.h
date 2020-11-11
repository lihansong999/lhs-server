#ifndef __SERVERCOMMON_SVCNETMATCHESLRU_H__
#define __SERVERCOMMON_SVCNETMATCHESLRU_H__

#include "SCLocal.h"
#include "SCTypeDefine.h"

SC_NS_BEGIN


class SC_DLL SvcNetMatchesLRU
{
public:
	SvcNetMatchesLRU();
	~SvcNetMatchesLRU();

	bool Add(const SvcNetMatch & svcNetMatch);
	bool Add(SvcNetMatchType type, const Framework::FWNetMatch & netMatch);

	bool Find(const SvcNetMatch & svcNetMatch);
	bool Find(SvcNetMatchType type, const Framework::FWNetMatch & netMatch);

	bool Remove(const SvcNetMatch & svcNetMatch);
	bool Remove(SvcNetMatchType type, const Framework::FWNetMatch & netMatch);

	void Clear();

	int LRU(SvcNetMatch * out_svcNetMatches, int count);

private:
	Framework::FWLockRecursive				_svcNetMatchesContainerLock;
	Framework::FWLinkedSet<SvcNetMatch>	  *	_svcNetMatchesSet;
};


SC_NS_END


#endif //!__SERVERCOMMON_SVCNETMATCHESLRU_H__