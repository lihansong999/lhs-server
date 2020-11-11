#include "CommonError.h"

namespace MSG_NAMESPACE {
	namespace Common {


#define INSERTERR(k,v)	_errMap.insert(std::pair<int, std::string>(k, v))


		struct ErrorStringCtor
		{
			ErrorStringCtor()
			{
				INSERTERR(ERR_UNKNOWN, "未知错误");
				INSERTERR(ERR_SERVER_BUSY, "服务器繁忙");
				INSERTERR(ERR_NOT_LOGGED, "非法操作，尚未登录");
				INSERTERR(ERR_LOGIN_REPEAT, "不可重复登录");
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