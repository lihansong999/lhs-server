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

	/* ��ʾ�ַ�����ӡ��Ĭ�ϴ�ӡ����Ϊprintf */
	void __cdecl Print(const char * format, ...);

	/* ��ʾ�ַ�����ӡ��ĩβ���Զ����У�Ĭ�ϴ�ӡ����Ϊprintf */
	void __cdecl PrintNotAutoNewlines(const char * format, ...);

	/* ������ʹ���Զ����ӡ�����滻Ĭ�ϴ�ӡ�����������ַ�������\r\n\0��β */
	void CustomPrintPrint(void(*custom)(const char *));
	
	/* ��־��ӡ��д�뵽��־�ļ���Ĭ�ϴ�ӡ����Ϊprintf����־����д��exeͬ��Ŀ¼�� */
	void __cdecl Log(LOGTYPE logType, const char * functionName, const char * format, ...);

	/* ������ʹ���Զ����ӡ�����滻Ĭ�ϴ�ӡ�����������ַ�������\r\n\0��β */
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