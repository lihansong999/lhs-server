#ifndef __FRAMEWORK_NETYPEDEF_H__
#define __FRAMEWORK_NETYPEDEF_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


enum FW_DLL FWOverLappedContextType {
	FW_OLCT_UNKNOWN = 0,
	FW_OLCT_RECV,
	FW_OLCT_SEND,
};

struct FW_DLL FWOverLappedContext {
	FWOverLappedContext();
	OVERLAPPED					Overlapped;
	WSABUF						WsaBuf;
	FWOverLappedContextType		Type;
	void Clear();
};

typedef FW_ID	FW_NET_ACTIVITY_ID;

struct FW_DLL FWNetMatch {
	FWNetMatch();
	FWNetMatch(unsigned int index, FW_NET_ACTIVITY_ID activityID);
	bool operator<(const FWNetMatch & other) const;
	bool operator==(const FWNetMatch & other) const;
	unsigned int Index;
	FW_NET_ACTIVITY_ID ActivityID;
};


FW_NS_END


#endif //!__FRAMEWORK_NETYPEDEF_H__