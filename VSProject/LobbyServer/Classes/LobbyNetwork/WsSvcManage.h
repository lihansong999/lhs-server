#pragma once
#include "../LobbyBase/Local.h"
#include "../LobbyBase/TypeDefine.h"


class WsSvcManage : public Framework::FWWsSvcManageBase
{
public:
	WsSvcManage();
	~WsSvcManage();
	
	static WsSvcManage * GetInstance();

protected:
	virtual bool _onWsSvcReject(const char * ip46, unsigned short port) override;

	virtual void _onWsSvcEstablishe(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

	virtual void _onWsSvcMessage(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) override;

	virtual void _onWsSvcClose(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

private:

};