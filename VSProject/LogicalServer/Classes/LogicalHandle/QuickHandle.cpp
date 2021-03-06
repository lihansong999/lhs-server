#include "stdafx.h"
#include "QuickHandle.h"
#include "DataHandle.h"
#include "../LogicalMain.h"
#include "../LogicalNetwork/NetworkTools.h"
#include "../LogicalNetwork/TcpOutManage.h"
#include "../LogicalNetwork/TcpSvcManage.h"
#include "../LogicalNetwork/WsSvcManage.h"

FW_NS_USEING;

//压入基础数据--客户端请求的数据处理
#define PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(ld) \
	do{  \
		ld->PushBackValue<int>(DATA_H_CLIENT_REQUEST); \
		ld->PushBackValue<int>(mainID); \
		ld->PushBackValue<int>(assistantID); \
		ld->PushBackValue<SvcNetMatch>(svcNetMatch); \
		ld->PushBackValue<FWSvcSocketInfo>(svcSocketInfo); \
			}while(false)

//压入基础数据--中心服请求的数据处理
#define PUSH_BASE_FOR_DATA_H_CENTER_REQUEST(ld) \
	do{  \
		ld->PushBackValue<int>(DATA_H_CENTER_REQUEST); \
		ld->PushBackValue<int>(mainID); \
		ld->PushBackValue<int>(assistantID); \
			}while(false)


static QuickHandle * _QuickHandle = nullptr;

QuickHandle::QuickHandle()
{
	_QuickHandle = this;
}

QuickHandle::~QuickHandle()
{
	this->Stop();
	_QuickHandle = nullptr;
}

QuickHandle * QuickHandle::GetInstance()
{
	return _QuickHandle;
}

void QuickHandle::_deleteLogicData(FWLogicDataBase * dataBase)
{
	delete dataBase;
}

void QuickHandle::_onLogicDataHandler(FWLogicDataBase * dataBase, const char * threadID, void * customArg)
{
	FWLogicDataGeneral * logicDataGeneral = dynamic_cast<FWLogicDataGeneral*>(dataBase);
	if (!logicDataGeneral)
	{
		return;
	}
	switch ((QuickHandleType)logicDataGeneral->PopFrontValue<int>())
	{
	case QUICK_H_CLIENT_ARRIVED:
	{
		SvcNetMatch svcNetMatch = logicDataGeneral->PopFrontValue<SvcNetMatch>();
		FWSvcSocketInfo svcSocketInfo = logicDataGeneral->PopFrontValue<FWSvcSocketInfo>();
		unsigned int size = logicDataGeneral->PopFrontValue<unsigned int>();
		char * data = logicDataGeneral->PopFrontValue<char*>();
		unsigned int offset = 0;
		while (offset < size)
		{
			int validSize = 0;
			Message::MsgPackageRecv msgPackageRecv((data + offset), size - offset, &validSize);
			if (validSize == 0 || msgPackageRecv.GetErrorCode() != 0)
			{
				CloseSvcSocket(svcNetMatch);
				break;
			}
			long long r = this->_clientMsgDispense(svcNetMatch, svcSocketInfo, &msgPackageRecv);
			if (r == -1)
			{
				CloseSvcSocket(svcNetMatch);
				break;
			}
			else if (r > 0)
			{
				long long invl = (r < DELAY_CLOSE_SOCKET_TIME_MAX) ? (r) : (DELAY_CLOSE_SOCKET_TIME_MAX);
				LogicalMain::GetInstance()->GetSchedule()->Add([svcNetMatch](long long invl, Framework::FW_ID id)->void {
					CloseSvcSocket(svcNetMatch);
				}, invl, 1, true);
				break;
			}
			offset += validSize;
		}
		FW_FREE(data);
	}
		break;
	case QUICK_H_CENTER_ARRIVED:
	{
		unsigned int size = logicDataGeneral->PopFrontValue<unsigned int>();
		char * data = logicDataGeneral->PopFrontValue<char*>();
		unsigned int offset = 0;
		while (offset < size)
		{
			int validSize = 0;
			Message::MsgPackageRecv msgPackageRecv((data + offset), size - offset, &validSize);
			if (validSize == 0 || msgPackageRecv.GetErrorCode() != 0)
			{
				TcpOutManage::GetInstance()->CloseCenter();
				break;
			}
			if (!this->_centerMsgDispense(&msgPackageRecv))
			{
				TcpOutManage::GetInstance()->CloseCenter();
				break;
			}
			offset += validSize;
		}
		FW_FREE(data);
	}
		break;
	case QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE:
	{
		SvcNetMatch svcNetMatch = logicDataGeneral->PopFrontValue<SvcNetMatch>();
		FWLogicDataGeneral * ld = new FWLogicDataGeneral();
		ld->PushBackValue<int>(DATA_H_INSIDE_CLIENT_SOCKET_CLOSE);
		ld->PushBackValue<SvcNetMatch>(svcNetMatch);
		DataHandle::GetInstance()->PushLogicData(ld);
	}
		break;
	default:
		break;
	}
}

long long QuickHandle::_clientMsgDispense(const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();
	switch (mainID)
	{
	case Message::Common::MSG_MAIN_TEST:
	{
		return this->_clientTest(svcNetMatch, svcSocketInfo, msgPackageRecv);
	}
		break;
	case Message::Logical::MSG_MAIN_LOGIN:
	{
		return this->_clientLogin(svcNetMatch, svcSocketInfo, msgPackageRecv);
	}
		break;
	case Message::Logical::MSG_MAIN_MATCH:
	{
		return this->_clientMatch(svcNetMatch, svcSocketInfo, msgPackageRecv);
	}
		break;
	default:
		return -1;
		break;
	}
}

long long QuickHandle::_clientTest(const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();
	if (assistantID == Message::Common::MSG_ASS_TEST_PROBE)
	{
		Message::Common::ProbeReq probeReq;
		if (!msgPackageRecv->Deserialize(&probeReq))
			return -1;
		if (probeReq.Check.Compare(MESSAGE_PROBE_CHECK) != 0)
			return -1;
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(logicDataGeneral);
		DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
		return 0;
	}
	else if (assistantID == Message::Common::MSG_ASS_TEST_HEARTBEAT)
	{
		Message::Common::BeartbeatReq beartbeatReq;
		if (!msgPackageRecv->Deserialize(&beartbeatReq))
			return -1;
		Message::Common::BeartbeatRes beartbeatRes;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &beartbeatRes);
		SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return 0;
	}

	return -1;
}

long long QuickHandle::_clientLogin(const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();

	Message::Logical::LoginReq loginReq;
	if (!msgPackageRecv->Deserialize(&loginReq))
		return -1;

	if (assistantID == Message::Logical::MSG_ASS_LOGIN_DYNAMIC_PASSWORD)
	{
		if (!ServerCommon::DynaPwdValidity(loginReq.DynaPwd.C_Str()))
		{
			Message::MsgPackageSend msgPackageSend(mainID, assistantID, Message::Logical::ERR_LOGIN_BAD1, nullptr);
			SendDataSvcSocket(svcNetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
			return DELAY_CLOSE_SOCKET_TIME_FOR_SENT;
		}
		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(logicDataGeneral);
		logicDataGeneral->PushBackValue<PlayerID_t>(loginReq.PlayerID);
		logicDataGeneral->PushBackString(loginReq.DynaPwd.C_Str());
		DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
		return 0;
	}

	return -1;
}

long long QuickHandle::_clientMatch(const SvcNetMatch & svcNetMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();

	if (assistantID == Message::Logical::MSG_ASS_MATCH_REQ_ADD)
	{
		Message::Logical::AddMatchReq addMatchReq;
		if (!msgPackageRecv->Deserialize(&addMatchReq))
			return -1;

		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(logicDataGeneral);
		DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
		return 0;
	}
	else if (assistantID == Message::Logical::MSG_ASS_MATCH_REQ_QUIT)
	{
		Message::Logical::QuitMatchReq quitMatchReq;
		if (!msgPackageRecv->Deserialize(&quitMatchReq))
			return -1;

		FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
		PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(logicDataGeneral);
		DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
		return 0;
	}

	return -1;
}

bool QuickHandle::_centerMsgDispense(const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();
	switch (mainID)
	{
	case Message::Center::MSG_MAIN_LOGIN:
	{
		return this->_centerLogin(msgPackageRecv);
	}
		break;
	default:
		return false;
		break;
	}
}

bool QuickHandle::_centerLogin(const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();
	Message::Center::LoginRes loginRes;
	if (!msgPackageRecv->Deserialize(&loginRes))
		return false;

	if (assistantID == Message::Center::MSG_ASS_LOGIN_LOGICAL)
	{
		if (loginRes.IsSucceed)
		{
			FW_PRINT("%s", "中心服登录成功");
		}
		else
		{
			FW_LOG_ERROR("%s", "中心服登录失败，检查配置是否冲突");
		}
		return true;
	}

	return false;
}