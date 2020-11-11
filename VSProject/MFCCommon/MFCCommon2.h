#pragma once

#if defined(_DEBUG)
#if defined(USE_MEMORY_LEAK_DETECTOR)
#include "../Framework/ThirdParty/MemoryLeakDetector/include/vld.h"
#endif
#endif

#if defined(MFCCOMMON_EXPORTS)
#define MC_DLL     __declspec(dllexport)
#else
#define MC_DLL     __declspec(dllimport)
#endif

#define MC_NS_BEGIN		namespace MFCCommon {
#define MC_NS_END		}
#define MC_NS_USEING	using namespace MFCCommon


MC_NS_BEGIN


extern MC_DLL const char * MCVersion();

extern BOOL MC_DLL MCPreTranslateMessage(MSG *pMsg);

extern bool MC_DLL MCShowTipsOK(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom = nullptr);

extern bool MC_DLL MCShowTipsOKAndCancel(LPCWSTR lpString, HWND hWndResultNotify, UINT resultMsg, void * custom = nullptr);

extern bool MC_DLL MCBrowseDirectory(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result);

extern bool MC_DLL MCBrowseFile(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result);

extern bool MC_DLL MCBrowseSaveFile(CWnd * pParent, LPCWSTR titleString, LPCWSTR defaultDir, CString & result);


MC_NS_END