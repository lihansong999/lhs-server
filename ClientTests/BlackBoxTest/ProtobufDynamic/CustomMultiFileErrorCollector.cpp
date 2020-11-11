#include "stdafx.h"
#include "CustomMultiFileErrorCollector.h"
#include "../BlackBoxTestDlg.h"


CustomMultiFileErrorCollector::CustomMultiFileErrorCollector()
{

}

CustomMultiFileErrorCollector::~CustomMultiFileErrorCollector()
{

}

void CustomMultiFileErrorCollector::AddError(const std::string& filename, int line, int column, const std::string& message)
{
	CBlackBoxTestDlg * clackBoxTestDlg = dynamic_cast<CBlackBoxTestDlg*>(AfxGetApp()->m_pMainWnd);
	if (clackBoxTestDlg)
	{
		char buff[1024] = { 0 };
		sprintf_s(buff, sizeof(buff), "error:%s:%d:%d:%s", filename.c_str(), line, column, message.c_str());
		clackBoxTestDlg->LobbyPrintA(buff);
	}
}

void CustomMultiFileErrorCollector::AddWarning(const std::string& filename, int line, int column, const std::string& message)
{
	CBlackBoxTestDlg * clackBoxTestDlg = dynamic_cast<CBlackBoxTestDlg*>(AfxGetApp()->m_pMainWnd);
	if (clackBoxTestDlg)
	{
		char buff[1024] = { 0 };
		sprintf_s(buff, sizeof(buff), "warning:%s:%d:%d:%s", filename.c_str(), line, column, message.c_str());
		clackBoxTestDlg->LobbyPrintA(buff);
	}
}