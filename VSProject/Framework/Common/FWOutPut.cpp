#include "FWOutPut.h"


FW_NS_BEGIN


static FWOutPut _OutPut;

FWOutPut::FWOutPut()
	:_logFilePointer(nullptr)
	, _customPrintPrint(nullptr)
	, _customLogPrint(nullptr)
{
	_logMutex = new std::mutex();
	_printMutex = new std::mutex();
}

FWOutPut::~FWOutPut()
{
	if (_logFilePointer)
	{
		fclose((FILE*)_logFilePointer);
	}
	delete ((std::mutex*)_logMutex);
	delete ((std::mutex*)_printMutex);
}

FWOutPut * FWOutPut::GetInstance()
{
	return &_OutPut;
}

#define PRINTFORMATBUFFERSIZE	8192
static char _PrintFormatBuffer[PRINTFORMATBUFFERSIZE];
void FWOutPut::Print(const char * format, ...)
{
	((std::mutex*)_printMutex)->lock();
	va_list args;
	va_start(args, format);
	int r = vsnprintf(_PrintFormatBuffer, PRINTFORMATBUFFERSIZE - 6, format, args);
	va_end(args);
	if (r > 0)
	{
		_PrintFormatBuffer[r] = '\r';
		_PrintFormatBuffer[r + 1] = '\n';
		_PrintFormatBuffer[r + 2] = '\0';
		if (_customPrintPrint)
		{
			(*_customPrintPrint)(_PrintFormatBuffer);
		}
		else
		{
			printf_s("%s", _PrintFormatBuffer);
		}
#if defined(_DEBUG)
		OutputDebugStringA(_PrintFormatBuffer);
#endif
	}
	((std::mutex*)_printMutex)->unlock();
}

void FWOutPut::PrintNotAutoNewlines(const char * format, ...)
{
	((std::mutex*)_printMutex)->lock();
	va_list args;
	va_start(args, format);
	int r = vsnprintf(_PrintFormatBuffer, PRINTFORMATBUFFERSIZE - 6, format, args);
	va_end(args);
	if (r > 0)
	{
		_PrintFormatBuffer[r] = '\0';
		if (_customPrintPrint)
		{
			(*_customPrintPrint)(_PrintFormatBuffer);
		}
		else
		{
			printf_s("%s", _PrintFormatBuffer);
		}
#if defined(_DEBUG)
		OutputDebugStringA(_PrintFormatBuffer);
#endif
	}
	((std::mutex*)_printMutex)->unlock();
}

void FWOutPut::CustomPrintPrint(void(*custom)(const char *))
{
	_customPrintPrint = custom;
}

#define LOGFORMATBUFFERSIZE	8192
static char _LogFormatBuffer[LOGFORMATBUFFERSIZE];
void FWOutPut::Log(LOGTYPE logType, const char * functionName, const char * format, ...)
{
	((std::mutex*)_logMutex)->lock();
	std::string finalFormat;
	finalFormat.reserve(512);
	switch (logType)
	{
	case FWOutPut::WARNING:
		finalFormat = "WRNING ";
		break;
	case FWOutPut::WRONG:
		finalFormat = "ERROR ";
		break;
	case FWOutPut::NORMAL:
	default:
		finalFormat = "LOG ";
		break;
	}
	memset(&(_LogFormatBuffer[LOGFORMATBUFFERSIZE - 6]), 0, 6);
	va_list args;
	va_start(args, format);
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	sprintf_s(_LogFormatBuffer, LOGFORMATBUFFERSIZE, "[%04d-%02d-%02d %02d:%02d:%02d] [%s]: ", (int)sysTime.wYear, (int)sysTime.wMonth, (int)sysTime.wDay, (int)sysTime.wHour, (int)sysTime.wMinute, (int)sysTime.wSecond, functionName);
	finalFormat += _LogFormatBuffer;
	finalFormat += format;
	int r = vsnprintf(_LogFormatBuffer, LOGFORMATBUFFERSIZE - 6, finalFormat.c_str(), args);
	va_end(args);
	if (r > 0)
	{
		_LogFormatBuffer[r] = '\n';
		_LogFormatBuffer[r + 1] = '\0';
		this->_writeLogToFile(_LogFormatBuffer, r + 1);
		_LogFormatBuffer[r] = '\r';
		_LogFormatBuffer[r + 1] = '\n';
		_LogFormatBuffer[r + 2] = '\0';
		if (_customLogPrint)
		{
			(*_customLogPrint)(logType, _LogFormatBuffer);
		}
		else
		{
			printf_s("%s", _LogFormatBuffer);
		}
#if defined(_DEBUG)
		OutputDebugStringA(_LogFormatBuffer);
#endif
	}
	((std::mutex*)_logMutex)->unlock();
}

void FWOutPut::CustomLogPrint(void(*custom)(FWOutPut::LOGTYPE, const char *))
{
	_customLogPrint = custom;
}

void * FWOutPut::_getLogFilePointer()
{
	if (_logFilePointer)
	{
		return _logFilePointer;
	}
	std::string path;
	char buffer[1024/*MAX_PATH*/];
	DWORD r = GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
	if (r > 0)
	{
		path = buffer;
		std::string::size_type pos = path.rfind(".exe");
		if (pos != std::string::npos && pos == path.size() - 4)
		{
			path.replace(pos, path.size() - pos, "_Log.txt");
		}
		else
		{
			path = "";
		}
	}
	if (path.compare("") == 0)
	{
		return nullptr;
	}
	FILE * fp = _fsopen(path.c_str(), "a+", _SH_DENYWR);
	if (!fp)
	{
		errno_t err = errno;
		return nullptr;
	}
	_logFilePointer = fp;
	return _logFilePointer;
}

void FWOutPut::_writeLogToFile(const char * buffer, int size)
{
	if (buffer && size > 0)
	{
		FILE * fp = (FILE*)this->_getLogFilePointer();
		if (fp)
		{
			fwrite(buffer, 1, (size_t)size, fp);
			fflush(fp);
		}
	}
}



FW_NS_END