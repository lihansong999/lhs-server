#ifndef __MESSAGE_PROTOCOLTYPEDEF_H__
#define __MESSAGE_PROTOCOLTYPEDEF_H__

#include "../MsgBase.h"


namespace MSG_NAMESPACE {

#define PLAYERID_T	long long
#define GOLDS_T		long long
#define DIAMONDS_T	long long


	enum ForceOfflineType
	{
		FOT_UNKNOWN = 0,
		FOT_REPEAT_LOGIN,	//�ظ���¼��������
	};


}


#endif //!__MESSAGE_PROTOCOLTYPEDEF_H__