
// ServerTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "Resource.h"		// ������


// CServerToolApp: 
// �йش����ʵ�֣������ ServerTool.cpp
//

class CServerToolApp : public CWinApp
{
public:
	CServerToolApp();

// ��д
public:
	virtual BOOL InitInstance();

	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CServerToolApp theApp;