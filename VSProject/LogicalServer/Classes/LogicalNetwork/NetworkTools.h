#pragma once
#include "../LogicalBase/Local.h"
#include "../LogicalBase/TypeDefine.h"


bool SendDataSvcSocket(const SvcNetMatch & svcNetMatch, const char * pData, int size);

void SendDataSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count, const char * pData, int size);

void CloseSvcSocket(const SvcNetMatch & svcNetMatch);

void CloseSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count);

bool GetSvcSocketInfo(const SvcNetMatch & svcNetMatch, Framework::FWSvcSocketInfo * out_svcSocketInfo);

int GetSvcConnectedCount();