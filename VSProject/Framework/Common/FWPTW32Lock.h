#ifndef __FRAMEWORK_PTW32LOCK_H__
#define __FRAMEWORK_PTW32LOCK_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


/*
PTW32ª•≥‚À¯
*/
class FW_DLL FWPTW32Lock
{
public:
	FWPTW32Lock();
	FWPTW32Lock(const FWPTW32Lock & other) = delete;
	FWPTW32Lock& operator=(const FWPTW32Lock & other) = delete;
	FWPTW32Lock(FWPTW32Lock && other) = delete;
	FWPTW32Lock& operator=(FWPTW32Lock && other) = delete;
	~FWPTW32Lock();

	void Lock();
	void UnLock();

private:
	void * _mutex;
};


/*
PTW32µ›πÈª•≥‚À¯
*/
class FW_DLL FWPTW32LockRecursive
{
public:
	FWPTW32LockRecursive();
	FWPTW32LockRecursive(const FWPTW32LockRecursive & other) = delete;
	FWPTW32LockRecursive& operator=(const FWPTW32LockRecursive & other) = delete;
	FWPTW32LockRecursive(FWPTW32LockRecursive && other) = delete;
	FWPTW32LockRecursive& operator=(FWPTW32LockRecursive && other) = delete;
	~FWPTW32LockRecursive();

	void Lock();
	void UnLock();

private:
	void * _mutex;
};


/*
PTW32æ÷≤ø…œÀ¯∂‘œÛ
*/
class FW_DLL FWPTW32LockScopeController
{
public:
	FWPTW32LockScopeController(FWPTW32Lock * lock);
	FWPTW32LockScopeController(FWPTW32LockRecursive * lock);
	FWPTW32LockScopeController(const FWPTW32LockScopeController & other) = delete;
	FWPTW32LockScopeController& operator=(const FWPTW32LockScopeController & other) = delete;
	FWPTW32LockScopeController(FWPTW32LockScopeController && other) = delete;
	FWPTW32LockScopeController& operator=(FWPTW32LockScopeController && other) = delete;
	~FWPTW32LockScopeController();

private:
	FWPTW32Lock * _lock;
	FWPTW32LockRecursive * _lockRecursive;
};



FW_NS_END


#endif //!__FRAMEWORK_PTW32LOCK_H__