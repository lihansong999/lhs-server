#include "stdafx.h"
#include "TcpSvcManage.h"
#include "../CenterMain.h"
#include "../CenterHandle/DataHandle.h"
#include "../CenterHandle/QuickHandle.h"

FW_NS_USEING;


static TcpSvcManage * _TcpSvcManage = nullptr;

TcpSvcManage::TcpSvcManage()
{
	_TcpSvcManage = this;
}

TcpSvcManage::~TcpSvcManage()
{
	this->Stop();
	_TcpSvcManage = nullptr;
}

TcpSvcManage * TcpSvcManage::GetInstance()
{
	return _TcpSvcManage;
}

void TcpSvcManage::_onTcpSvcOverloaded()
{
	FW_LOG_WRNING("%s", "无法分配Socket，服务器已达到最大连接数。");
}

void TcpSvcManage::_onTcpSvcAccepted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{

}

unsigned int TcpSvcManage::_onTcpSvcRecvTest(const char * buf, unsigned int size)
{
	int validCount = 0;
	return (unsigned int)Message::MsgPackageRecv::TestBufferValidity(buf, size, &validCount);
}

void TcpSvcManage::_onTcpSvcRecvCompleted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size)
{
	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_CLIENT_ARRIVED);
	logicDataGeneral->PushBackValue<FWNetMatch>(netMatch);
	logicDataGeneral->PushBackValue<FWSvcSocketInfo>(svcSocketInfo);
	logicDataGeneral->PushBackValue<unsigned int>(size);
	logicDataGeneral->PushBackValue<char*>(newBuf);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}

void TcpSvcManage::_onTcpSvcClose(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{
	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE);
	logicDataGeneral->PushBackValue<FWNetMatch>(netMatch);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}