#include "LobbyError.h"

namespace MSG_NAMESPACE {
	namespace Lobby {


#define INSERTERR(k,v)	_errMap.insert(std::pair<int, std::string>(k, v))


		struct ErrorStringCtor
		{
			ErrorStringCtor()
			{
				INSERTERR(ERR_LOGIN_BAD1, "账号或密码错误");
				INSERTERR(ERR_LOGIN_BAD2, "unionid错误");
				INSERTERR(ERR_QUERY_NOT_FOUND_PLAYER_INFO, "找不到相应的玩家信息");
				INSERTERR(ERR_MATCH_ALREADY_PLAYING, "已经在比赛中");
			}
			std::map<int, std::string> _errMap;
		};
		static ErrorStringCtor _ErrorStringCtor;


		const char * GetErrorString(int code)
		{
			std::map<int, std::string>::iterator it = _ErrorStringCtor._errMap.find(code);
			if (it != _ErrorStringCtor._errMap.end())
			{
				return it->second.c_str();
			}
			return nullptr;
		}


	}
}