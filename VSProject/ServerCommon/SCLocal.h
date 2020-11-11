#ifndef __SERVERCOMMON_LOCAL_H__
#define __SERVERCOMMON_LOCAL_H__

#include "../Framework/Framework.h"

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#include "../Framework/ThirdParty/MemoryLeakDetector/include/vld.h"
#endif
#endif

#if defined(SERVERCOMMON_EXPORTS)
#define SC_DLL     __declspec(dllexport)
#else
#define SC_DLL     __declspec(dllimport)
#endif

#define SC_NS_BEGIN		namespace ServerCommon {
#define SC_NS_END		}
#define SC_NS_USEING	using namespace ServerCommon


#endif //!__SERVERCOMMON_LOCAL_H__