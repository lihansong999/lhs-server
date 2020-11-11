#pragma once


// CCommonInputDlg 对话框

class CCommonInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonInputDlg)

public:
	CCommonInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommonInputDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	CString _defaultText;
	CString _inputContent;
};
