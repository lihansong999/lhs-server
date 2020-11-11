
// LogicalServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LogicalServer.h"
#include "LogicalServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define PRINT_DEQUE_MAX_COUNT	120
#define LOG_DEQUE_MAX_COUNT		70

FW_NS_USEING;


static HWND _HWndSelf = NULL;

CLogicalServerDlg::CLogicalServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LOGICALSERVER_DIALOG, pParent)
	, _serviceState(CLogicalServerDlg::INITIALIZED)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CLogicalServerDlg::~CLogicalServerDlg()
{
	FWOutPut::GetInstance()->CustomPrintPrint(nullptr);
	FWOutPut::GetInstance()->CustomLogPrint(nullptr);
}

void CLogicalServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLogicalServerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLogicalServerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLogicalServerDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogicalServerDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLogicalServerDlg 消息处理程序

BOOL CLogicalServerDlg::OnInitDialog()
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

	FWUseDump();

	SetTimer(CLogicalServerDlg::OnTimer_T_1000, 1000, NULL);

	_serviceState = CLogicalServerDlg::STARTING;
	std::thread t = std::thread([this]() {
		_logicalMain.Start();
		_serviceState = CLogicalServerDlg::STARTED;
		::PostMessage(_HWndSelf, WMC_SSTATE_CHANGE_TO_STARTED, 0, 0);
	});
	t.detach();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLogicalServerDlg::OnPaint()
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
HCURSOR CLogicalServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CLogicalServerDlg::PreTranslateMessage(MSG* pMsg)
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

LRESULT CLogicalServerDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
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
	case WMC_TIPS_CLOSE_SERVICE:
	{
		if (wParam == IDOK)
		{
			_serviceState = CLogicalServerDlg::ENDING;
			std::thread t = std::thread([this]() {
				_logicalMain.Stop();
				_serviceState = CLogicalServerDlg::ENDED;
				::PostMessage(_HWndSelf, WMC_SSTATE_CHANGE_TO_STOPPED, 0, 0);
			});
			t.detach();
		}
		else if(wParam == IDCANCEL)
		{
			_serviceState = CLogicalServerDlg::STARTED;
		}
	}
		return 0;
	case WMC_TIPS_FROM_MYSQL_RELOAD_REDIS_SCRIPT_SHA1_TO_MEMORY:
	{
		if (wParam == IDOK)
		{
			if (_serviceState == CLogicalServerDlg::STARTED)
			{
				FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
				logicDataGeneral->PushBackValue<int>(DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1);
				DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
			}
			else
			{
				MFCCommon::MCShowTipsOK(L"当前无法执行此操作。", NULL, 0);
			}
		}
	}
		return 0;
	case WMC_SSTATE_CHANGE_TO_STARTED:
	{
		CString idStr;
		idStr.Format(L"%d", _logicalMain.GetLogicalID());
		((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(idStr);
		CString tcpPortStr;
		tcpPortStr.Format(L"%d", _logicalMain.GetTcpPort());
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(tcpPortStr);
		CString wsPortStr;
		wsPortStr.Format(L"%d", _logicalMain.GetWsPort());
		((CEdit *)GetDlgItem(IDC_EDIT9))->SetWindowText(wsPortStr);
		CString maxClientsStr;
		maxClientsStr.Format(L"%d", _logicalMain.GetMaxClients());
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(maxClientsStr);
	}
		return 0;
	case WMC_SSTATE_CHANGE_TO_STOPPED:
	{

	}
		return 0;
	default:
		return CWnd::WindowProc(message, wParam, lParam);
	}
}

void CLogicalServerDlg::OnBnClickedOk()
{
	//CDialog::OnOK();
}

void CLogicalServerDlg::OnBnClickedCancel()
{
	switch (_serviceState)
	{
	case CLogicalServerDlg::STARTING:
	{
		MFCCommon::MCShowTipsOK(L"服务正在启动，请等待。", NULL, 0);
		return;
	}
		break;
	case CLogicalServerDlg::STARTED:
	{
		_serviceState = CLogicalServerDlg::TEMP;
		MFCCommon::MCShowTipsOKAndCancel(L"是否确定关闭服务？", _HWndSelf, WMC_TIPS_CLOSE_SERVICE);
		return;
	}
		break;
	case CLogicalServerDlg::ENDING:
	{
		MFCCommon::MCShowTipsOK(L"正在关闭服务，请等待。", NULL, 0);
		return;
	}
		break;
	case CLogicalServerDlg::ENDED:
	{
		CDialog::OnCancel();
		return;
	}
		break;
	case CLogicalServerDlg::INITIALIZED:
	case CLogicalServerDlg::TEMP:
	default:
		return;
		break;
	}
}

void CLogicalServerDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch ((CLogicalServerDlg::OnTimerTag)nIDEvent)
	{
	case CLogicalServerDlg::OnTimer_T_1000:
	{
		int tcpcc = TcpSvcManage::GetInstance()->GetConnectedCount();
		int wscc = WsSvcManage::GetInstance()->GetConnectedCount();
		CString connectedStr;
		connectedStr.Format(L"%d", tcpcc + wscc);
		((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(connectedStr);
		connectedStr.Format(L"%d", tcpcc);
		((CEdit *)GetDlgItem(IDC_EDIT8))->SetWindowText(connectedStr);
		connectedStr.Format(L"%d", wscc);
		((CEdit *)GetDlgItem(IDC_EDIT11))->SetWindowText(connectedStr);
	}
		break;
	default:
		break;
	}

	CDialog::OnTimer(nIDEvent);
}

void CLogicalServerDlg::OnBnClickedButton1()
{
	MFCCommon::MCShowTipsOKAndCancel(L"是否确定从数据库中重新载入Redis脚本Sha1到内存中？", _HWndSelf, WMC_TIPS_FROM_MYSQL_RELOAD_REDIS_SCRIPT_SHA1_TO_MEMORY);
}
