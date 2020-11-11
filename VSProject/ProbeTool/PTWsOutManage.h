#pragma once
#include "PTLocal.h"


class PTWsOutManage : protected Framework::FWWsOutManageBase
{
public:
	PTWsOutManage();
	~PTWsOutManage();

	static PTWsOutManage * GetInstance();

	bool Start();

	void Stop();

protected:
	virtual void _onWsOutOverloaded(Framework::FW_ID custom) override;

	virtual void _onWsOutConnectResult(bool succeed, const Framework::FWNetMatch & netMatch, Framework::FW_ID custom) override;

	virtual void _onWsOutMessage(const Framework::FWNetMatch & netMatch, char * newBuf, unsigned int size, Framework::FW_ID custom) override;

	virtual void _onWsOutClose(const Framework::FWNetMatch & netMatch, Framework::FW_ID custom) override;

private:

};