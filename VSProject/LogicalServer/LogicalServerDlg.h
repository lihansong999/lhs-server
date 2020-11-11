
// LogicalServerDlg.h : 头文件
//

#pragma once
#include "Classes/LogicalMain.h"
#include "LogicalWndMessageCustom.h"


// CLogicalServerDlg 对话框
class CLogicalServerDlg : public CDialog
{
// 构造
public:
	CLogicalServerDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CLogicalServerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGICALSERVER_DIALOG };
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
	LogicalMain					_logicalMain;
	std::deque<std::wstring>	_printDeque;
	std::deque<std::wstring>	_logDeque;
};
