
// ServerToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ServerTool.h"
#include "ServerToolDlg.h"
#include "afxdialogex.h"

#include <google/protobuf/message_lite.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define PRINT_DEQUE_MAX_COUNT	120
#define LOG_DEQUE_MAX_COUNT		70

FW_NS_USEING;


static HWND _HWndSelf = NULL;

CServerToolDlg::CServerToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SERVERTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CServerToolDlg::~CServerToolDlg()
{
	FWOutPut::GetInstance()->CustomPrintPrint(nullptr);
	FWOutPut::GetInstance()->CustomLogPrint(nullptr);
	google::protobuf::ShutdownProtobufLibrary();
}

void CServerToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CServerToolDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CServerToolDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CServerToolDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CServerToolDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CServerToolDlg 消息处理程序

BOOL CServerToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	_HWndSelf = this->m_hWnd;

	((CEdit *)GetDlgItem(IDC_EDIT1))->SetWindowText(L"");
	((CEdit *)GetDlgItem(IDC_EDIT1))->SetLimitText(30000);
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetWindowText(L"");
	((CEdit *)GetDlgItem(IDC_EDIT2))->SetLimitText(30000);

	FWOutPut::GetInstance()->CustomPrintPrint([](const char * str)->void {
		if (_HWndSelf)
		{
			size_t len = strlen(str) + 1;
			char * msgBody = new char[strlen(str) + 1];
			strcpy_s(msgBody, len, str);
			::PostMessage(_HWndSelf, WMC_PRINT_PRINT, (WPARAM)msgBody, 0);
		}
	});
	FWOutPut::GetInstance()->CustomLogPrint([](FWOutPut::LOGTYPE t, const char * str)->void {
		if (_HWndSelf)
		{
			size_t len = strlen(str) + 1;
			char * msgBody = new char[strlen(str) + 1];
			strcpy_s(msgBody, len, str);
			::PostMessage(_HWndSelf, WMC_LOG_PRINT, (WPARAM)msgBody, 0);
		}
	});

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CServerToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CServerToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CServerToolDlg::PreTranslateMessage(MSG* pMsg)
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

LRESULT CServerToolDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WMC_PRINT_PRINT:
	{
		CEdit * pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);
		//SCROLLINFO scrollInfo;
		//pEdit->GetScrollInfo(SB_VERT, &scrollInfo);
		//int nStartChar, nEndChar;
		//pEdit->GetSel(nStartChar, nEndChar);
		FWWString str = FW_ANSI_2_UNICODE((char*)wParam);
		delete[] (char*)wParam;
		int removeLength = 0;
		_printDeque.push_back(str.C_Str());
		if (_printDeque.size() > PRINT_DEQUE_MAX_COUNT)
		{
			removeLength = (int)_printDeque.front().length();
			_printDeque.pop_front();
		}
		if (removeLength > 0)
		{
			pEdit->SetSel(0, removeLength);
			pEdit->ReplaceSel(L"");
		}
		pEdit->SetSel(-1);
		pEdit->ReplaceSel(str.C_Str());
		//pEdit->SetScrollPos(SB_VERT, scrollInfo.nPos);
		//pEdit->SetSel(nStartChar, nEndChar);
	}
		return 0;
	case WMC_LOG_PRINT:
	{
		CEdit * pEdit = (CEdit *)GetDlgItem(IDC_EDIT2);
		//SCROLLINFO scrollInfo;
		//pEdit->GetScrollInfo(SB_VERT, &scrollInfo);
		//int nStartChar, nEndChar;
		//pEdit->GetSel(nStartChar, nEndChar);
		FWWString str = FW_ANSI_2_UNICODE((char*)wParam);
		delete[] (char*)wParam;
		int removeLength = 0;
		_logDeque.push_back(str.C_Str());
		if (_logDeque.size() > LOG_DEQUE_MAX_COUNT)
		{
			removeLength = (int)_logDeque.front().length();
			_logDeque.pop_front();
		}
		if (removeLength > 0)
		{
			pEdit->SetSel(0, removeLength);
			pEdit->ReplaceSel(L"");
		}
		pEdit->SetSel(-1);
		pEdit->ReplaceSel(str.C_Str());
		//pEdit->SetScrollPos(SB_VERT, scrollInfo.nPos);
		//pEdit->SetSel(nStartChar, nEndChar);
	}
		return 0;
	case WMC_TIPS_CLOSE_WND:
	{
		if (wParam == IDOK)
		{
			CDialog::OnCancel();
		}
	}
		return 0;
	case WMC_TIPS_FROM_DISK_RELOAD_REDIS_SCRIPT_SHA1_TO_MYSQL:
	{
		if (wParam == IDOK)
		{
			_redisScriptLoadTool.Execute();
		}
	}
		return 0;
	default:
		return CWnd::WindowProc(message, wParam, lParam);
	}
}

void CServerToolDlg::OnBnClickedOk()
{
	//CDialog::OnOK();
}

void CServerToolDlg::OnBnClickedCancel()
{
	MFCCommon::MCShowTipsOKAndCancel(L"是否确定关闭？", _HWndSelf, WMC_TIPS_CLOSE_WND);
}

void CServerToolDlg::OnBnClickedButton1()
{
	MFCCommon::MCShowTipsOKAndCancel(L"是否确定初始化Redis脚本并将sha1写入数据库？", _HWndSelf, WMC_TIPS_FROM_DISK_RELOAD_REDIS_SCRIPT_SHA1_TO_MYSQL);
}
