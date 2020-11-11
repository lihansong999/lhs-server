#ifndef __FRAMEWORK_LOCAL_H__
#define __FRAMEWORK_LOCAL_H__

#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <new.h>
#include <assert.h>
#include <malloc.h>
#include <string>
#include <regex>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <iterator>
#include <functional>
#include <stdarg.h>
#include <thread>
#include <mutex>
#include <winsock2.h>
#include <MSWSock.h>
#include <mstcpip.h>
#include <WS2tcpip.h>
#include <process.h>
#include <future>
#include <windows.h>

#include "ThirdParty/rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#pragma warning(push)
#pragma warning(disable:4003)
#include "ThirdParty/rapidjson-1.1.0/include/rapidjson/document.h"
#pragma warning(pop)
#include "ThirdParty/rapidjson-1.1.0/include/rapidjson/error/en.h"
#include "ThirdParty/rapidjson-1.1.0/include/rapidjson/writer.h"
#include "ThirdParty/rapidjson-1.1.0/include/rapidjson/stringbuffer.h"

#include "ThirdParty/tinyxml2-7.1.0/tinyxml2.h"

#include "ThirdParty/zlib/include/zlib.h"

#include "ThirdParty/libcurl/include/curl.h"


#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#include "ThirdParty/MemoryLeakDetector/include/vld.h"
#endif
#endif

#if defined(FRAMEWORK_EXPORTS)
#define FW_DLL     __declspec(dllexport)
#else
#define FW_DLL     __declspec(dllimport)
#endif

#define FW_NS_BEGIN		namespace Framework {
#define FW_NS_END		}
#define FW_NS_USEING	using namespace Framework


#define FW_PRINT(format, ...) \
	do{ \
		Framework::FWOutPut::GetInstance()->Print(format, ##__VA_ARGS__); \
			}while(false)

#define FW_PRINT_NOT_AUTO_NEWLINES(format, ...) \
	do{ \
		Framework::FWOutPut::GetInstance()->PrintNotAutoNewlines(format, ##__VA_ARGS__); \
			}while(false)

#define FW_LOG(format, ...) \
	do{ \
		Framework::FWOutPut::GetInstance()->Log(Framework::FWOutPut::NORMAL, __FUNCTION__, format, ##__VA_ARGS__); \
			}while(false)

#define FW_LOG_WRNING(format, ...) \
	do{ \
		Framework::FWOutPut::GetInstance()->Log(Framework::FWOutPut::WARNING, __FUNCTION__, format, ##__VA_ARGS__); \
			}while(false)

#define FW_LOG_ERROR(format, ...) \
	do{ \
		Framework::FWOutPut::GetInstance()->Log(Framework::FWOutPut::WRONG, __FUNCTION__, format, ##__VA_ARGS__); \
			}while(false)


#if defined(_DEBUG)

#define FW_PRINT_DEBUG						FW_PRINT
#define FW_PRINT_NOT_AUTO_NEWLINES_DEBUG	FW_PRINT_NOT_AUTO_NEWLINES

#define FW_LOG_DEBUG						FW_LOG
#define FW_LOG_WRNING_DEBUG					FW_LOG_WRNING
#define FW_LOG_ERROR_DEBUG					FW_LOG_ERROR

#else

#define FW_PRINT_DEBUG(format, ...)			do {} while (false)
#define FW_PRINT_NOT_AUTO_NEWLINES_DEBUG	do {} while (false)

#define FW_LOG_DEBUG(format, ...)			do {} while (false)
#define FW_LOG_WRNING_DEBUG(format, ...)	do {} while (false)
#define FW_LOG_ERROR_DEBUG(format, ...)		do {} while (false)

#endif


extern FW_DLL const char * FWVersion();


#endif //!__FRAMEWORK_LOCAL_H__