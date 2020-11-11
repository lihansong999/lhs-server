#pragma once
#include <string>
#include <regex>

// CAccountInputDlg 对话框

class CAccountInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CAccountInputDlg)
public:
	enum CREATE_TYPE {
		CT_REGISTER = 0,
		CT_LOGIN,
	};

	enum INPUT_TYPE {
		IT_UID = 2980,
		IT_ACT,
	};

public:
	CAccountInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAccountInputDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

public:
	CREATE_TYPE _createType;
	std::string _unionid;
	std::string _account;
	std::string _password;
	std::string _nickname;
	int			_sex;
};
