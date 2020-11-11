#include "stdafx.h"
#include "../BlackBoxTestDlg.h"


char ModuleFileDirectory[1024/*MAX_PATH*/] = { 0 };
static std::mutex MutexFileDirectory;
const char * GetModuleFileDirectory()
{
	if (ModuleFileDirectory[0] == '\0')
	{
		MutexFileDirectory.lock();
		if (ModuleFileDirectory[0] == '\0')
		{
			char buffer[1024/*MAX_PATH*/];
			DWORD r = GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
			if (r > 0)
			{
				int si = -1;
				for (int i = (int)r; i >= 0; i--)
				{
					if (buffer[i] == '\\')
					{
						si = i - 1;
						break;
					}
				}
				for (int i = si; i >= 0; i--)
				{
					ModuleFileDirectory[i] = buffer[i];
				}
			}
		}
		MutexFileDirectory.unlock();
	}
	return ModuleFileDirectory;
}

