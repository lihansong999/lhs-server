#pragma once

#include "Local.h"

//����UTF8�ַ���������
extern int UTF8_STRLEN(const char * utf8);

//UTF8ת��Ϊ˫�ֽ�Unicode
extern std::wstring UTF8_2_UNICODE(const char * utf8);

//˫�ֽ�Unicodeת��ΪUTF8
extern std::string UNICODE_2_UTF8(const wchar_t * unicode);

//˫�ֽ�Unicodeת��Ϊ��ǰϵͳĬ�ϵ�ANSI����ҳ
extern std::string UNICODE_2_ANSI(const wchar_t * unicode);

//��ǰϵͳĬ�ϵ�ANSI����ҳת��Ϊ˫�ֽ�Unicode
extern std::wstring ANSI_2_UNICODE(const char * ansi);

//UTF8ת��Ϊ��ǰϵͳĬ�ϵ�ANSI����ҳ
extern std::string UTF8_2_ANSI(const char * utf8);

//��ǰϵͳĬ�ϵ�ANSI����ҳת��ΪUTF8
extern std::string ANSI_2_UTF8(const char * ansi);
