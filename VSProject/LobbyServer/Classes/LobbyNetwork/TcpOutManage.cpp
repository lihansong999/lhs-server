#include "stdafx.h"
#include "TcpOutManage.h"
#include "../LobbyMain.h"
#include "../LobbyHandle/DataHandle.h"
#include "../LobbyHandle/QuickHandle.h"

FW_NS_USEING;

#define CENTER_RECONNECT_SEC	3

static TcpOutManage * _TcpOutManage = nullptr;

TcpOutManage::TcpOutManage()
	:_centerPort(0)
{
	_TcpOutManage = this;
}

TcpOutManage::~TcpOutManage()
{
	this->Stop();
	_TcpOutManage = nullptr;
}

TcpOutManage * TcpOutManage::GetInstance()
{
	return _TcpOutManage;
}

bool TcpOutManage::Start()
{
	//��ʱ������һ�����ķ���ֻ��Ҫ֧��һ������
	return FWTcpOutManageBase::Start(1);
}

void TcpOutManage::Stop()
{
	FWTcpOutManageBase::Stop();
}

void TcpOutManage::InitCenterConnectConfig(const std::string & host, int port)
{
	_centerHost = host;
	_centerPort = port;
}

void TcpOutManage::ConnectCenter()
{
	this->Connect(_centerHost.c_str(), (unsigned short)_centerPort, Center);
}

bool TcpOutManage::SendDataCenter(const char * pData, int size)
{
	return this->SendDataTcpOutSocket(_centerNetMatch, pData, size);
}

void TcpOutManage::CloseCenter()
{
	this->CloseTcpOutSocket(_centerNetMatch);
}

void TcpOutManage::_onTcpOutOverloaded(FW_ID custom)
{
	if (custom == Center)
	{
		FW_LOG_WRNING("%s%d%s", "���ķ�����ʧ�ܣ��޷�����Socket���Ѵﵽ���������������", CENTER_RECONNECT_SEC, "����ٴ�������");
		std::thread t = std::thread([this]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(CENTER_RECONNECT_SEC));
			this->ConnectCenter();
		});
		t.detach();
	}
}

void TcpOutManage::_onTcpOutConnectResult(bool succeed, const FWNetMatch & netMatch, FW_ID custom)
{
	if (custom == Center)
	{
		if (succeed)
		{
			FW_PRINT("%s", "���ķ����ӳɹ�");
			_centerNetMatch = netMatch;
			//��¼���ķ�
			Message::Center::LoginReq loginReq;
			loginReq.ServerID = LobbyMain::GetInstance()->GetLobbyID();
			Message::MsgPackageSend msgPackageSend(Message::Center::MSG_MAIN_LOGIN, Message::Center::MSG_ASS_LOGIN_LOBBY, &loginReq);
			this->SendDataCenter(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
		else
		{
			FW_LOG_WRNING("%s%d%s", "���ķ�����ʧ�ܣ�", CENTER_RECONNECT_SEC, "����ٴ�������");
			std::thread t = std::thread([this]() {
				std::this_thread::sleep_for(std::chrono::seconds(CENTER_RECONNECT_SEC));
				this->ConnectCenter();
			});
			t.detach();
		}
	}
}

unsigned int TcpOutManage::_onTcpOutRecvTest(const char * buf, unsigned int size, FW_ID custom)
{
	if (custom == Center)
	{
		int validCount = 0;
		return (unsigned int)Message::MsgPackageRecv::TestBufferValidity(buf, size, &validCount);
	}

	return -1;
}

void TcpOutManage::_onTcpOutRecvCompleted(const FWNetMatch & netMatch, char * newBuf, unsigned int size, FW_ID custom)
{
	if (custom == Center)
	{
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		logicDataGeneral->PushBackValue<int>(QUICK_H_CENTER_ARRIVED);
		logicDataGeneral->PushBackValue<unsigned int>(size);
		logicDataGeneral->PushBackValue<char*>(newBuf);
		QuickHandle::GetInstance()->PushLogicData(logicDataGeneral);
	}
}

void TcpOutManage::_onTcpOutClose(const FWNetMatch & netMatch, FW_ID custom)
{
	if (custom == Center)
	{
		FW_PRINT("%s", "�����ķ������ѶϿ�");
		std::thread t = std::thread([this]() {
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			this->ConnectCenter();
		});
		t.detach();
	}
}