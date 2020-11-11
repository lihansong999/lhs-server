#include "stdafx.h"
#include "DataHandle.h"
#include "QuickHandle.h"
#include "../CenterBase/ServerInfoManage.h"
#include "../CenterMain.h"
#include "../CenterNetwork/TcpSvcManage.h"

FW_NS_USEING;


static DataHandle * _DataHandle = nullptr;

DataHandle::DataHandle()
	:_mysqlPort(0)
	, _redisPort(0)
	, _redisSelectIndex(0)
{
	_DataHandle = this;
}

DataHandle::~DataHandle()
{
	this->Stop();
	_DataHandle = nullptr;
}

DataHandle * DataHandle::GetInstance()
{
	return _DataHandle;
}

void DataHandle::InitMySQLConnectConfig(const std::string & host, unsigned int port, const std::string & username, const std::string & password, const std::string & database)
{
	_mysqlHost = host; _mysqlPort = port; _mysqlUsername = username; _mysqlPassword = password; _mysqlDatabase = database;
}

void DataHandle::InitRedisConnectConfig(const std::string & host, int port, const std::string & password, int selectIndex)
{
	_redisHost = host; _redisPort = port; _redisPassword = password; _redisSelectIndex = selectIndex;
}

void * DataHandle::_onCreateThread(const char * threadID)
{
	DataManipulation * dataManipulation = new DataManipulation();
	dataManipulation->GetMySQLHelper()->Init(_mysqlHost.c_str(), _mysqlUsername.c_str(), _mysqlPassword.c_str(), _mysqlDatabase.c_str(), _mysqlPort, 0, "utf8mb4", 7, 20, 20);
	if (dataManipulation->GetMySQLHelper()->Connect())
	{
		FW_PRINT("%s%s%s", "MySQL数据库连接成功，在处理线程：", threadID, "中");
	}
	else
	{
		FW_LOG_ERROR("%s%s%s", "MySQL数据库初始连接失败，在处理线程：", threadID, "中");
	}
	dataManipulation->GetRedisHelper()->Init(_redisHost.c_str(), _redisPort, _redisPassword.c_str(), _redisSelectIndex, 7, 20);
	if (dataManipulation->GetRedisHelper()->Connect())
	{
		FW_PRINT("%s%s%s", "Redis连接成功，在处理线程：", threadID, "中");
	}
	else
	{
		FW_LOG_ERROR("%s%s%s", "Redis初始连接失败，在处理线程：", threadID, "中");
	}
	return dataManipulation;
}

void DataHandle::_onDeleteThread(const char * threadID, void * customArg)
{
	if (customArg)
	{
		DataManipulation * dataManipulation = (DataManipulation*)customArg;
		dataManipulation->GetMySQLHelper()->Disconnect();
		FW_PRINT("%s%s%s", "关闭MySQL数据库连接，在处理线程：", threadID, "中");
		dataManipulation->GetRedisHelper()->Disconnect();
		FW_PRINT("%s%s%s", "关闭Redis连接，在处理线程：", threadID, "中");
		delete dataManipulation;
	}
}

void DataHandle::_deleteLogicData(FWLogicDataBase * dataBase)
{
	delete dataBase;
}

void DataHandle::_onLogicDataHandler(FWLogicDataBase * dataBase, const char * threadID, void * customArg)
{
	if (!customArg)
	{
		return;
	}
	DataManipulation * dataManipulation = (DataManipulation*)customArg;
	FWLogicDataGeneral * logicDataGeneral = dynamic_cast<FWLogicDataGeneral*>(dataBase);
	if (!logicDataGeneral)
	{
		return;
	}
	switch ((DataHandleType)logicDataGeneral->PopFrontValue<int>())
	{
	case DATA_H_CLIENT_REQUEST:
	{
		const int mainID = logicDataGeneral->PopFrontValue<int>();
		const int assistantID = logicDataGeneral->PopFrontValue<int>();
		FWNetMatch netMatch = logicDataGeneral->PopFrontValue<FWNetMatch>();
		FWSvcSocketInfo svcSocketInfo = logicDataGeneral->PopFrontValue<FWSvcSocketInfo>();
		if (!this->_clientMsgDispense(dataManipulation, netMatch, svcSocketInfo, mainID, assistantID, logicDataGeneral))
		{
			TcpSvcManage::GetInstance()->CloseTcpSvcSocket(netMatch);
		}
	}
		break;
	case DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1:
	{
		if (dataManipulation->ResetRedisScriptSha1Manage(CenterMain::GetInstance()->GetRedisScriptSha1Manage()))
		{
			FW_PRINT("%s", "Redis脚本sha1载入成功");
		}
		else
		{
			FW_LOG_ERROR("%s", "Redis脚本sha1载入失败");
		}
	}
		break;
	case DATA_H_INSIDE_INIT_DATABASE_REDIS_DATA:
	{

	}
		break;
	default:
		break;
	}
}

bool DataHandle::_clientMsgDispense(DataManipulation * dataManipulation, const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, FWLogicDataGeneral * logicDataGeneral)
{
	switch (mainID)
	{
	default:
		return false;
		break;
	}
}