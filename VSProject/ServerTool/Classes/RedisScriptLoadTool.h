#pragma once
#include "Local.h"


class RedisScriptLoadTool
{
public:
	RedisScriptLoadTool();
	~RedisScriptLoadTool();

	static RedisScriptLoadTool * GetInstance();

	void Execute();

private:
	void _threadExecute();

private:
	volatile bool	_running;
	wchar_t			_defaultDir[1024];
};