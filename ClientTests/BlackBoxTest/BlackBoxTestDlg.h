
// BlackBoxTestDlg.h : 头文件
//

#pragma once
#include "Classes/SocketThread.h"
#include "Classes/HttpRequest.h"


// CBlackBoxTestDlg 对话框
class CBlackBoxTestDlg : public CDialog, public SocketThreadDelegate
{
// 构造
public:
	CBlackBoxTestDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CBlackBoxTestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLACKBOXTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	virtual void onConnectResult(SocketThread * socketThread, bool s);
	virtual void onDisconnected(SocketThread * socketThread);
	virtual void onMessage(SocketThread * socketThread, Message::MsgPackageRecv * pack);

	void LobbyPrintA(const char * str);
	void LobbyPrintW(const wchar_t * str);
	void LogicalPrintA(const char * str);
	void LogicalPrintW(const wchar_t * str);
	std::string GetShowedWebHostA();
	std::wstring GetShowedWebHostW();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();

private:
	SocketThread				_lobbySocketThread;
	std::deque<std::wstring>	_lobbyPrintDeque;
	bool						_lobbyConnected;
	SocketThread				_logicalSocketThread;
	std::deque<std::wstring>	_logicalPrintDeque;
	bool						_logicalConnected;

private:
	Message::Lobby::LoginRes	_lobbyLoginRes;
	Message::Logical::LoginRes	_logicalLoginRes;
};
