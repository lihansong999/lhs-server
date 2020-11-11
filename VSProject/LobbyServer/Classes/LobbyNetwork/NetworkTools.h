#pragma once
#include "../LobbyBase/Local.h"
#include "../LobbyBase/TypeDefine.h"


bool SendDataSvcSocket(const SvcNetMatch & svcNetMatch, const char * pData, int size);

void SendDataSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count, const char * pData, int size);

void CloseSvcSocket(const SvcNetMatch & svcNetMatch);

void CloseSvcSocketBatch(const SvcNetMatch * svcNetMatches, unsigned int count);

bool GetSvcSocketInfo(const SvcNetMatch & svcNetMatch, Framework::FWSvcSocketInfo * out_svcSocketInfo);

int GetSvcConnectedCount();