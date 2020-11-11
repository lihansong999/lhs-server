#pragma once
#include "Local.h"

typedef Framework::FWSchedule<std::function<void(long long, Framework::FW_ID)> > Schedule;

struct LobbyServerInfo
{
	Framework::FWNetMatch	NetMatch;
	int						ServerID;
};

struct LogicalServerInfo
{
	Framework::FWNetMatch	NetMatch;
	int						ServerID;
};