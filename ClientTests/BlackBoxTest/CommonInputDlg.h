#pragma once


// CCommonInputDlg �Ի���

class CCommonInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonInputDlg)

public:
	CCommonInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommonInputDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
