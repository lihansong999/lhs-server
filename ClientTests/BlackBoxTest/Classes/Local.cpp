#include "stdafx.h"
#include "Local.h"


#pragma comment(lib, "Message.lib")

#pragma comment(lib, "ws2_32.lib")

#pragma comment(lib, "zlib.lib")

//#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")

#pragma comment(lib, "libcurl.lib")

#pragma comment(lib, "tinyxml2.lib")

#pragma comment(lib, "libprotobuf.lib")


#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#pragma comment(lib, "vld.lib")
#endif
#endif