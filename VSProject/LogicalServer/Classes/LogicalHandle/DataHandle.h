#pragma once
#include "../LogicalBase/Local.h"
#include "../LogicalBase/TypeDefine.h"
#include "HandleTypeDef.h"


class DataHandle : public Framework::FWLogicHandlerBase
{
public:
	DataHandle();
	~DataHandle();

	static DataHandle * GetInstance();

	void InitMySQLConnectConfig(const std::string & host, unsigned int port, const std::string & username, const std::string & password, const std::string & database);

	void InitRedisConnectConfig(const std::string & host, int port, const std::string & password, int selectIndex);

protected:
	virtual void * _onCreateThread(const char * threadID) override;

	virtual void _onDeleteThread(const char * threadID, void * customArg) override;

	virtual void _deleteLogicData(Framework::FWLogicDataBase * dataBase) override;

	virtual void _onLogicDataHandler(Framework::FWLogicDataBase * dataBase, const char * threadID, void * customArg) override;

private:
	long long _clientMsgDispense(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, Framework::FWLogicDataGeneral * logicDataGeneral);

	long long _clientTest(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, Framework::FWLogicDataGeneral * logicDataGeneral);

	long long _clientLogin(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, Framework::FWLogicDataGeneral * logicDataGeneral);

	long long _clientMatch(DataManipulation * dataManipulation, const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const int mainID, const int assistantID, Framework::FWLogicDataGeneral * logicDataGeneral);

private:
	bool _centerMsgDispense(DataManipulation * dataManipulation, Framework::FWLogicDataGeneral * logicDataGeneral);

private:
	std::string _mysqlHost;
	unsigned int _mysqlPort;
	std::string _mysqlUsername;
	std::string _mysqlPassword;
	std::string _mysqlDatabase;
	std::string _redisHost;
	int			_redisPort;
	std::string _redisPassword;
	int			_redisSelectIndex;
};