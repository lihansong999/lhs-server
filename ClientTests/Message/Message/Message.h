#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "MsgString.h"
#include "MsgBase.h"
#include "MsgPackage.h"
#include "Protocol/Common/CommonProtocol.h"
#include "Protocol/Common/CommonError.h"
#include "Protocol/Lobby/LobbyProtocol.h"
#include "Protocol/Lobby/LobbyError.h"
#include "Protocol/Logical/LogicalProtocol.h"
#include "Protocol/Logical/LogicalError.h"
#if defined(MESSAGE_SERVER)
#include "Protocol/Center/CenterProtocol.h"
#include "Protocol/Center/CenterError.h"
#endif


#endif //!__MESSAGE_H__