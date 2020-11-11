// AccountInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BlackBoxTest.h"
#include "AccountInputDlg.h"
#include "afxdialogex.h"
#include "Classes/RecordInfo.h"
#include "Classes/Charset.h"

// CAccountInputDlg 对话框

IMPLEMENT_DYNAMIC(CAccountInputDlg, CDialog)

CAccountInputDlg::CAccountInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	_createType = CAccountInputDlg::CT_REGISTER;
	_sex = SEX_UNKNOWN;
}

CAccountInputDlg::~CAccountInputDlg()
{
}

void CAccountInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAccountInputDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAccountInputDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAccountInputDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CAccountInputDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAccountInputDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


BOOL CAccountInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	std::string account = RecordInfo::GetInstance()->Read_Account();
	std::string password = RecordInfo::GetInstance()->Read_Password();
	std::string unionid = RecordInfo::GetInstance()->Read_Unionid();
	if (unionid.size() > 0)
	{
		((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(ANSI_2_UNICODE(unionid.c_str()).c_str());
	}
	if (account.size() > 0)
	{
		((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(ANSI_2_UNICODE(account.c_str()).c_str());
	}
	if (password.size() > 0)
	{
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(ANSI_2_UNICODE(password.c_str()).c_str());
	}

	if (_createType == CAccountInputDlg::CT_REGISTER)
	{
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(L"默认昵称");
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(BST_UNCHECKED);
	}
	else if (_createType == CAccountInputDlg::CT_LOGIN)
	{
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(L"");
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetReadOnly(TRUE);
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(BST_UNCHECKED);
		((CButton *)GetDlgItem(IDC_RADIO1))->EnableWindow(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(BST_UNCHECKED);
		((CButton *)GetDlgItem(IDC_RADIO2))->EnableWindow(FALSE);
	}

	return TRUE;
}

BOOL CAccountInputDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN || pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
		if (pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CAccountInputDlg::OnBnClickedOk()
{
	//CDialog::OnOK();
}

void CAccountInputDlg::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

void CAccountInputDlg::OnBnClickedButton1()
{
	CString uidText;
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowTextW(uidText);
	_unionid = UNICODE_2_ANSI(uidText.GetBuffer());
	std::regex pattern("^[\x01-\x7F]+$");
	if (_unionid.size() < 6 || _unionid.size() > 64 || !std::regex_match(_unionid, pattern))
	{
		AfxMessageBox(L"唯一码只能是0x01-0x7f组合的6-64个字符。");
		return;
	}

	if (_createType == CAccountInputDlg::CT_REGISTER)
	{
		CString nicknameText;
		((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowTextW(nicknameText);
		_nickname = UNICODE_2_ANSI(nicknameText.GetBuffer());
		if (_nickname.size() == 0)
		{
			AfxMessageBox(L"昵称不能为空");
			return;
		}
		else if (_nickname.size() > 120)
		{
			AfxMessageBox(L"昵称太长");
			return;
		}
		if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck() == BST_CHECKED && ((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_UNCHECKED)
		{
			_sex = SEX_MEN;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_CHECKED && ((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck() == BST_UNCHECKED)
		{
			_sex = SEX_WOMEN;
		}
		else
		{
			AfxMessageBox(L"请正确选择性别");
			return;
		}
	}

	EndDialog(CAccountInputDlg::IT_UID);
}

void CAccountInputDlg::OnBnClickedButton2()
{
	CString actText;
	((CEdit *)GetDlgItem(IDC_EDIT2))->GetWindowTextW(actText);
	CString pwdText;
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowTextW(pwdText);
	_account = UNICODE_2_ANSI(actText.GetBuffer());
	_password = UNICODE_2_ANSI(pwdText.GetBuffer());
	std::regex pattern("^[A-Za-z0-9]+$");
	if (_account.size() < 6 || _account.size() > 12 || !std::regex_match(_account, pattern))
	{
		AfxMessageBox(L"账号只能是6-12个字符的字母或数字。");
		return;
	}
	if (_password.size() < 6 || _password.size() > 12 || !std::regex_match(_password, pattern))
	{
		AfxMessageBox(L"密码只能是6-12个字符的字母或数字。");
		return;
	}

	if (_createType == CAccountInputDlg::CT_REGISTER)
	{
		CString nicknameText;
		((CEdit *)GetDlgItem(IDC_EDIT4))->GetWindowTextW(nicknameText);
		_nickname = UNICODE_2_ANSI(nicknameText.GetBuffer());
		if (_nickname.size() == 0)
		{
			AfxMessageBox(L"昵称不能为空");
			return;
		}
		else if (_nickname.size() > 120)
		{
			AfxMessageBox(L"昵称太长");
			return;
		}
		if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck() == BST_CHECKED && ((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_UNCHECKED)
		{
			_sex = SEX_MEN;
		}
		else if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() == BST_CHECKED && ((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck() == BST_UNCHECKED)
		{
			_sex = SEX_WOMEN;
		}
		else
		{
			AfxMessageBox(L"请正确选择性别");
			return;
		}
	}

	EndDialog(CAccountInputDlg::IT_ACT);
}
