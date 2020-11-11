#pragma once


// CAsyncTipsDlg �Ի���

class CAsyncTipsDlg : public CDialog
{
	DECLARE_DYNAMIC(CAsyncTipsDlg)

public:
	CAsyncTipsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAsyncTipsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	���֪ͨ��ʽ��
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
