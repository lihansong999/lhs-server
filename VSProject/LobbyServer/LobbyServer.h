
// LobbyServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "Resource.h"		// ������


// CLobbyServerApp: 
// �йش����ʵ�֣������ LobbyServer.cpp
//

class CLobbyServerApp : public CWinApp
{
public:
	CLobbyServerApp();

// ��д
public:
	virtual BOOL InitInstance();

	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLobbyServerApp theApp;