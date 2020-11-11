#include "FWPTW32Lock.h"

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#endif // !HAVE_STRUCT_TIMESPEC
#include <pthread.h>

FW_NS_BEGIN


FWPTW32Lock::FWPTW32Lock()
{
	_mutex = new pthread_mutex_t();
	pthread_mutexattr_t mutexAttr;
	pthread_mutexattr_init(&mutexAttr);
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_NORMAL);
	pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_PRIVATE);
	pthread_mutexattr_setrobust(&mutexAttr, PTHREAD_MUTEX_STALLED);
	pthread_mutex_init((pthread_mutex_t*)_mutex, &mutexAttr);
	pthread_mutexattr_destroy(&mutexAttr);
}

FWPTW32Lock::~FWPTW32Lock()
{
	pthread_mutex_destroy((pthread_mutex_t*)_mutex);
	delete ((pthread_mutex_t*)_mutex);
}

void FWPTW32Lock::Lock()
{
	pthread_mutex_lock((pthread_mutex_t*)_mutex);
}

void FWPTW32Lock::UnLock()
{
	pthread_mutex_unlock((pthread_mutex_t*)_mutex);
}


//////////////////////////////////////////////////////////////////////////


FWPTW32LockRecursive::FWPTW32LockRecursive()
{
	_mutex = new pthread_mutex_t();
	pthread_mutexattr_t mutexAttr;
	pthread_mutexattr_init(&mutexAttr);
	pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_PRIVATE);
	pthread_mutexattr_setrobust(&mutexAttr, PTHREAD_MUTEX_STALLED);
	pthread_mutex_init((pthread_mutex_t*)_mutex, &mutexAttr);
	pthread_mutexattr_destroy(&mutexAttr);
}

FWPTW32LockRecursive::~FWPTW32LockRecursive()
{
	pthread_mutex_destroy((pthread_mutex_t*)_mutex);
	delete ((pthread_mutex_t*)_mutex);
}

void FWPTW32LockRecursive::Lock()
{
	pthread_mutex_lock((pthread_mutex_t*)_mutex);
}

void FWPTW32LockRecursive::UnLock()
{
	pthread_mutex_unlock((pthread_mutex_t*)_mutex);
}


//////////////////////////////////////////////////////////////////////////


FWPTW32LockScopeController::FWPTW32LockScopeController(FWPTW32Lock * lock)
	:_lock(lock)
	, _lockRecursive(nullptr)
{
	_lock->Lock();
}

FWPTW32LockScopeController::FWPTW32LockScopeController(FWPTW32LockRecursive * lock)
	: _lock(nullptr)
	, _lockRecursive(lock)
{
	_lockRecursive->Lock();
}

FWPTW32LockScopeController::~FWPTW32LockScopeController()
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
