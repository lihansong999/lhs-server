#ifndef __FRAMEWORK_SVCTYPEDEF_H__
#define __FRAMEWORK_SVCTYPEDEF_H__

#include "../FWNetTypeDef.h"

FW_NS_BEGIN


struct FW_DLL FWSvcSocketInfo {
	FWSvcSocketInfo();
	char Ip46[64];				//如果使用 FWWebSvcManageBase::WSAF_V46MAPPED 或 FWTcpListenSocket::AF_V46MAPPED 参考 https://tools.ietf.org/html/rfc2553#section-3.7
	unsigned short Port;
	long long InitTime;			// FW_TIME()
	long long LastReceivedTime;	// FW_TIME()
};


FW_NS_END


#endif //!__FRAMEWORK_SVCTYPEDEF_H__