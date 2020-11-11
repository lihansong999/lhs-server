#ifndef __FRAMEWORK_CHARSET_H__
#define __FRAMEWORK_CHARSET_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWString.h"

FW_NS_BEGIN


//����UTF8�ַ���������
extern int FW_DLL FW_UTF8_STRLEN(const char * utf8);

//UTF8ת��Ϊ˫�ֽ�Unicode
extern FWWString FW_DLL FW_UTF8_2_UNICODE(const char * utf8);

//˫�ֽ�Unicodeת��ΪUTF8
extern FWString FW_DLL FW_UNICODE_2_UTF8(const wchar_t * unicode);

//˫�ֽ�Unicodeת��Ϊ��ǰϵͳĬ�ϵ�ANSI����ҳ
extern FWString FW_DLL FW_UNICODE_2_ANSI(const wchar_t * unicode);

//��ǰϵͳĬ�ϵ�ANSI����ҳת��Ϊ˫�ֽ�Unicode
extern FWWString FW_DLL FW_ANSI_2_UNICODE(const char * ansi);

//UTF8ת��Ϊ��ǰϵͳĬ�ϵ�ANSI����ҳ
extern FWString FW_DLL FW_UTF8_2_ANSI(const char * utf8);

//��ǰϵͳĬ�ϵ�ANSI����ҳת��ΪUTF8
extern FWString FW_DLL FW_ANSI_2_UTF8(const char * ansi);


FW_NS_END


#endif //!__FRAMEWORK_CHARSET_H__