#pragma once
#include "../LogicalBase/Local.h"
#include "../LogicalBase/TypeDefine.h"


class TcpOutManage : protected Framework::FWTcpOutManageBase
{
	enum OutCustom
	{
		Center = 1,
	};
public:
	TcpOutManage();
	~TcpOutManage();

	static TcpOutManage * GetInstance();

	bool Start();

	void Stop();

	//Center
	void InitCenterConnectConfig(const std::string & host, int port);
	void ConnectCenter();
	bool SendDataCenter(const char * pData, int size);
	void CloseCenter();

protected:
	virtual void _onTcpOutOverloaded(Framework::FW_ID custom) override;

	virtual void _onTcpOutConnectResult(bool succeed, const Framework::FWNetMatch & netMatch, Framework::FW_ID custom) override;

	virtual unsigned int _onTcpOutRecvTest(const char * buf, unsigned int size, Framework::FW_ID custom) override;

	virtual void _onTcpOutRecvCompleted(const Framework::FWNetMatch & netMatch, char * newBuf, unsigned int size, Framework::FW_ID custom) override;

	virtual void _onTcpOutClose(const Framework::FWNetMatch & netMatch, Framework::FW_ID custom) override;

private:
	std::string	_centerHost;
	int			_centerPort;
	Framework::FWNetMatch _centerNetMatch;
};