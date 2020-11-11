#include "FWLocal.h"

#pragma comment(lib, "ws2_32.lib")

#pragma comment(lib, "hiredis.lib")
#pragma comment(lib, "hiredis_ssl.lib")

#pragma comment(lib, "libmysql.lib")

#pragma comment(lib, "zlib.lib")

#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")

#pragma comment(lib, "libcurl.lib")

#pragma comment(lib, "pthreadVC2.lib")
#pragma comment(lib, "websockets.lib")


#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#pragma comment(lib, "vld.lib")
#endif
#endif

const char * FWVersion()
{
	return "1.0.0";
}
