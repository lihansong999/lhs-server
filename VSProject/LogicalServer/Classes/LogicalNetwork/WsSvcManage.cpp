#include "stdafx.h"
#include "WsSvcManage.h"
#include "NetworkTools.h"
#include "../LogicalMain.h"
#include "../LogicalHandle/DataHandle.h"
#include "../LogicalHandle/QuickHandle.h"

FW_NS_USEING;


static WsSvcManage * _WsSvcManage = nullptr;

WsSvcManage::WsSvcManage()
{
	_WsSvcManage = this;
}

WsSvcManage::~WsSvcManage()
{
	this->Stop();
	_WsSvcManage = nullptr;
}

WsSvcManage * WsSvcManage::GetInstance()
{
	return _WsSvcManage;
}

bool WsSvcManage::_onWsSvcReject(const char * ip46, unsigned short port)
{
	return GetSvcConnectedCount() >= LogicalMain::GetInstance()->GetMaxClients();
}

void WsSvcManage::_onWsSvcEstablishe(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{
	if (!LogicalMain::GetInstance()->GetSvcNetMatchesLRU()->Add(SCSNMT_WS, netMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}
}

void WsSvcManage::_onWsSvcMessage(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size)
{
	SvcNetMatch svcNetMatch(SCSNMT_WS, netMatch);
	if (!LogicalMain::GetInstance()->GetSvcNetMatchesLRU()->Find(svcNetMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}
	if (size == 0)
	{
		if (newBuf)
			FW_FREE(newBuf);
		this->CloseWsSvcSocket(netMatch);
		return;
	}
	//强制与TCP消息流兼容（发送兼容在NetworkTools.cpp中）
	char * buf = (char*)FW_MALLOC(size + sizeof(int));
	int s = Message::htonInt32(size);
	memcpy(buf, &s, sizeof(int));
	memcpy(buf + sizeof(int), newBuf, size);
	FW_FREE(newBuf);
	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_CLIENT_ARRIVED);
	logicDataGeneral->PushBackValue<SvcNetMatch>(svcNetMatch);
	logicDataGeneral->PushBackValue<FWSvcSocketInfo>(svcSocketInfo);
	logicDataGeneral->PushBackValue<unsigned int>(size + sizeof(int));
	logicDataGeneral->PushBackValue<char*>(buf);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}

void WsSvcManage::_onWsSvcClose(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo)
{
	SvcNetMatch svcNetMatch(SCSNMT_WS, netMatch);
	if (!LogicalMain::GetInstance()->GetSvcNetMatchesLRU()->Remove(svcNetMatch))
	{
		FW_LOG_ERROR("%s", "严重的框架BUG。");
	}
	FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
	logicDataGeneral->PushBackValue<int>(QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE);
	logicDataGeneral->PushBackValue<SvcNetMatch>(svcNetMatch);
	QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
}