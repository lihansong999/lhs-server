#ifndef __MESSAGE_LOGICALERROR_H__
#define __MESSAGE_LOGICALERROR_H__

#include "../../MsgBase.h"


namespace MSG_NAMESPACE {
	namespace Logical {


		/*
		��Χ
		[300000, 399999]
		����[3xx000, 3xx999]��xxλ��ʾ��ͬ���ӷ���
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		//��¼
		const int ERR_LOGIN_BAD1 = 301001;	//��¼��֤ʧ��
		const int ERR_LOGIN_BAD2 = 301002;	//������һ����������

		//����
		const int ERR_MATCH_ADD_BAD1 = 302001;	//���ڱ����У������ظ�����
		const int ERR_MATCH_QUIT_BAD1 = 302002;	//δ�ڱ����У��޷��˳�


	}
}


#endif //!__MESSAGE_LOGICALERROR_H__