
// CenterServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "Resource.h"		// ������


// CCenterServerApp: 
// �йش����ʵ�֣������ CenterServer.cpp
//

class CCenterServerApp : public CWinApp
{
public:
	CCenterServerApp();

// ��д
public:
	virtual BOOL InitInstance();

	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCenterServerApp theApp;