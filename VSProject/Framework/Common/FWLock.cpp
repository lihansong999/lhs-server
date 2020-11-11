#include "FWLock.h"

FW_NS_BEGIN


FWLock::FWLock()
{
	_mutex = new std::mutex();
}

FWLock::~FWLock()
{
	delete ((std::mutex*)_mutex);
}

void FWLock::Lock()
{
	((std::mutex*)_mutex)->lock();
}

void FWLock::UnLock()
{
	((std::mutex*)_mutex)->unlock();
}


//////////////////////////////////////////////////////////////////////////


FWLockRecursive::FWLockRecursive()
{
	_mutex = new std::recursive_mutex();
}

FWLockRecursive::~FWLockRecursive()
{
	delete ((std::recursive_mutex*)_mutex);
}

void FWLockRecursive::Lock()
{
	((std::recursive_mutex*)_mutex)->lock();
}

void FWLockRecursive::UnLock()
{
	((std::recursive_mutex*)_mutex)->unlock();
}


//////////////////////////////////////////////////////////////////////////


FWLockScopeController::FWLockScopeController(FWLock * lock)
	:_lock(lock)
	, _lockRecursive(nullptr)
{
	_lock->Lock();
}

FWLockScopeController::FWLockScopeController(FWLockRecursive * lock)
	: _lock(nullptr)
	, _lockRecursive(lock)
{
	_lockRecursive->Lock();
}

FWLockScopeController::~FWLockScopeController()
{
	if (_lock)
	{
		_lock->UnLock();
	}
	if (_lockRecursive)
	{
		_lockRecursive->UnLock();
	}
}


FW_NS_END
