
// LobbyServerDlg.h : ͷ�ļ�
//

#pragma once
#include "Classes/LobbyMain.h"
#include "LobbyWndMessageCustom.h"


// CLobbyServerDlg �Ի���
class CLobbyServerDlg : public CDialog
{
// ����
public:
	CLobbyServerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CLobbyServerDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOBBYSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();

public:
	enum ServiceState {
		INITIALIZED = 0,
		TEMP,
		STARTING,
		STARTED,
		ENDING,
		ENDED,
	};

	enum OnTimerTag {
		OnTimer_T_1000 = 0,
	};

private:
	ServiceState				_serviceState;
	LobbyMain					_lobbyMain;
	std::deque<std::wstring>	_printDeque;
	std::deque<std::wstring>	_logDeque;
};
