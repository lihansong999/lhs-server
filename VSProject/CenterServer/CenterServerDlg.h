
// CenterServerDlg.h : ͷ�ļ�
//

#pragma once
#include "Classes/CenterMain.h"
#include "CenterWndMessageCustom.h"


// CCenterServerDlg �Ի���
class CCenterServerDlg : public CDialog
{
// ����
public:
	CCenterServerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CCenterServerDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CENTERSERVER_DIALOG };
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

	static void AddLobbyServerToList(int id);
	static void RemoveLobbyServerToList(int id);
	static void ClearLobbyServerToList();

	static void AddLogicalServerToList(int id);
	static void RemoveLogicalServerToList(int id);
	static void ClearLogicalServerToList();

private:
	ServiceState				_serviceState;
	CenterMain					_centerMain;
	std::deque<std::wstring>	_printDeque;
	std::deque<std::wstring>	_logDeque;
	std::set<int>				_lobbyServerSet;
	std::set<int>				_logicalServerSet;
};
