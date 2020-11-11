#pragma once
#include "../LogicalBase/Local.h"
#include "../LogicalBase/TypeDefine.h"
#include "HandleTypeDef.h"

class QuickHandle : public Framework::FWLogicHandlerBase
{
public:
	QuickHandle();
	~QuickHandle();

	static QuickHandle * GetInstance();

protected:
	virtual void _deleteLogicData(Framework::FWLogicDataBase * dataBase) override;

	virtual void _onLogicDataHandler(Framework::FWLogicDataBase * dataBase, const char * threadID, void * customArg) override;

private:
	long long _clientMsgDispense(const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

	long long _clientTest(const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

	long long _clientLogin(const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

	long long _clientMatch(const SvcNetMatch & svcNetMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

private:
	bool _centerMsgDispense(const Message::MsgPackageRecv * msgPackageRecv);

	bool _centerLogin(const Message::MsgPackageRecv * msgPackageRecv);
};
