#ifndef __MESSAGE_LOGICALERROR_H__
#define __MESSAGE_LOGICALERROR_H__

#include "../../MsgBase.h"


namespace MSG_NAMESPACE {
	namespace Logical {


		/*
		范围
		[300000, 399999]
		其中[3xx000, 3xx999]的xx位表示不同的子分类
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		//登录
		const int ERR_LOGIN_BAD1 = 301001;	//登录验证失败
		const int ERR_LOGIN_BAD2 = 301002;	//已在另一个比赛服中

		//比赛
		const int ERR_MATCH_ADD_BAD1 = 302001;	//已在比赛中，不可重复加入
		const int ERR_MATCH_QUIT_BAD1 = 302002;	//未在比赛中，无法退出


	}
}


#endif //!__MESSAGE_LOGICALERROR_H__