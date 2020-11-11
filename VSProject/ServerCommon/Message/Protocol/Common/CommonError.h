#ifndef __MESSAGE_COMMONERROR_H__
#define __MESSAGE_COMMONERROR_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Common {


		/*
		��Χ
		[100000, 199999]
		����[1xx000, 1xx999]��xxλ��ʾ��ͬ���ӷ���
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		const int ERR_UNKNOWN = 101001;	//δ֪����
		const int ERR_SERVER_BUSY = 101002;	//��������æ
		const int ERR_NOT_LOGGED = 101003; //�Ƿ���������δ��¼
		const int ERR_LOGIN_REPEAT = 101004; //�����ظ���¼


	}
}


#endif //!__MESSAGE_COMMONERROR_H__