#ifndef __SERVERCOMMON_REDISSCRIPTSHA1MANAGE_H__
#define __SERVERCOMMON_REDISSCRIPTSHA1MANAGE_H__

#include "SCLocal.h"
#include "SCTypeDefine.h"

SC_NS_BEGIN


class SC_DLL RedisScriptSha1Manage
{
public:
	RedisScriptSha1Manage();
	~RedisScriptSha1Manage();

	bool Reset(const char ** scriptNameArray, const char ** scriptSha1Array, int count);

	Framework::FWString Find(const char * scriptName);

private:
	Framework::FWLockRecursive				_scriptSha1ContainerLock;
	std::map<std::string, std::string>	*	_scriptSha1Map;
};


SC_NS_END


#endif //!__SERVERCOMMON_REDISSCRIPTSHA1MANAGE_H__