#ifndef __FRAMEWORK_OUTPUT_H__
#define __FRAMEWORK_OUTPUT_H__

#include "../FWLocal.h"

FW_NS_BEGIN


class FW_DLL FWOutPut
{
public:
	enum LOGTYPE{
		NORMAL = 0,
		WARNING = 1,
		WRONG = 2,
	};
public:
	FWOutPut();
	~FWOutPut();

	static FWOutPut * GetInstance();

	/* 提示字符串打印，默认打印函数为printf */
	void __cdecl Print(const char * format, ...);

	/* 提示字符串打印，末尾不自动换行，默认打印函数为printf */
	void __cdecl PrintNotAutoNewlines(const char * format, ...);

	/* 可设置使用自定义打印函数替换默认打印函数，传入字符串都以\r\n\0结尾 */
	void CustomPrintPrint(void(*custom)(const char *));
	
	/* 日志打印及写入到日志文件，默认打印函数为printf，日志将被写到exe同级目录下 */
	void __cdecl Log(LOGTYPE logType, const char * functionName, const char * format, ...);

	/* 可设置使用自定义打印函数替换默认打印函数，传入字符串都以\r\n\0结尾 */
	void CustomLogPrint(void(*custom)(FWOutPut::LOGTYPE, const char *));

private:
	void * _getLogFilePointer();
	void _writeLogToFile(const char * buffer, int size);

private:
	void * _logFilePointer;
	void * _logMutex;
	void * _printMutex;
	void(*_customPrintPrint)(const char *);
	void(*_customLogPrint)(FWOutPut::LOGTYPE, const char *);
};


FW_NS_END


#endif //!__FRAMEWORK_OUTPUT_H__