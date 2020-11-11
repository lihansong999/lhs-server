#ifndef __SERVERCOMMON_REDISHELPER_H__
#define __SERVERCOMMON_REDISHELPER_H__

#include "SCLocal.h"

SC_NS_BEGIN


class SC_DLL RedisHelper : public Framework::FWRedisHelper
{
public:
	RedisHelper();
	~RedisHelper();

private:

};


SC_NS_END


#endif //!__SERVERCOMMON_REDISHELPER_H__