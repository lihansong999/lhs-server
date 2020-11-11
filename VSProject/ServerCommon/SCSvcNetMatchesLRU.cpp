#include "SCSvcNetMatchesLRU.h"

SC_NS_BEGIN

FW_NS_USEING;


SvcNetMatchesLRU::SvcNetMatchesLRU()
{
	_svcNetMatchesSet = new FWLinkedSet<SvcNetMatch>(true);
}

SvcNetMatchesLRU::~SvcNetMatchesLRU()
{
	delete _svcNetMatchesSet;
}

bool SvcNetMatchesLRU::Add(const SvcNetMatch & svcNetMatch)
{
	FWLockScopeController lsc(&_svcNetMatchesContainerLock);
	if (!_svcNetMatchesSet->Insert(svcNetMatch))
	{
		return false;
	}
	return true;
}

bool SvcNetMatchesLRU::Add(SvcNetMatchType type, const FWNetMatch & netMatch)
{
	return Add(SvcNetMatch(type, netMatch));
}

bool SvcNetMatchesLRU::Find(const SvcNetMatch & svcNetMatch)
{
	FWLockScopeController lsc(&_svcNetMatchesContainerLock);
	FWLinkedSet<SvcNetMatch>::Iterator it = _svcNetMatchesSet->Find(svcNetMatch);
	if (it != _svcNetMatchesSet->End())
	{
		return true;
	}
	return false;
}

bool SvcNetMatchesLRU::Find(SvcNetMatchType type, const FWNetMatch & netMatch)
{
	return Find(SvcNetMatch(type, netMatch));
}

bool SvcNetMatchesLRU::Remove(const SvcNetMatch & svcNetMatch)
{
	FWLockScopeController lsc(&_svcNetMatchesContainerLock);
	return _svcNetMatchesSet->Erase(svcNetMatch) == 1;
}

bool SvcNetMatchesLRU::Remove(SvcNetMatchType type, const FWNetMatch & netMatch)
{
	return Find(SvcNetMatch(type, netMatch));
}

void SvcNetMatchesLRU::Clear()
{
	FWLockScopeController lsc(&_svcNetMatchesContainerLock);
	_svcNetMatchesSet->Clear();
}

int SvcNetMatchesLRU::LRU(SvcNetMatch * out_svcNetMatches, int count)
{
	FWLockScopeController lsc(&_svcNetMatchesContainerLock);
	if (!out_svcNetMatches || count <= 0)
	{
		return 0;
	}
	int index = 0;
	for (FWLinkedSet<SvcNetMatch>::Iterator it = _svcNetMatchesSet->Begin(); it != _svcNetMatchesSet->End(); it++)
	{
		out_svcNetMatches[index] = *it;
		if (++index == count)
			break;
	}
	return index;
}


SC_NS_END