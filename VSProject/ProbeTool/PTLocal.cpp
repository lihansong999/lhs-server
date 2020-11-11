#include "PTLocal.h"

#pragma comment(lib, "ws2_32.lib")

#pragma comment(lib, "Framework.lib")
#pragma comment(lib, "ServerCommon.lib")
#pragma comment(lib, "libprotobuf.lib")

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#pragma comment(lib, "vld.lib")
#endif
#endif