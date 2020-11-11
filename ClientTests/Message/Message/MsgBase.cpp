#include "MsgBase.h"
#include "Protocol/Common/CommonError.h"
#include "Protocol/Lobby/LobbyError.h"
#include "Protocol/Logical/LogicalError.h"
#if defined(MESSAGE_SERVER)
#include "Protocol/Center/CenterError.h"
#endif

namespace MSG_NAMESPACE {


	static inline bool _IsBigEndian()
	{
		short var = 0x1234;
		return *((char*)(&var)) == 0x12;
	}

	static inline int _ChangeEndianInt32(int i)
	{
		return (
			((i << 24) & 0xff000000) |
			((i << 8) & 0x00ff0000) |
			((i >> 8) & 0x0000ff00) |
			((i >> 24) & 0x000000ff)
			);
	}

	int htonInt32(int i)
	{
		if (_IsBigEndian())
		{
			return i;
		}
		return _ChangeEndianInt32(i);
	}

	int ntohInt32(int i)
	{
		if (_IsBigEndian())
		{
			return i;
		}
		return _ChangeEndianInt32(i);
	}

	MSGString GetErrorString(int code)
	{
		const char * ret = nullptr;
		if (ret = Common::GetErrorString(code))
			return ret;
		if (ret = Logical::GetErrorString(code))
			return ret;
		if (ret = Lobby::GetErrorString(code))
			return ret;
#if defined(MESSAGE_SERVER)
		if (ret = Center::GetErrorString(code))
			return ret;
#endif
		char buff[64] = { 0 };
		sprintf_s(buff, sizeof(buff), "%s%d", "Î´¶¨ÒåµÄ´íÎóÂë£º", code);
		return buff;
	}

	MsgBodyBase::MsgBodyBase()
	{

	}

	MsgBodyBase::~MsgBodyBase()
	{

	}
	

}