
// CenterServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CenterServer.h"
#include "CenterServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define PRINT_DEQUE_MAX_COUNT	120
#define LOG_DEQUE_MAX_COUNT		70

FW_NS_USEING;


static HWND _HWndSelf = NULL;

CCenterServerDlg::CCenterServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CENTERSERVER_DIALOG, pParent)
	, _serviceState(CCenterServerDlg::INITIALIZED)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CCenterServerDlg::~CCenterServerDlg()
{
	FWOutPut::GetInstance()->CustomPrintPrint(nullptr);
	FWOutPut::GetInstance()->CustomLogPrint(nullptr);
}

void CCenterServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCenterServerDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCenterServerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCenterServerDlg::OnBnClickedCancel)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CCenterServerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCenterServerDlg ��Ϣ�������

BOOL CCenterServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

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

	SetTimer(CCenterServerDlg::OnTimer_T_1000, 1000, NULL);

	_serviceState = CCenterServerDlg::STARTING;
	std::thread t = std::thread([this]() {
		_centerMain.Start();
		_serviceState = CCenterServerDlg::STARTED;
		::PostMessage(_HWndSelf, WMC_SSTATE_CHANGE_TO_STARTED, 0, 0);
	});
	t.detach();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCenterServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCenterServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CCenterServerDlg::PreTranslateMessage(MSG* pMsg)
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

LRESULT CCenterServerDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
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
			_serviceState = CCenterServerDlg::ENDING;
			std::thread t = std::thread([this]() {
				_centerMain.Stop();
				_serviceState = CCenterServerDlg::ENDED;
				::PostMessage(_HWndSelf, WMC_SSTATE_CHANGE_TO_STOPPED, 0, 0);
			});
			t.detach();
		}
		else if(wParam == IDCANCEL)
		{
			_serviceState = CCenterServerDlg::STARTED;
		}
	}
		return 0;
	case WMC_TIPS_FROM_MYSQL_RELOAD_REDIS_SCRIPT_SHA1_TO_MEMORY:
	{
		if (wParam == IDOK)
		{
			if (_serviceState == CCenterServerDlg::STARTED)
			{
				FWLogicDataGeneral * logicDataGeneral = new FWLogicDataGeneral();
				logicDataGeneral->PushBackValue<int>(DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1);
				DataHandle::GetInstance()->PushLogicData(logicDataGeneral);
			}
			else
			{
				MFCCommon::MCShowTipsOK(L"��ǰ�޷�ִ�д˲�����", NULL, 0);
			}
		}
	}
		return 0;
	case WMC_SSTATE_CHANGE_TO_STARTED:
	{
		CString portStr;
		portStr.Format(L"%d", _centerMain.GetPort());
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(portStr);
		CString maxclientsStr;
		maxclientsStr.Format(L"%d", _centerMain.GetMaxclients());
		((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(maxclientsStr);
	}
		return 0;
	case WMC_SSTATE_CHANGE_TO_STOPPED:
	{

	}
		return 0;
	case WMC_NOTE_ONLINE_SERVER_LIST_UPDATE:
	{
		int t = (int)wParam;
		int id = (int)lParam;
		std::set<int> * serverSet = nullptr;
		CListBox * listBox = nullptr;
		if (t == 1 || t == 2 || t == 3)
		{
			serverSet = &_lobbyServerSet;
			listBox = (CListBox *)GetDlgItem(IDC_LIST1);
		}
		else if (t == 4 || t == 5 || t == 6)
		{
			serverSet = &_logicalServerSet;
			listBox = (CListBox *)GetDlgItem(IDC_LIST2);
		}
		else
		{
			return 0;
		}
		if (t == 1 || t == 4)
		{
			(*serverSet).insert(id);
			listBox->ResetContent();
			for (std::set<int>::iterator it = (*serverSet).begin(); it != (*serverSet).end(); it++)
			{
				CString str;
				str.Format(L"%s%d", L"ID: ", *it);
				listBox->AddString(str);
			}
		}
		else if (t == 2 || t == 5)
		{
			(*serverSet).erase(id);
			listBox->ResetContent();
			for (std::set<int>::iterator it = (*serverSet).begin(); it != (*serverSet).end(); it++)
			{
				CString str;
				str.Format(L"%s%d", L"ID: ", *it);
				listBox->AddString(str);
			}
		}
		else if (t == 3 || t == 6)
		{
			(*serverSet).clear();
			listBox->ResetContent();
		}
	}
		return 0;
	default:
		return CWnd::WindowProc(message, wParam, lParam);
	}
}

void CCenterServerDlg::OnBnClickedOk()
{
	//CDialog::OnOK();
}

void CCenterServerDlg::OnBnClickedCancel()
{
	switch (_serviceState)
	{
	case CCenterServerDlg::STARTING:
	{
		MFCCommon::MCShowTipsOK(L"����������������ȴ���", NULL, 0);
		return;
	}
		break;
	case CCenterServerDlg::STARTED:
	{
		_serviceState = CCenterServerDlg::TEMP;
		MFCCommon::MCShowTipsOKAndCancel(L"�Ƿ�ȷ���رշ���", _HWndSelf, WMC_TIPS_CLOSE_SERVICE);
		return;
	}
		break;
	case CCenterServerDlg::ENDING:
	{
		MFCCommon::MCShowTipsOK(L"���ڹرշ�����ȴ���", NULL, 0);
		return;
	}
		break;
	case CCenterServerDlg::ENDED:
	{
		CDialog::OnCancel();
		return;
	}
		break;
	case CCenterServerDlg::INITIALIZED:
	case CCenterServerDlg::TEMP:
	default:
		return;
		break;
	}
}

void CCenterServerDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialog::OnTimer(nIDEvent);
}

void CCenterServerDlg::OnBnClickedButton1()
{
	MFCCommon::MCShowTipsOKAndCancel(L"�Ƿ�ȷ�������ݿ�����������Redis�ű�Sha1���ڴ��У�", _HWndSelf, WMC_TIPS_FROM_MYSQL_RELOAD_REDIS_SCRIPT_SHA1_TO_MEMORY);
}

void CCenterServerDlg::AddLobbyServerToList(int id)
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 1, (LPARAM)id);
}

void CCenterServerDlg::RemoveLobbyServerToList(int id)
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 2, (LPARAM)id);
}

void CCenterServerDlg::ClearLobbyServerToList()
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 3, 0);
}

void CCenterServerDlg::AddLogicalServerToList(int id)
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 4, (LPARAM)id);
}

void CCenterServerDlg::RemoveLogicalServerToList(int id)
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 5, (LPARAM)id);
}

void CCenterServerDlg::ClearLogicalServerToList()
{
	if (_HWndSelf)
		::PostMessage(_HWndSelf, WMC_NOTE_ONLINE_SERVER_LIST_UPDATE, 6, 0);
}