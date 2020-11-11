#if defined(MESSAGE_SERVER)

#include "CenterError.h"

namespace MSG_NAMESPACE {
	namespace Center {


#define INSERTERR(k,v)	_errMap.insert(std::pair<int, std::string>(k, v))


		struct ErrorStringCtor
		{
			ErrorStringCtor()
			{

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


#endif