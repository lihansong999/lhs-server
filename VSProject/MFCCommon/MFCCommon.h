// MFCCommon.h : MFCCommon DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "Resource.h"		// ������


// CMFCCommonApp
// �йش���ʵ�ֵ���Ϣ������� MFCCommon.cpp
//

class CMFCCommonApp : public CWinApp
{
public:
	CMFCCommonApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
