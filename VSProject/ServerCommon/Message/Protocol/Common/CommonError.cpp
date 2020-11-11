#include "CommonError.h"

namespace MSG_NAMESPACE {
	namespace Common {


#define INSERTERR(k,v)	_errMap.insert(std::pair<int, std::string>(k, v))


		struct ErrorStringCtor
		{
			ErrorStringCtor()
			{
				INSERTERR(ERR_UNKNOWN, "δ֪����");
				INSERTERR(ERR_SERVER_BUSY, "��������æ");
				INSERTERR(ERR_NOT_LOGGED, "�Ƿ���������δ��¼");
				INSERTERR(ERR_LOGIN_REPEAT, "�����ظ���¼");
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