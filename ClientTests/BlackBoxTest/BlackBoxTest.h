
// BlackBoxTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "Resource.h"		// ������


// CBlackBoxTestApp: 
// �йش����ʵ�֣������ BlackBoxTest.cpp
//

class CBlackBoxTestApp : public CWinApp
{
public:
	CBlackBoxTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBlackBoxTestApp theApp;