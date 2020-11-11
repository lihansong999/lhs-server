#include "LogicalError.h"

namespace MSG_NAMESPACE {
	namespace Logical {


#define INSERTERR(k,v)	_errMap.insert(std::pair<int, std::string>(k, v))


		struct ErrorStringCtor
		{
			ErrorStringCtor()
			{
				INSERTERR(ERR_LOGIN_BAD1, "��¼��֤ʧ��");
				INSERTERR(ERR_LOGIN_BAD2, "������һ����������");
				INSERTERR(ERR_MATCH_ADD_BAD1, "���ڱ����У������ظ�����");
				INSERTERR(ERR_MATCH_QUIT_BAD1, "δ�ڱ����У��޷��˳�");
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