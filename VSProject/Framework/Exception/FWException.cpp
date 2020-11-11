#include "FWException.h"
#include "../Common/FWOutPut.h"
#include <DbgHelp.h>

FW_NS_BEGIN


void MyInvalidParameterHandler(const wchar_t* expression,
	const wchar_t* function,
	const wchar_t* file,
	unsigned int line,
	uintptr_t pReserved)
{
	throw 1;
}

void MyPurecallHandler(void)
{
	throw 1;
}

int MyNewHandler(size_t size)
{
	throw 1;
	return 0;
}

void ResetHandler()
{
	//无效参数传递，比如printf(NULL)
	_invalid_parameter_handler oldInvalidParameterHandler = _set_invalid_parameter_handler(MyInvalidParameterHandler);
	FW_PRINT("%s%p", "invalid_parameter_handler 已替换，原函数地址 = ", oldInvalidParameterHandler);

	//纯虚函数调用错误，比如在父类析构中使用子类指针调用了一个父类声明的纯虚函数
	_purecall_handler oldPurecallHandler = _set_purecall_handler(MyPurecallHandler);
	FW_PRINT("%s%p", "purecall_handler 已替换，原函数地址 = ", oldPurecallHandler);

	//内存分配错误，比如分配一块超大内存
	_PNH oldNewHandler = _set_new_handler(MyNewHandler);
	FW_PRINT("%s%p", "new_handler 已替换，原函数地址 = ", oldNewHandler);
}

void DeleteSetUnhandledExceptionFilter()
{
#if defined(_M_IX86)
	HMODULE kernel32 = LoadLibraryA("kernel32.dll");
	if (kernel32 == NULL)
	{
		return;
	}
	void * lpfnSetUnhandledExceptionFilter = (void*)GetProcAddress(kernel32, "SetUnhandledExceptionFilter");
	if (lpfnSetUnhandledExceptionFilter)
	{
		unsigned char expected_code[] = {
			0x8B, 0xFF, // mov edi,edi
			0x55,       // push ebp
			0x8B, 0xEC, // mov ebp,esp
		};
		if (memcmp(expected_code, lpfnSetUnhandledExceptionFilter, sizeof(expected_code)) == 0)
		{
			unsigned char new_code[] = {
				0x33, 0xC0,       // xor eax,eax
				0xC2, 0x04, 0x00, // ret 4
			};
			static_assert(sizeof(expected_code) == sizeof(new_code), "");
			DWORD dwOldFlag, dwTempFlag;
			if (VirtualProtectEx(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code), PAGE_EXECUTE_READWRITE, &dwOldFlag) != FALSE)
			{
				WriteProcessMemory(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, new_code, sizeof(new_code), NULL);
				VirtualProtectEx(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code), dwOldFlag, &dwTempFlag);
				FlushInstructionCache(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code));
			}
		}
	}
	FreeLibrary(kernel32);
#elif defined(_M_X64)
	HMODULE kernel32 = LoadLibraryA("kernel32.dll");
	if (kernel32 == NULL)
	{
		return;
	}
	void * lpfnSetUnhandledExceptionFilter = (void*)GetProcAddress(kernel32, "SetUnhandledExceptionFilter");
	if (lpfnSetUnhandledExceptionFilter)
	{
		unsigned char expected_code[] = {
			0x48, 0x8b, 0xc4,	// mov rax,rsp
		};
		if (memcmp(expected_code, lpfnSetUnhandledExceptionFilter, sizeof(expected_code)) == 0)
		{
			unsigned char new_code[] = {
				0x33, 0xC0,		// xor eax,eax
				0xC3,			// ret
			};
			static_assert(sizeof(expected_code) == sizeof(new_code), "");
			DWORD dwOldFlag, dwTempFlag;
			if (VirtualProtectEx(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code), PAGE_EXECUTE_READWRITE, &dwOldFlag) != FALSE)
			{
				WriteProcessMemory(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, new_code, sizeof(new_code), NULL);
				VirtualProtectEx(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code), dwOldFlag, &dwTempFlag);
				FlushInstructionCache(GetCurrentProcess(), lpfnSetUnhandledExceptionFilter, sizeof(new_code));
			}
		}
	}
	FreeLibrary(kernel32);
#else
#error not supported
#endif
}

LONG WINAPI ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo)
{
	static std::mutex MiniDumpWriteDumpLock;

	if (IsDebuggerPresent())
	{
		return EXCEPTION_CONTINUE_SEARCH;
	}
	HMODULE DbgHelp = LoadLibraryA("dbghelp.dll");
	if (DbgHelp == NULL)
	{
		return EXCEPTION_CONTINUE_SEARCH;
	}
	typedef BOOL(WINAPI *LPFN_MiniDumpWriteDump)(
		HANDLE,
		DWORD,
		HANDLE,
		MINIDUMP_TYPE,
		PMINIDUMP_EXCEPTION_INFORMATION,
		PMINIDUMP_USER_STREAM_INFORMATION,
		PMINIDUMP_CALLBACK_INFORMATION
		);
	LPFN_MiniDumpWriteDump lpfnMiniDumpWriteDump = (LPFN_MiniDumpWriteDump)GetProcAddress(DbgHelp, "MiniDumpWriteDump");
	if (!lpfnMiniDumpWriteDump)
	{
		FreeLibrary(DbgHelp);
		return EXCEPTION_CONTINUE_SEARCH;
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
			SYSTEMTIME sysTime;
			GetLocalTime(&sysTime);
			sprintf_s(buffer, 1024/*MAX_PATH*/, "%s%04d-%02d-%02d-%02d-%02d-%02d%s", "_Dump_", (int)sysTime.wYear, (int)sysTime.wMonth, (int)sysTime.wDay, (int)sysTime.wHour, (int)sysTime.wMinute, (int)sysTime.wSecond, ".dmp");
			path.replace(pos, path.size() - pos, buffer);
		}
		else
		{
			path = "";
		}
	}
	if (path.compare("") == 0)
	{
		FreeLibrary(DbgHelp);
		return EXCEPTION_CONTINUE_SEARCH;
	}
	HANDLE DumpFile = CreateFileA(path.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (DumpFile == INVALID_HANDLE_VALUE)
	{
		FreeLibrary(DbgHelp);
		return EXCEPTION_CONTINUE_SEARCH;
	}
	MINIDUMP_EXCEPTION_INFORMATION mei;
	mei.ThreadId = GetCurrentThreadId();
	mei.ExceptionPointers = lpExceptionInfo;
	mei.ClientPointers = NULL;
	MiniDumpWriteDumpLock.lock();
	(*lpfnMiniDumpWriteDump)(GetCurrentProcess(), GetCurrentProcessId(), DumpFile, MiniDumpNormal, (lpExceptionInfo != NULL) ? &mei : NULL, NULL, NULL);
	MiniDumpWriteDumpLock.unlock();
	CloseHandle(DumpFile);
	FreeLibrary(DbgHelp);
	return EXCEPTION_EXECUTE_HANDLER;
}

void FWUseDump()
{
	static volatile LONG64 CallCount = 0;
	if (InterlockedIncrement64(&CallCount) != 1)
	{
		return;
	}

	ResetHandler();

	LPTOP_LEVEL_EXCEPTION_FILTER oldUnhandledExceptionFilter = SetUnhandledExceptionFilter(ExceptionFilter);
	FW_PRINT("%s%p", "UnhandledExceptionFilter 已替换，原函数地址 = ", oldUnhandledExceptionFilter);

	DeleteSetUnhandledExceptionFilter();
}


FW_NS_END
