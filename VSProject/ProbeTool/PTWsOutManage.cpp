#include "PTWsOutManage.h"

FW_NS_USEING;


static PTWsOutManage * _PTWsOutManage = nullptr;

PTWsOutManage::PTWsOutManage()
{
	_PTWsOutManage = this;
}

PTWsOutManage::~PTWsOutManage()
{
	this->Stop();
	_PTWsOutManage = nullptr;
}

PTWsOutManage * PTWsOutManage::GetInstance()
{
	return _PTWsOutManage;
}

bool PTWsOutManage::Start()
{
	return FWWsOutManageBase::Start(4, MSG_PACKAGE_MAX, WSDP_TEXT, true);
}

void PTWsOutManage::Stop()
{
	FWWsOutManageBase::Stop();
}

void PTWsOutManage::_onWsOutOverloaded(Framework::FW_ID custom)
{

}

void PTWsOutManage::_onWsOutConnectResult(bool succeed, const Framework::FWNetMatch & netMatch, Framework::FW_ID custom)
{

}

void PTWsOutManage::_onWsOutMessage(const Framework::FWNetMatch & netMatch, char * newBuf, unsigned int size, Framework::FW_ID custom)
{
	if (size == 0)
	{
		if (newBuf)
			FW_FREE(newBuf);
		this->CloseWsOutSocket(netMatch);
		return;
	}
}

void PTWsOutManage::_onWsOutClose(const Framework::FWNetMatch & netMatch, Framework::FW_ID custom)
{

}