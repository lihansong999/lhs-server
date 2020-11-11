#pragma once
#include "Classes/SocketThread.h"

// CPlayerInfoDlg �Ի���

class CPlayerInfoDlg : public CDialog, public SocketThreadDelegate
{
	DECLARE_DYNAMIC(CPlayerInfoDlg)

public:
	CPlayerInfoDlg(SocketThread * lobbySocketThread, SocketThread * logicalSocketThread, PLAYERID_T selfPlayerID, PLAYERID_T showPlayerID, CWnd* pParent = NULL);
	virtual ~CPlayerInfoDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void onMessage(SocketThread * socketThread, Message::MsgPackageRecv * pack);

public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	SocketThread *	_lobbySocketThread;
	SocketThread *	_logicalSocketThread;
	PLAYERID_T		_selfPlayerID;
	PLAYERID_T		_showPlayerID;
};
