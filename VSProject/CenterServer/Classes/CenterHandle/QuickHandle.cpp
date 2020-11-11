#include "stdafx.h"
#include "QuickHandle.h"
#include "DataHandle.h"
#include "../CenterBase/ServerInfoManage.h"
#include "../CenterMain.h"
#include "../CenterNetwork/TcpSvcManage.h"

FW_NS_USEING;

//压入基础数据--客户端请求的数据处理
#define PUSH_BASE_FOR_DATA_H_CLIENT_REQUEST(ld) \
	do{  \
		ld->PushBackValue<int>(DATA_H_CLIENT_REQUEST); \
		ld->PushBackValue<int>(mainID); \
		ld->PushBackValue<int>(assistantID); \
		ld->PushBackValue<FWNetMatch>(netMatch); \
		ld->PushBackValue<FWSvcSocketInfo>(svcSocketInfo); \
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
		FWNetMatch netMatch = logicDataGeneral->PopFrontValue<FWNetMatch>();
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
				TcpSvcManage::GetInstance()->CloseTcpSvcSocket(netMatch);
				break;
			}
			if (!this->_clientMsgDispense(netMatch, svcSocketInfo, &msgPackageRecv))
			{
				TcpSvcManage::GetInstance()->CloseTcpSvcSocket(netMatch);
				break;
			}
			offset += validSize;
		}
		FW_FREE(data);
	}
		break;
	case QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE:
	{
		FWNetMatch netMatch = logicDataGeneral->PopFrontValue<FWNetMatch>();
		if (!CenterMain::GetInstance()->GetOnlineServerInfoManage()->RemoveLobby(netMatch))
		{
			CenterMain::GetInstance()->GetOnlineServerInfoManage()->RemoveLogical(netMatch);
		}
	}
		break;
	default:
		break;
	}
}

bool QuickHandle::_clientMsgDispense(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	switch (mainID)
	{
	case Message::Center::MSG_MAIN_LOGIN:
	{
		return this->_clientLogin(netMatch, svcSocketInfo, msgPackageRecv);
	}
		break;
	case Message::Center::MSG_MAIN_FORWARD:
	{
		return this->_clientForward(netMatch, svcSocketInfo, msgPackageRecv);
	}
		break;
	default:
		return false;
		break;
	}
}

bool QuickHandle::_clientLogin(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();

	Message::Center::LoginReq loginReq;
	if (!msgPackageRecv->Deserialize(&loginReq))
		return false;

	if (assistantID == Message::Center::MSG_ASS_LOGIN_LOBBY)
	{
		Message::Center::LoginRes loginRes;
		loginRes.IsSucceed = true;
		ServerInfoManage * serverInfoManage = CenterMain::GetInstance()->GetOnlineServerInfoManage();
		LobbyServerInfo lobbyServerInfo;
		lobbyServerInfo.ServerID = loginReq.ServerID;
		lobbyServerInfo.NetMatch = netMatch;
		if (!serverInfoManage->AddLobby(lobbyServerInfo))
		{
			LobbyServerInfo tempLobbyServerInfo;
			if (serverInfoManage->FindLobby(lobbyServerInfo.ServerID, &tempLobbyServerInfo))
			{
				serverInfoManage->RemoveLobby(tempLobbyServerInfo.ServerID);
				TcpSvcManage::GetInstance()->CloseTcpSvcSocket(tempLobbyServerInfo.NetMatch);
				if (!serverInfoManage->AddLobby(lobbyServerInfo))
				{
					loginRes.IsSucceed = false;
				}
			}
			else
			{
				loginRes.IsSucceed = false;
			}
		}
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &loginRes);
		TcpSvcManage::GetInstance()->SendDataTcpSvcSocket(netMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return true;
	}
	else if (assistantID == Message::Center::MSG_ASS_LOGIN_LOGICAL)
	{
		Message::Center::LoginRes loginRes;
		loginRes.IsSucceed = true;
		ServerInfoManage * serverInfoManage = CenterMain::GetInstance()->GetOnlineServerInfoManage();
		LogicalServerInfo logicalServerInfo;
		logicalServerInfo.ServerID = loginReq.ServerID;
		logicalServerInfo.NetMatch = netMatch;
		if (!serverInfoManage->AddLogical(logicalServerInfo))
		{
			LogicalServerInfo tempLogicalServerInfo;
			if (serverInfoManage->FindLogical(logicalServerInfo.ServerID, &tempLogicalServerInfo))
			{
				serverInfoManage->RemoveLogical(tempLogicalServerInfo.ServerID);
				TcpSvcManage::GetInstance()->CloseTcpSvcSocket(tempLogicalServerInfo.NetMatch);
				if (!serverInfoManage->AddLogical(logicalServerInfo))
				{
					loginRes.IsSucceed = false;
				}
			}
			else
			{
				loginRes.IsSucceed = false;
			}
		}
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &loginRes);
		TcpSvcManage::GetInstance()->SendDataTcpSvcSocket(netMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return true;
	}

	return false;
}

bool QuickHandle::_clientForward(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, const Message::MsgPackageRecv * msgPackageRecv)
{
	const int mainID = msgPackageRecv->GetMainID();
	const int assistantID = msgPackageRecv->GetAssistantID();

	if (assistantID == Message::Center::MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET)
	{
		Message::Center::ForwardClosePlayerSocketReq forwardClosePlayerSocketReq;
		if (!msgPackageRecv->Deserialize(&forwardClosePlayerSocketReq))
			return false;
		LobbyServerInfo lobbyServerInfo;
		if (!CenterMain::GetInstance()->GetOnlineServerInfoManage()->FindLobby(forwardClosePlayerSocketReq.TargetServerID, &lobbyServerInfo))
		{
			return true;
		}
		Message::Center::ForwardClosePlayerSocketNote forwardClosePlayerSocketNote;
		forwardClosePlayerSocketNote.Type = forwardClosePlayerSocketReq.Type;
		forwardClosePlayerSocketNote.PlayerID = forwardClosePlayerSocketReq.PlayerID;
		forwardClosePlayerSocketNote.NetType = forwardClosePlayerSocketReq.NetType;
		forwardClosePlayerSocketNote.NetIndex = forwardClosePlayerSocketReq.NetIndex;
		forwardClosePlayerSocketNote.NetActivityID = forwardClosePlayerSocketReq.NetActivityID;
		Message::MsgPackageSend msgPackageSend(mainID, assistantID, &forwardClosePlayerSocketNote);
		TcpSvcManage::GetInstance()->SendDataTcpSvcSocket(lobbyServerInfo.NetMatch, msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		return true;
	}

	return false;
}