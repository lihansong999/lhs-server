#ifndef __MESSAGE_LOCAL_H__
#define __MESSAGE_LOCAL_H__

//json
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#pragma warning(push)
#pragma warning(disable:4003)
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/document.h"
#pragma warning(pop)
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/error/en.h"
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/writer.h"
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/stringbuffer.h"

#include <string>
#include <map>

#if defined(MESSAGE_EXPORTS)
#define MSG_DLL     __declspec(dllexport)
#else
#define MSG_DLL		__declspec(dllimport)
#endif

#define MSG_NAMESPACE Message


#endif //!__MESSAGE_LOCAL_H__