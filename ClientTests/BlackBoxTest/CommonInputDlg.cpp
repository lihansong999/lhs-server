// CommonInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BlackBoxTest.h"
#include "CommonInputDlg.h"
#include "afxdialogex.h"
#include "Classes/Charset.h"


// CCommonInputDlg 对话框

IMPLEMENT_DYNAMIC(CCommonInputDlg, CDialog)

CCommonInputDlg::CCommonInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG3, pParent)
{

}

CCommonInputDlg::~CCommonInputDlg()
{
}

void CCommonInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCommonInputDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CCommonInputDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCommonInputDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


BOOL CCommonInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(_defaultText);
	_inputContent = L"";

	return TRUE;
}

BOOL CCommonInputDlg::PreTranslateMessage(MSG* pMsg)
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

void CCommonInputDlg::OnBnClickedOk()
{
	((CEdit *)GetDlgItem(IDC_EDIT1))->GetWindowText(_inputContent);
	CDialog::OnOK();
}

void CCommonInputDlg::OnBnClickedCancel()
{
	CDialog::OnCancel();
}
