#pragma once
#include "../CenterBase/Local.h"
#include "../CenterBase/TypeDefine.h"


class TcpSvcManage : public Framework::FWTcpSvcManageBase
{
public:
	TcpSvcManage();
	~TcpSvcManage();
	
	static TcpSvcManage * GetInstance();

protected:
	virtual void _onTcpSvcOverloaded() override;

	virtual void _onTcpSvcAccepted(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

	virtual unsigned int _onTcpSvcRecvTest(const char * buf, unsigned int size) override;

	virtual void _onTcpSvcRecvCompleted(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) override;

	virtual void _onTcpSvcClose(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

private:

};