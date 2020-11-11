#ifndef __MESSAGE_CENTERERROR_H__
#define __MESSAGE_CENTERERROR_H__
#if defined(MESSAGE_SERVER)

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Center {


		/*
		��Χ
		[400000, 499999]
		����[4xx000, 4xx999]��xxλ��ʾ��ͬ���ӷ���
		*/
		extern MSG_DLL const char * GetErrorString(int code);


	}
}


#endif
#endif //!__MESSAGE_CENTERERROR_H__