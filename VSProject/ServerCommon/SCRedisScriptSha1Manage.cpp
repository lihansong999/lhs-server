#include "SCRedisScriptSha1Manage.h"

SC_NS_BEGIN

FW_NS_USEING;


RedisScriptSha1Manage::RedisScriptSha1Manage()
{
	_scriptSha1Map = new std::map<std::string, std::string>();
}

RedisScriptSha1Manage::~RedisScriptSha1Manage()
{
	delete _scriptSha1Map;
}

bool RedisScriptSha1Manage::Reset(const char ** scriptNameArray, const char ** scriptSha1Array, int count)
{
	FWLockScopeController lsc(&_scriptSha1ContainerLock);
	_scriptSha1Map->clear();
	for (int i = 0; i < count; i++)
	{
		const char * scriptName = scriptNameArray[i];
		const char * scriptSha1 = scriptSha1Array[i];
		std::pair<std::map<std::string, std::string>::iterator, bool> r = _scriptSha1Map->insert(std::pair<std::string, std::string>(scriptName, scriptSha1));
		if (!r.second)
		{
			return false;
		}
	}
	return true;
}

FWString RedisScriptSha1Manage::Find(const char * scriptName)
{
	FWLockScopeController lsc(&_scriptSha1ContainerLock);
	std::map<std::string, std::string>::iterator it = _scriptSha1Map->find(scriptName);
	if (it != _scriptSha1Map->end())
	{
		return it->second.c_str();
	}
	return "";
}


SC_NS_END