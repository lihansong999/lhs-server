#include "stdafx.h"
#include "NetworkTools.h"
#include "TcpSvcManage.h"
#include "WsSvcManage.h"
#include "TcpOutManage.h"

FW_NS_USEING;


bool SendDataSvcSocket(const SvcNetMatch & svcNetMatch, const char * pData, int size)
{
	if (svcNetMatch.Type == SCSNMT_TCP)
	{
		return TcpSvcManage::GetInstance()->SendDataTcpSvcSocket(svcNetMatch.NetMatch, pData, size);
	}
	else if (svcNetMatch.Type == SCSNMT_WS)
	{
		return WsSvcManage::GetInstance()->SendDataWsSvcSocket(svcNetMatch.NetMatch, pData + sizeof(int), size - sizeof(int));
	}
	return false;
}

void SendDataSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count, const char * pData, int size)
{
	if (!pData || size <= 0)
	{
		return;
	}
	if (!svcNetMatches || count == 0)
	{
		return;
	}
	for (unsigned int i = 0; i < count; i++)
	{
		SendDataSvcSocket(svcNetMatches[i], pData, size);
	}
}

void CloseSvcSocket(const SvcNetMatch & svcNetMatch)
{
	if (svcNetMatch.Type == SCSNMT_TCP)
	{
		TcpSvcManage::GetInstance()->CloseTcpSvcSocket(svcNetMatch.NetMatch);
	}
	else if (svcNetMatch.Type == SCSNMT_WS)
	{
		WsSvcManage::GetInstance()->CloseWsSvcSocket(svcNetMatch.NetMatch);
	}
}

void CloseSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count)
{
	if (!svcNetMatches || count == 0)
	{
		return;
	}
	for (unsigned int i = 0; i < count; i++)
	{
		CloseSvcSocket(svcNetMatches[i]);
	}
}

bool GetSvcSocketInfo(const SvcNetMatch & svcNetMatch, FWSvcSocketInfo * out_svcSocketInfo)
{
	if (svcNetMatch.Type == SCSNMT_TCP)
	{
		return TcpSvcManage::GetInstance()->GetTcpSvcSocketInfo(svcNetMatch.NetMatch, out_svcSocketInfo);
	}
	else if (svcNetMatch.Type == SCSNMT_WS)
	{
		return WsSvcManage::GetInstance()->GetWsSvcSocketInfo(svcNetMatch.NetMatch, out_svcSocketInfo);
	}
	return false;
}

int GetSvcConnectedCount()
{
	return TcpSvcManage::GetInstance()->GetConnectedCount() + WsSvcManage::GetInstance()->GetConnectedCount();
}