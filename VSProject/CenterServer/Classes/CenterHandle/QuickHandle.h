#pragma once
#include "../CenterBase/Local.h"
#include "../CenterBase/TypeDefine.h"
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
	bool _clientMsgDispense(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

	bool _clientLogin(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);

	bool _clientForward(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv);
};
