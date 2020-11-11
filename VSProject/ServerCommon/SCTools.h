#ifndef __SERVERCOMMON_TOOLS_H__
#define __SERVERCOMMON_TOOLS_H__

#include "SCLocal.h"

SC_NS_BEGIN


extern bool SC_DLL AccountValidity(const char * account);

extern bool SC_DLL PasswordValidity(const char * password);

extern bool SC_DLL DynaPwdValidity(const char * dynaPwd);

extern bool SC_DLL UnionidValidity(const char * unionid);

extern bool SC_DLL NicknameValidity(const char * nickname);

extern bool SC_DLL SexValidity(int sex);


SC_NS_END


#endif //!__SERVERCOMMON_TOOLS_H__