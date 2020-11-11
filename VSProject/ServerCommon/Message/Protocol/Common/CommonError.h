#ifndef __MESSAGE_COMMONERROR_H__
#define __MESSAGE_COMMONERROR_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Common {


		/*
		范围
		[100000, 199999]
		其中[1xx000, 1xx999]的xx位表示不同的子分类
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		const int ERR_UNKNOWN = 101001;	//未知错误
		const int ERR_SERVER_BUSY = 101002;	//服务器繁忙
		const int ERR_NOT_LOGGED = 101003; //非法操作，尚未登录
		const int ERR_LOGIN_REPEAT = 101004; //不可重复登录


	}
}


#endif //!__MESSAGE_COMMONERROR_H__