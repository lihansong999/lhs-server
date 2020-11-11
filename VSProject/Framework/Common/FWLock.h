#ifndef __FRAMEWORK_LOCK_H__
#define __FRAMEWORK_LOCK_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


/*
ª•≥‚À¯
*/
class FW_DLL FWLock
{
public:
	FWLock();
	FWLock(const FWLock & other) = delete;
	FWLock& operator=(const FWLock & other) = delete;
	FWLock(FWLock && other) = delete;
	FWLock& operator=(FWLock && other) = delete;
	~FWLock();

	void Lock();
	void UnLock();

private:
	void * _mutex;
};


/*
µ›πÈª•≥‚À¯
*/
class FW_DLL FWLockRecursive
{
public:
	FWLockRecursive();
	FWLockRecursive(const FWLockRecursive & other) = delete;
	FWLockRecursive& operator=(const FWLockRecursive & other) = delete;
	FWLockRecursive(FWLockRecursive && other) = delete;
	FWLockRecursive& operator=(FWLockRecursive && other) = delete;
	~FWLockRecursive();

	void Lock();
	void UnLock();

private:
	void * _mutex;
};


/*
æ÷≤ø…œÀ¯∂‘œÛ
*/
class FW_DLL FWLockScopeController
{
public:
	FWLockScopeController(FWLock * lock);
	FWLockScopeController(FWLockRecursive * lock);
	FWLockScopeController(const FWLockScopeController & other) = delete;
	FWLockScopeController& operator=(const FWLockScopeController & other) = delete;
	FWLockScopeController(FWLockScopeController && other) = delete;
	FWLockScopeController& operator=(FWLockScopeController && other) = delete;
	~FWLockScopeController();

private:
	FWLock * _lock;
	FWLockRecursive * _lockRecursive;
};



FW_NS_END


#endif //!__FRAMEWORK_LOCK_H__