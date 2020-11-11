#include "FWNetTypeDef.h"

FW_NS_BEGIN


FWOverLappedContext::FWOverLappedContext()
{
	this->Clear();
}

void FWOverLappedContext::Clear()
{
	memset(&Overlapped, 0, sizeof(OVERLAPPED));
	WsaBuf.buf = nullptr;
	WsaBuf.len = 0;
	Type = FW_OLCT_UNKNOWN;
}

FWNetMatch::FWNetMatch()
	:Index(0)
	, ActivityID(0)
{

}

FWNetMatch::FWNetMatch(unsigned int index, FW_NET_ACTIVITY_ID activityID)
	:Index(index)
	, ActivityID(activityID)
{

}

bool FWNetMatch::operator<(const FWNetMatch & other) const
{
	if (Index != other.Index)
	{
		return Index < other.Index;
	}
	return ActivityID < other.ActivityID;
}

bool FWNetMatch::operator==(const FWNetMatch & other) const
{
	return Index == other.Index && ActivityID == other.ActivityID;
}


FW_NS_END