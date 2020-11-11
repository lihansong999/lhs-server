#pragma once

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

#include "../../Message/Message/Message.h"

#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/rapidjson.h"
#pragma warning(push)
#pragma warning(disable:4003)
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/document.h"
#pragma warning(pop)
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/error/en.h"
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/writer.h"
#include "../../ThirdParty/rapidjson-1.1.0/include/rapidjson/stringbuffer.h"


#include "../../tinyxml2/tinyxml2.h"

#include "../../ThirdParty/zlib/include/zlib.h"

#include "../../ThirdParty/libcurl/include/curl.h"

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#include "../../ThirdParty/MemoryLeakDetector/include/vld.h"
#endif
#endif