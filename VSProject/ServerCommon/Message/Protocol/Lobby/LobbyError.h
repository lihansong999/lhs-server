#ifndef __MESSAGE_LOBBYERROR_H__
#define __MESSAGE_LOBBYERROR_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Lobby{


		/*
		范围
		[200000, 299999]
		其中[2xx000, 2xx999]的xx位表示不同的子分类
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		//登录
		const int ERR_LOGIN_BAD1 = 201001;	//账号或密码错误
		const int ERR_LOGIN_BAD2 = 201002;	//unionid错误

		//查询
		const int ERR_QUERY_NOT_FOUND_PLAYER_INFO = 202001;	//找不到对应的玩家信息

		//比赛
		const int ERR_MATCH_ALREADY_PLAYING = 203001;	//已经在比赛中


	}
}


#endif //!__MESSAGE_LOBBYERROR_H__