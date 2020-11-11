
// ServerToolDlg.h : ͷ�ļ�
//

#pragma once
#include "Classes/RedisScriptLoadTool.h"
#include "Classes/WndMessageCustom.h"

// CServerToolDlg �Ի���
class CServerToolDlg : public CDialog
{
// ����
public:
	CServerToolDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CServerToolDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVERTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();

private:
	std::deque<std::wstring>	_printDeque;
	std::deque<std::wstring>	_logDeque;
	RedisScriptLoadTool			_redisScriptLoadTool;
};
