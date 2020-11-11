#pragma once

#include "Local.h"

//计算UTF8字符串的字数
extern int UTF8_STRLEN(const char * utf8);

//UTF8转换为双字节Unicode
extern std::wstring UTF8_2_UNICODE(const char * utf8);

//双字节Unicode转换为UTF8
extern std::string UNICODE_2_UTF8(const wchar_t * unicode);

//双字节Unicode转换为当前系统默认的ANSI代码页
extern std::string UNICODE_2_ANSI(const wchar_t * unicode);

//当前系统默认的ANSI代码页转换为双字节Unicode
extern std::wstring ANSI_2_UNICODE(const char * ansi);

//UTF8转换为当前系统默认的ANSI代码页
extern std::string UTF8_2_ANSI(const char * utf8);

//当前系统默认的ANSI代码页转换为UTF8
extern std::string ANSI_2_UTF8(const char * ansi);
