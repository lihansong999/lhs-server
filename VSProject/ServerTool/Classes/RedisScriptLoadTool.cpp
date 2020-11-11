#include "stdafx.h"
#include "RedisScriptLoadTool.h"
#include "../ServerToolDlg.h"
#include "WndMessageCustom.h"

FW_NS_USEING;


static RedisScriptLoadTool * _RedisScriptLoadTool = nullptr;

RedisScriptLoadTool::RedisScriptLoadTool()
	:_running(false)
{
	_defaultDir[0] = 0;
	_RedisScriptLoadTool = this;
}

RedisScriptLoadTool::~RedisScriptLoadTool()
{
	_RedisScriptLoadTool = nullptr;
}

RedisScriptLoadTool * RedisScriptLoadTool::GetInstance()
{
	return _RedisScriptLoadTool;
}

void RedisScriptLoadTool::Execute()
{
	if (_running)
	{
		MFCCommon::MCShowTipsOK(L"上次操作未完成之前不要重复操作。", NULL, 0);
		return;
	}
	_running = true;
	CString selectDir;
	if (!MFCCommon::MCBrowseDirectory(AfxGetMainWnd(), L"选择脚本文件夹", _defaultDir, selectDir))
	{
		FW_PRINT("%s", "未选择文件夹。");
		_running = false;
		return;
	}
	wcscpy_s(_defaultDir, _countof(_defaultDir), selectDir.GetString());
	std::thread t = std::thread(std::bind(&RedisScriptLoadTool::_threadExecute, this));
	t.detach();
}

void RedisScriptLoadTool::_threadExecute()
{
	std::string basePath = FW_UNICODE_2_ANSI(_defaultDir).C_Str();
	if (basePath.back() != '/' && basePath.back() != '\\')
	{
		basePath.append("\\");
	}
	struct _finddata_t fb;
	intptr_t handle = _findfirst(std::string(basePath + "*").c_str(), &fb);
	std::vector<std::string> scriptFilenameVector;
	if (handle != 0)
	{
		do
		{
			if (strcmp(fb.name, ".") != 0 && strcmp(fb.name, "..") != 0 && (fb.attrib & _A_SUBDIR) == 0)
			{
				std::string filename = fb.name;
				std::string::size_type pos = filename.rfind(".lua");
				if (filename.npos != pos && pos == filename.length() - 4)
				{
					scriptFilenameVector.push_back(filename);
				}
			}
		} while (_findnext(handle, &fb) == 0);
		_findclose(handle);
	}
	if (scriptFilenameVector.size() == 0)
	{
		FW_PRINT("%s", "没有找到需要加载的脚本");
		_running = false;
		return;
	}
	FW_PRINT("%s%d%s", "共找到", (int)scriptFilenameVector.size(),"个脚本");
	FW_PRINT("%s", "开始载入......");
	FWData fileData = FWFileIO::GetInstance()->LoadFileFromModuleFileDirectory("ServerToolConfig/RunConfig.json");
	if (fileData.IsNull())
	{
		FW_LOG_ERROR("%s", "无法读取基础配置文件。");
		_running = false;
		return;
	}
	rapidjson::GenericDocument<rapidjson::UTF8<> > configDocument;
	configDocument.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(fileData.GetPointer(), (size_t)fileData.GetSize());
	if (configDocument.HasParseError())
	{
		FW_LOG_ERROR("%s", "基础配置文件解析出错。");
		_running = false;
		return;
	}
	const rapidjson::GenericValue<rapidjson::UTF8<> > & mysqlConfig = configDocument["MySQL"];
	std::string mysqlHost = mysqlConfig["Host"].GetString();
	int mysqlPort = mysqlConfig["Port"].GetInt();
	std::string mysqlUsername = mysqlConfig["Username"].GetString();
	std::string mysqlPassword = mysqlConfig["Password"].GetString();
	std::string mysqlDatabase = mysqlConfig["Database"].GetString();
	const rapidjson::GenericValue<rapidjson::UTF8<> > & redisConfig = configDocument["Redis"];
	std::string redisHost = redisConfig["Host"].GetString();
	int redisPort = redisConfig["Port"].GetInt();
	std::string redisPassword = redisConfig["Password"].GetString();
	int selectIndex = redisConfig["Select"].GetInt();
	FW_PRINT("%s", "开始连接MySQL和Redis");
	DataManipulation dataManipulation;
	dataManipulation.GetMySQLHelper()->Init(mysqlHost.c_str(), mysqlUsername.c_str(), mysqlPassword.c_str(), mysqlDatabase.c_str(), mysqlPort, 0, "utf8mb4", 7, 20, 20);
	if (dataManipulation.GetMySQLHelper()->Connect())
	{
		FW_PRINT("%s", "MySQL连接成功");
	}
	else
	{
		FW_LOG_ERROR("%s", "MySQL连接失败");
		_running = false;
		return;
	}
	dataManipulation.GetRedisHelper()->Init(redisHost.c_str(), redisPort, redisPassword.c_str(), selectIndex, 7, 20);
	if (dataManipulation.GetRedisHelper()->Connect())
	{
		FW_PRINT("%s", "Redis连接成功");
	}
	else
	{
		FW_LOG_ERROR("%s", "Redis连接失败");
		_running = false;
		return;
	}
	for (std::vector<std::string>::iterator it = scriptFilenameVector.begin(); it != scriptFilenameVector.end(); it++)
	{
		std::string filePath = basePath + *it;
		FWString luaString = FWFileIO::GetInstance()->LoadFileToString(filePath.c_str());
		if (luaString.Size() == 0)
		{
			FW_LOG_ERROR("%s%s", "无法读取脚本 ", (*it).c_str());
			_running = false;
			return;
		}
		if (!dataManipulation.LoadRedisScriptSha1ToMySQL((*it).c_str(), luaString.C_Str()))
		{
			FW_LOG_ERROR("%s%s%s", "载入脚本 ", (*it).c_str(), " 失败");
			_running = false;
			return;
		}
	}
	FW_PRINT("%s%d%s", "载入完成，成功载入", (int)scriptFilenameVector.size(), "个脚本");
	_running = false;
}