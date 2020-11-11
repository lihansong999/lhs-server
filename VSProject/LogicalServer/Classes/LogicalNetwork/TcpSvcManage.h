#pragma once
#include "../LogicalBase/Local.h"
#include "../LogicalBase/TypeDefine.h"


class TcpSvcManage : public Framework::FWTcpSvcManageBase
{
public:
	TcpSvcManage();
	~TcpSvcManage();
	
	static TcpSvcManage * GetInstance();

protected:
	virtual bool _onTcpSvcReject(const char * ip46, unsigned short port) override;

	virtual void _onTcpSvcOverloaded() override;

	virtual void _onTcpSvcAccepted(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

	virtual unsigned int _onTcpSvcRecvTest(const char * buf, unsigned int size) override;

	virtual void _onTcpSvcRecvCompleted(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) override;

	virtual void _onTcpSvcClose(const Framework::FWNetMatch & netMatch, const Framework::FWSvcSocketInfo & svcSocketInfo) override;

private:

};