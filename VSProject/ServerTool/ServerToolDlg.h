
// ServerToolDlg.h : 头文件
//

#pragma once
#include "Classes/RedisScriptLoadTool.h"
#include "Classes/WndMessageCustom.h"

// CServerToolDlg 对话框
class CServerToolDlg : public CDialog
{
// 构造
public:
	CServerToolDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CServerToolDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVERTOOL_DIALOG };
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
	afx_msg void OnBnClickedButton1();

private:
	std::deque<std::wstring>	_printDeque;
	std::deque<std::wstring>	_logDeque;
	RedisScriptLoadTool			_redisScriptLoadTool;
};
