#include "stdafx.h"
#include "TcpSvcManage.h"
#include "NetworkTools.h"
#include "../LobbyMain.h"
#include "../LobbyHandle/DataHandle.h"
#include "../LobbyHandle/QuickHandle.h"

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

bool TcpSvcManage::_onTcpSvcReject(const char * ip46, unsigned short port)
{
	return GetSvcConnectedCount() >= LobbyMain::GetInstance()->GetMaxClients();
}

void TcpSvcManage::_onTcpSvcOverloaded()
{
	FW_LOG_WRNING("%s", "无法分配Socket，服务器已达到最大连接数。");
}

void TcpSvcManage::_onTcpSvcAccepted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{
	if (!LobbyMain::GetInstance()->GetSvcNetMatchesLRU()->Add(SCSNMT_TCP, netMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}
}

unsigned int TcpSvcManage::_onTcpSvcRecvTest(const char * buf, unsigned int size)
{
	int validCount = 0;
	return (unsigned int)Message::MsgPackageRecv::TestBufferValidity(buf, size, &validCount);
}

void TcpSvcManage::_onTcpSvcRecvCompleted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size)
{
	SvcNetMatch svcNetMatch(SCSNMT_TCP, netMatch);
	if (!LobbyMain::GetInstance()->GetSvcNetMatchesLRU()->Find(svcNetMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}

	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_CLIENT_ARRIVED);
	logicDataGeneral->PushBackValue<SvcNetMatch>(svcNetMatch);
	logicDataGeneral->PushBackValue<FWSvcSocketInfo>(svcSocketInfo);
	logicDataGeneral->PushBackValue<unsigned int>(size);
	logicDataGeneral->PushBackValue<char*>(newBuf);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}

void TcpSvcManage::_onTcpSvcClose(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{
	SvcNetMatch svcNetMatch(SCSNMT_TCP, netMatch);
	if (!LobbyMain::GetInstance()->GetSvcNetMatchesLRU()->Remove(svcNetMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}
	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE);
	logicDataGeneral->PushBackValue<SvcNetMatch>(svcNetMatch);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}