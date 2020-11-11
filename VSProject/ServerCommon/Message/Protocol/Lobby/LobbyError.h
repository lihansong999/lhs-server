#ifndef __MESSAGE_LOBBYERROR_H__
#define __MESSAGE_LOBBYERROR_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Lobby{


		/*
		��Χ
		[200000, 299999]
		����[2xx000, 2xx999]��xxλ��ʾ��ͬ���ӷ���
		*/
		extern MSG_DLL const char * GetErrorString(int code);

		//��¼
		const int ERR_LOGIN_BAD1 = 201001;	//�˺Ż��������
		const int ERR_LOGIN_BAD2 = 201002;	//unionid����

		//��ѯ
		const int ERR_QUERY_NOT_FOUND_PLAYER_INFO = 202001;	//�Ҳ�����Ӧ�������Ϣ

		//����
		const int ERR_MATCH_ALREADY_PLAYING = 203001;	//�Ѿ��ڱ�����


	}
}


#endif //!__MESSAGE_LOBBYERROR_H__