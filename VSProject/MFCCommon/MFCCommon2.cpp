#include "stdafx.h"
#include "MFCCommon2.h"
#include "AsyncTipsDlg.h"

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#pragma comment(lib, "vld.lib")
#endif
#endif

MC_NS_BEGIN


const char * MCVersion()
{
	return "1.0.0";
}

BOOL MCPreTranslateMessage(MSG *pMsg)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	CWinApp * winApp = AfxGetApp();
	if (winApp)
	{
		return winApp->PreTranslateMessage(pMsg);
	}
	return FALSE;
}

bool MCShowTipsOK(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom /*= nullptr*/)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	return CAsyncTipsDlg::ShowOK(lpString, hWndResultNotify, resultMsg, custom);
}

bool MCShowTipsOKAndCancel(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom /*= nullptr*/)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	return CAsyncTipsDlg::ShowOKAndCancel(lpString, hWndResultNotify, resultMsg, custom);
}

static int CALLBACK _BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:
	{
		if (lpData)
		{
			::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
		}
	}
		break;
	default:
		break;
	}
	return 0;
}

bool MCBrowseDirectory(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	bool ret = false;
	result = L"";
	wchar_t buf[1024/*MAX_PATH*/];
	BROWSEINFO bi;
	bi.hwndOwner = pParent->m_hWnd;
	bi.pidlRoot = nullptr;
	bi.pszDisplayName = buf;
	bi.lpszTitle = titleString;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = _BrowseCallbackProc;
	bi.lParam = 0;
	bi.iImage = 0;
	CString defaultDirStr;
	if (defaultDir)
	{
		defaultDirStr = defaultDir;
		defaultDirStr.Replace(L"/", L"\\");
		DWORD r = GetFileAttributes(defaultDirStr.GetString());
		if (r != INVALID_FILE_ATTRIBUTES && (r & FILE_ATTRIBUTE_DIRECTORY))
		{
			bi.lParam = (LONG_PTR)defaultDirStr.GetString();
		}
	}
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);
	if (lp)
	{
		if (SHGetPathFromIDList(lp, buf) == TRUE)
		{
			result = buf;
			ret = true;
		}
		LPMALLOC pMalloc = nullptr;
		if (SUCCEEDED(SHGetMalloc(&pMalloc)))
		{
			pMalloc->Free(lp);
			pMalloc->Release();
		}
	}
	return ret;
}

bool MCBrowseFile(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	result = L"";
	char curBuf[/*MAX_PATH*/1024];
	DWORD cr = GetCurrentDirectoryA(/*MAX_PATH*/1024, curBuf);
	CFileDialog fileDlg(TRUE, nullptr, nullptr, OFN_NOCHANGEDIR, nullptr, pParent);
	if (titleString)
	{
		fileDlg.m_ofn.lpstrTitle = titleString;
	}
	CString defaultDirStr;
	if (defaultDir)
	{
		defaultDirStr = defaultDir;
		defaultDirStr.Replace(L"/", L"\\");
		DWORD r = GetFileAttributes(defaultDirStr.GetString());
		if (r != INVALID_FILE_ATTRIBUTES && (r & FILE_ATTRIBUTE_DIRECTORY))
		{
			fileDlg.m_ofn.lpstrInitialDir = defaultDirStr.GetString();
		}
	}
	INT_PTR r = fileDlg.DoModal();
	if (cr > 0)
	{
		SetCurrentDirectoryA(curBuf);
	}
	if (r == IDOK)
	{
		result = fileDlg.GetPathName();
		return true;
	}
	return false;
}

bool MCBrowseSaveFile(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result)
{
#if defined(_AFXDLL)
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
#endif

	result = L"";
	char curBuf[/*MAX_PATH*/1024];
	DWORD cr = GetCurrentDirectoryA(/*MAX_PATH*/1024, curBuf);
	CFileDialog fileDlg(FALSE, nullptr, nullptr, OFN_NOCHANGEDIR | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, nullptr, pParent);
	if (titleString)
	{
		fileDlg.m_ofn.lpstrTitle = titleString;
	}
	CString defaultDirStr;
	if (defaultDir)
	{
		defaultDirStr = defaultDir;
		defaultDirStr.Replace(L"/", L"\\");
		DWORD r = GetFileAttributes(defaultDirStr.GetString());
		if (r != INVALID_FILE_ATTRIBUTES && (r & FILE_ATTRIBUTE_DIRECTORY))
		{
			fileDlg.m_ofn.lpstrInitialDir = defaultDirStr.GetString();
		}
	}
	INT_PTR r = fileDlg.DoModal();
	if (cr > 0)
	{
		SetCurrentDirectoryA(curBuf);
	}
	if (r == IDOK)
	{
		result = fileDlg.GetPathName();
		return true;
	}
	return false;
}


MC_NS_END