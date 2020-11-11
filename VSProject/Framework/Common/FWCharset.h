#ifndef __FRAMEWORK_CHARSET_H__
#define __FRAMEWORK_CHARSET_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWString.h"

FW_NS_BEGIN


//计算UTF8字符串的字数
extern int FW_DLL FW_UTF8_STRLEN(const char * utf8);

//UTF8转换为双字节Unicode
extern FWWString FW_DLL FW_UTF8_2_UNICODE(const char * utf8);

//双字节Unicode转换为UTF8
extern FWString FW_DLL FW_UNICODE_2_UTF8(const wchar_t * unicode);

//双字节Unicode转换为当前系统默认的ANSI代码页
extern FWString FW_DLL FW_UNICODE_2_ANSI(const wchar_t * unicode);

//当前系统默认的ANSI代码页转换为双字节Unicode
extern FWWString FW_DLL FW_ANSI_2_UNICODE(const char * ansi);

//UTF8转换为当前系统默认的ANSI代码页
extern FWString FW_DLL FW_UTF8_2_ANSI(const char * utf8);

//当前系统默认的ANSI代码页转换为UTF8
extern FWString FW_DLL FW_ANSI_2_UTF8(const char * ansi);


FW_NS_END


#endif //!__FRAMEWORK_CHARSET_H__