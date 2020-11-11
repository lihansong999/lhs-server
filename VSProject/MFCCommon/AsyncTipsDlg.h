#pragma once


// CAsyncTipsDlg 对话框

class CAsyncTipsDlg : public CDialog
{
	DECLARE_DYNAMIC(CAsyncTipsDlg)

public:
	CAsyncTipsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAsyncTipsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void PostNcDestroy();

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();

public:
	/* 
	结果通知方式：
		if(_hWndResultNotify)
		{
			::PostMessage(_hWndResultNotify, _resultMsg, IDOK/IDCANCEL, (LPARAM)_custom);
		}
	*/
	static bool ShowOK(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom = nullptr);
	static bool ShowOKAndCancel(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom = nullptr);

private:
	int		_tipsType;
	HWND	_hWndResultNotify;
	UINT	_resultMsg;
	void  * _custom;
};
