#ifndef __FRAMEWORK_TYPEDEFINE_H__
#define __FRAMEWORK_TYPEDEFINE_H__

#include "FWLocal.h"

FW_NS_BEGIN


typedef LONG64	FW_ID;


template <typename T>
bool isNegative(T v)
{
	return ((v >> (sizeof(T) * 8 - 1)) & 0x1) == 0x1;
}



FW_NS_END


#endif //!__FRAMEWORK_TYPEDEFINE_H__