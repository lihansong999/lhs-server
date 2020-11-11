// AsyncTipsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCCommon.h"
#include "AsyncTipsDlg.h"
#include "afxdialogex.h"


// CAsyncTipsDlg 对话框

IMPLEMENT_DYNAMIC(CAsyncTipsDlg, CDialog)

CAsyncTipsDlg::CAsyncTipsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, _tipsType(0)
	, _hWndResultNotify(NULL)
	, _resultMsg(0)
	, _custom(nullptr)
{

}

CAsyncTipsDlg::~CAsyncTipsDlg()
{
}

void CAsyncTipsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CAsyncTipsDlg::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}

BEGIN_MESSAGE_MAP(CAsyncTipsDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAsyncTipsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAsyncTipsDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CAsyncTipsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


BOOL CAsyncTipsDlg::PreTranslateMessage(MSG* pMsg)
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

void CAsyncTipsDlg::OnOK()
{
	DestroyWindow();
}

void CAsyncTipsDlg::OnCancel()
{
	DestroyWindow();
}

void CAsyncTipsDlg::OnBnClickedOk()
{
	if (_hWndResultNotify)
	{
		::PostMessage(_hWndResultNotify, _resultMsg, IDOK, (LPARAM)_custom);
	}
	OnOK();
}

void CAsyncTipsDlg::OnBnClickedCancel()
{
	if (_tipsType == 1)
	{
		return;
	}
	if (_hWndResultNotify)
	{
		::PostMessage(_hWndResultNotify, _resultMsg, IDCANCEL, (LPARAM)_custom);
	}
	OnCancel();
}

void CAsyncTipsDlg::OnBnClickedButton1()
{
	if (_hWndResultNotify)
	{
		::PostMessage(_hWndResultNotify, _resultMsg, IDOK, (LPARAM)_custom);
	}
	OnOK();
}

bool CAsyncTipsDlg::ShowOK(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom /*= nullptr*/)
{
	CAsyncTipsDlg * asyncTipsDlg = new CAsyncTipsDlg(NULL);
	asyncTipsDlg->_tipsType = 1;
	asyncTipsDlg->_hWndResultNotify = hWndResultNotify;
	asyncTipsDlg->_resultMsg = resultMsg;
	asyncTipsDlg->_custom = custom;
	if (hWndResultNotify)
	{
		ASSERT(resultMsg >= WM_USER);
	}
	if (asyncTipsDlg->Create(IDD_DIALOG1, NULL) != TRUE)
	{
		delete asyncTipsDlg;
		return false;
	}
	((CEdit *)asyncTipsDlg->GetDlgItem(IDC_EDIT1))->SetWindowText(lpString);
	((CButton *)asyncTipsDlg->GetDlgItem(IDOK))->ShowWindow(SW_HIDE);
	((CButton *)asyncTipsDlg->GetDlgItem(IDCANCEL))->ShowWindow(SW_HIDE);
	asyncTipsDlg->CenterWindow(NULL);
	asyncTipsDlg->ShowWindow(SW_SHOW);
	return true;
}

bool CAsyncTipsDlg::ShowOKAndCancel(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom /*= nullptr*/)
{
	CAsyncTipsDlg * asyncTipsDlg = new CAsyncTipsDlg(NULL);
	asyncTipsDlg->_tipsType = 2;
	asyncTipsDlg->_hWndResultNotify = hWndResultNotify;
	asyncTipsDlg->_resultMsg = resultMsg;
	asyncTipsDlg->_custom = custom;
	if (hWndResultNotify)
	{
		ASSERT(resultMsg >= WM_USER);
	}
	if (asyncTipsDlg->Create(IDD_DIALOG1, NULL) != TRUE)
	{
		delete asyncTipsDlg;
		return false;
	}
	((CEdit *)asyncTipsDlg->GetDlgItem(IDC_EDIT1))->SetWindowText(lpString);
	((CButton *)asyncTipsDlg->GetDlgItem(IDC_BUTTON1))->ShowWindow(SW_HIDE);
	asyncTipsDlg->CenterWindow(NULL);
	asyncTipsDlg->ShowWindow(SW_SHOW);
	return true;
}