#ifndef __MESSAGE_CENTERERROR_H__
#define __MESSAGE_CENTERERROR_H__
#if defined(MESSAGE_SERVER)

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Center {


		/*
		范围
		[400000, 499999]
		其中[4xx000, 4xx999]的xx位表示不同的子分类
		*/
		extern MSG_DLL const char * GetErrorString(int code);


	}
}


#endif
#endif //!__MESSAGE_CENTERERROR_H__