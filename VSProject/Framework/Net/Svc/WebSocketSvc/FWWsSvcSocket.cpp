#include "FWWsSvcSocket.h"
#include "FWWsSvcManageBase.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#endif // !HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <libwebsockets.h>

FW_NS_BEGIN


static lws_write_protocol _MappedDataProtocol(FWWsSvcManageBase::WSDataProtocol dataProtocol)
{
	switch (dataProtocol)
	{
	case FWWsSvcManageBase::WSDP_TEXT:
		return LWS_WRITE_TEXT;
		break;
	case FWWsSvcManageBase::WSDP_BINARY:
		return LWS_WRITE_BINARY;
		break;
	default:
		return LWS_WRITE_TEXT;
		break;
	}
}

FWWsSvcSocket::FWWsSvcSocket(unsigned int index, FWWsSvcManageBase * wsSvcManage)
	:_index(index)
	, _wsSvcManage(wsSvcManage)
	, _wsi(NULL)
	, _activityID(0)
{
	_sendBuffer = new std::vector<char>();
	((std::vector<char>*)_sendBuffer)->reserve(FW_WSSVC_SEND_BUF_SIZE);
	_sendDataSize = new std::list<size_t>();
	_recvBuffer = new std::vector<char>();
	((std::vector<char>*)_recvBuffer)->reserve(FW_WSSVC_RECV_BUF_SIZE);
}

FWWsSvcSocket::~FWWsSvcSocket()
{
	delete ((std::vector<char>*)_sendBuffer);
	delete ((std::list<size_t>*)_sendDataSize);
	delete ((std::vector<char>*)_recvBuffer);
}

void FWWsSvcSocket::CloseSocket(FW_NET_ACTIVITY_ID activityID)
{
	FWPTW32LockScopeController lsc(&_lock);
	if (activityID != _activityID)
	{
		return;
	}
	if (_wsi)
	{
		struct lws * wsi = (struct lws*)_wsi;
		_wsi = NULL;
		lws_callback_on_writable(wsi);
	}
}

unsigned int FWWsSvcSocket::GetIndex() const
{
	return _index;
}

FW_NET_ACTIVITY_ID FWWsSvcSocket::GetActivityID()
{
	FWPTW32LockScopeController lsc(&_lock);
	return _activityID;
}

bool FWWsSvcSocket::GetSocketInfo(FW_NET_ACTIVITY_ID activityID, FWSvcSocketInfo * out_svcSocketInfo)
{
	FWPTW32LockScopeController lsc(&_lock);
	if (activityID == _activityID)
	{
		if (out_svcSocketInfo)
		{
			*out_svcSocketInfo = _svcSocketInfo;
			return true;
		}
	}
	return false;
}

bool FWWsSvcSocket::SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size)
{
	FWPTW32LockScopeController lsc(&_lock);
	if (activityID != _activityID)
	{
		return false;
	}
	if (!_wsi)
	{
		return false;
	}
	if (size < 0 || (size > 0 && !pData))
	{
		return false;
	}

	((std::vector<char>*)_sendBuffer)->reserve(((std::vector<char>*)_sendBuffer)->size() + LWS_SEND_BUFFER_PRE_PADDING + size + LWS_SEND_BUFFER_POST_PADDING);
	for (int i = 0; i < LWS_SEND_BUFFER_PRE_PADDING; i++)
		((std::vector<char>*)_sendBuffer)->push_back(0);
	for (int i = 0; i < size; i++)
		((std::vector<char>*)_sendBuffer)->push_back(pData[i]);
	for (int i = 0; i < LWS_SEND_BUFFER_POST_PADDING; i++)
		((std::vector<char>*)_sendBuffer)->push_back(0);
	((std::list<size_t>*)_sendDataSize)->push_back((size_t)size);

	lws_callback_on_writable((struct lws*)_wsi);

	return true;
}

bool FWWsSvcSocket::_initSocket(void * wsi, const char * ip46, unsigned short port)
{
	FWPTW32LockScopeController lsc(&_lock);

	//如果初始化失败需要返回false时，必须设置_wsi = NULL

	if (_wsi != NULL)
	{
		FW_LOG_ERROR("%s", "_wsi != NULL");
	}

	volatile static FW_NET_ACTIVITY_ID ActivityIDBase = 0;
	_activityID = InterlockedIncrement64(&ActivityIDBase);
	_wsi = wsi;
	strcpy_s(_svcSocketInfo.Ip46, sizeof(_svcSocketInfo.Ip46), ip46);
	_svcSocketInfo.Port = port;
	_svcSocketInfo.InitTime = FW_TIME();
	_svcSocketInfo.LastReceivedTime = _svcSocketInfo.InitTime;

	((std::vector<char>*)_sendBuffer)->clear();
	((std::list<size_t>*)_sendDataSize)->clear();
	((std::vector<char>*)_recvBuffer)->clear();

	return true;
}

void FWWsSvcSocket::_onCloseSocketWSI(FW_NET_ACTIVITY_ID activityID)
{
	_lock.Lock();
	if (activityID != _activityID)
	{
		_lock.UnLock();
		return;
	}
	FWNetMatch netMatch(_index, _activityID);
	FWSvcSocketInfo svcSocketInfo = _svcSocketInfo;
	_wsi = NULL;
	_lock.UnLock();
	_wsSvcManage->_onWsSvcClose(netMatch, svcSocketInfo);
	_wsSvcManage->_deleteSocket(this);
}

bool FWWsSvcSocket::_onWriteableWSI(FW_NET_ACTIVITY_ID activityID)
{
	FWPTW32LockScopeController lsc(&_lock);
	if (activityID != _activityID)
	{
		return false;
	}
	if (!_wsi)
	{
		return false;
	}
	if (((std::list<size_t>*)_sendDataSize)->size() == 0)
	{
		return true;
	}
	size_t dataSize = ((std::list<size_t>*)_sendDataSize)->front();
	((std::list<size_t>*)_sendDataSize)->pop_front();
	int wr = 0;
	if (dataSize > 0)
	{
		wr = lws_write((struct lws*)_wsi, (unsigned char *)(&(*((std::vector<char>*)_sendBuffer))[LWS_SEND_BUFFER_PRE_PADDING]), dataSize, _MappedDataProtocol(_wsSvcManage->_dataProtocol));
	}
	else
	{
		unsigned char nullMsgBuf[LWS_SEND_BUFFER_PRE_PADDING + LWS_SEND_BUFFER_POST_PADDING + 1] = { 0 };
		wr = lws_write((struct lws*)_wsi, &nullMsgBuf[LWS_SEND_BUFFER_PRE_PADDING], dataSize, _MappedDataProtocol(_wsSvcManage->_dataProtocol));
	}
	if (wr < 0)
	{
		_wsi = NULL;
		return false;
	}
	if ((size_t)wr != dataSize)
	{
		FW_LOG_ERROR("%s", "预料之外的错误，wr != dataSize");
		_wsi = NULL;
		return false;
	}
	((std::vector<char>*)_sendBuffer)->erase(((std::vector<char>*)_sendBuffer)->begin(), ((std::vector<char>*)_sendBuffer)->begin() + (LWS_SEND_BUFFER_PRE_PADDING + dataSize + LWS_SEND_BUFFER_POST_PADDING));
	if (((std::list<size_t>*)_sendDataSize)->size() > 0)
	{
		lws_callback_on_writable((struct lws*)_wsi);
	}
	return true;
}

bool FWWsSvcSocket::_onReceiveWSI(FW_NET_ACTIVITY_ID activityID, bool isFirst, bool isFinal, bool isBinary, char * in, size_t len)
{
	_lock.Lock();
	if (activityID != _activityID)
	{
		_lock.UnLock();
		return false;
	}
	if (!_wsi)
	{
		_lock.UnLock();
		return false;
	}

	const size_t preLen = ((std::vector<char>*)_recvBuffer)->size();
	const size_t totalLen = len + preLen;

	if (totalLen > (size_t)_wsSvcManage->_rSinglePackageMax)
	{
		_wsi = NULL;
		_lock.UnLock();
		return false;
	}

	if (isFirst && preLen > 0)
	{
		FW_LOG_ERROR("%s", "严重错误，isFirst && preLen > 0");
		_wsi = NULL;
		_lock.UnLock();
		return false;
	}

	if (isFinal)
	{
		_svcSocketInfo.LastReceivedTime = FW_TIME();
		char * buffer = (char*)FW_MALLOC((totalLen > 0) ? (totalLen) : (1));
		if (preLen > 0)
		{
			memcpy(buffer, &(*((std::vector<char>*)_recvBuffer))[0], preLen);
			((std::vector<char>*)_recvBuffer)->clear();
		}
		memcpy(buffer + preLen, in, len);
		_lock.UnLock();
		_wsSvcManage->_onWsSvcMessage(FWNetMatch(_index, _activityID), _svcSocketInfo, buffer, (unsigned int)totalLen);
		return true;
	}

	for (size_t i = 0; i < len; i++)
	{
		((std::vector<char>*)_recvBuffer)->push_back(in[i]);
	}
	_lock.UnLock();
	return true;
}


FW_NS_END