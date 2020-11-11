#include "SCTypeDefine.h"

SC_NS_BEGIN

FW_NS_USEING;


const char * RKN_LOBBY_SERVER_ID_SET			= "LobbyServerIDSet";
const char * RKN_LOBBY_SERVER_INFO_HASH			= "LobbyServerInfoHash_";

const char * RKN_LOGICAL_SERVER_ID_SET			= "LogicalServerIDSet";
const char * RKN_LOGICAL_SERVER_INFO_HASH		= "LogicalServerInfoHash_";

const long long SERVICE_PACKAGE_RECV_OUT_TIME		= 20000LL;
const long long DELAY_CLOSE_SOCKET_TIME_FOR_SENT	= 150LL;
const long long DELAY_CLOSE_SOCKET_TIME_MAX			= 1000LL;

const char * MESSAGE_PROBE_CHECK				= "LIHANSONG1234567890";


SvcNetMatch::SvcNetMatch()
	:Type(SCSNMT_MAX)
{

}

SvcNetMatch::SvcNetMatch(SvcNetMatchType type, const FWNetMatch & netMatch)
	:Type(type)
	, NetMatch(netMatch)
{

}

SvcNetMatch::SvcNetMatch(int type, unsigned int index, FW_NET_ACTIVITY_ID activityID)
	:Type((SvcNetMatchType)type)
	, NetMatch(index, activityID)
{

}

bool SvcNetMatch::operator<(const SvcNetMatch & other) const
{
	if (Type != other.Type)
	{
		return Type < other.Type;
	}
	return NetMatch < other.NetMatch;
}

bool SvcNetMatch::operator==(const SvcNetMatch & other) const
{
	return Type == other.Type && NetMatch == other.NetMatch;
}


SC_NS_END