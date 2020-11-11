#pragma once
#include "../Framework/Framework.h"
#include "../ServerCommon/ServerCommon.h"

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#include "../Framework/ThirdParty/MemoryLeakDetector/include/vld.h"
#endif
#endif

SC_NS_USEING;