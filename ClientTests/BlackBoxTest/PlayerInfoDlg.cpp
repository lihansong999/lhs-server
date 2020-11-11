// PlayerInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BlackBoxTest.h"
#include "PlayerInfoDlg.h"
#include "afxdialogex.h"
#include "Classes/Charset.h"


// CPlayerInfoDlg 对话框

IMPLEMENT_DYNAMIC(CPlayerInfoDlg, CDialog)

CPlayerInfoDlg::CPlayerInfoDlg(SocketThread * lobbySocketThread, SocketThread * logicalSocketThread, PLAYERID_T selfPlayerID, PLAYERID_T showPlayerID, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
{
	_lobbySocketThread = lobbySocketThread;
	_logicalSocketThread = logicalSocketThread;
	_selfPlayerID = selfPlayerID;
	_showPlayerID = showPlayerID;
}

CPlayerInfoDlg::~CPlayerInfoDlg()
{
	_lobbySocketThread->RemoveListener(this);
	_logicalSocketThread->RemoveListener(this);
}

void CPlayerInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlayerInfoDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CPlayerInfoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPlayerInfoDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void CPlayerInfoDlg::onMessage(SocketThread * socketThread, Message::MsgPackageRecv * pack)
{
	const int mainID = pack->GetMainID();
	const int assistantID = pack->GetAssistantID();
	const int errorCode = pack->GetErrorCode();
	if (errorCode != 0)
	{
		return;
	}
	if (strcmp(socketThread->GetName(), ST_NAME_LOBBY) == 0)
	{
		if (mainID == Message::Lobby::MSG_MAIN_REQUEST_PLAYERINFO)
		{
			Message::Lobby::PlayerInfoRes playerInfoRes;
			pack->Deserialize(&playerInfoRes);
			if (playerInfoRes.PlayerID == _showPlayerID)
			{
				((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(UTF8_2_UNICODE(playerInfoRes.Nickname.C_Str()).c_str());
				((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(GET_SEX_STRING_W(playerInfoRes.Sex));
				((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(playerInfoRes.LobbyServerID > 0 ? L"是" : L"否");
				((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(playerInfoRes.LogicalServerID > 0 ? L"是" : L"否");
				if (playerInfoRes.PlayerID == _selfPlayerID)
				{
					CString formatStr;
					formatStr.Format(L"%lld", playerInfoRes.Golds);
					((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(formatStr);
					formatStr.Format(L"%lld", playerInfoRes.Diamonds);
					((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(formatStr);
				}
				else
				{
					((CEdit *)GetDlgItem(IDC_EDIT7))->SetWindowText(L"");
					((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(L"");
				}
			}
		}
	}
	else if (strcmp(socketThread->GetName(), ST_NAME_LOGICAL) == 0)
	{

	}
}

BOOL CPlayerInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString playerIDStr;
	playerIDStr.Format(L"%lld", _showPlayerID);
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(playerIDStr);

	_lobbySocketThread->AddListener(this);
	_logicalSocketThread->AddListener(this);

	Message::Lobby::PlayerInfoReq playerInfoReq;
	playerInfoReq.PlayerID = _showPlayerID;
	Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_REQUEST_PLAYERINFO, Message::Lobby::MSG_ASS_REQUEST_PLAYERINFO_WITH_PLAYERID, &playerInfoReq);
	_lobbySocketThread->SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());

	return TRUE;
}

BOOL CPlayerInfoDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN || pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
		if (pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CPlayerInfoDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialog::OnOK();
}

void CPlayerInfoDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
