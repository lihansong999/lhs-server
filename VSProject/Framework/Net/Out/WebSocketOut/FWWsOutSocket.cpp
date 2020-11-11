#include "FWWsOutSocket.h"
#include "FWWsOutManageBase.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"

#ifndef HAVE_STRUCT_TIMESPEC
#define HAVE_STRUCT_TIMESPEC
#endif // !HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <libwebsockets.h>

FW_NS_BEGIN


static lws_write_protocol _MappedDataProtocol(FWWsOutManageBase::WSDataProtocol dataProtocol)
{
	switch (dataProtocol)
	{
	case FWWsOutManageBase::WSDP_TEXT:
		return LWS_WRITE_TEXT;
		break;
	case FWWsOutManageBase::WSDP_BINARY:
		return LWS_WRITE_BINARY;
		break;
	default:
		return LWS_WRITE_TEXT;
		break;
	}
}

FWWsOutSocket::FWWsOutSocket(unsigned int index, FWWsOutManageBase * wsOutManage)
	:_index(index)
	, _wsOutManage(wsOutManage)
	, _wsi(NULL)
	, _activityID(0)
	, _custom(0LL)
{
	_sendBuffer = new std::vector<char>();
	((std::vector<char>*)_sendBuffer)->reserve(FW_WSOUT_SEND_BUF_SIZE);
	_sendDataSize = new std::list<size_t>();
	_recvBuffer = new std::vector<char>();
	((std::vector<char>*)_recvBuffer)->reserve(FW_WSOUT_RECV_BUF_SIZE);
}

FWWsOutSocket::~FWWsOutSocket()
{
	delete ((std::vector<char>*)_sendBuffer);
	delete ((std::list<size_t>*)_sendDataSize);
	delete ((std::vector<char>*)_recvBuffer);
}

void FWWsOutSocket::CloseSocket(FW_NET_ACTIVITY_ID activityID)
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

unsigned int FWWsOutSocket::GetIndex() const
{
	return _index;
}

FW_ID FWWsOutSocket::GetCustom()
{
	FWPTW32LockScopeController lsc(&_lock);
	return _custom;
}

FW_NET_ACTIVITY_ID FWWsOutSocket::GetActivityID()
{
	FWPTW32LockScopeController lsc(&_lock);
	return _activityID;
}

bool FWWsOutSocket::SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size)
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

bool FWWsOutSocket::_initSocket(void * wsi, FW_ID custom)
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
	_custom = custom;

	((std::vector<char>*)_sendBuffer)->clear();
	((std::list<size_t>*)_sendDataSize)->clear();
	((std::vector<char>*)_recvBuffer)->clear();

	return true;
}

void FWWsOutSocket::_onCloseSocketWSI(FW_NET_ACTIVITY_ID activityID)
{
	_lock.Lock();
	if (activityID != _activityID)
	{
		_lock.UnLock();
		return;
	}
	_wsi = NULL;
	FWNetMatch netMatch(_index, _activityID);
	FW_ID custom = _custom;
	_lock.UnLock();
	_wsOutManage->_onWsOutClose(netMatch, _custom);
	_wsOutManage->_deleteSocket(this);
}

bool FWWsOutSocket::_onWriteableWSI(FW_NET_ACTIVITY_ID activityID)
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
		wr = lws_write((struct lws*)_wsi, (unsigned char *)(&(*((std::vector<char>*)_sendBuffer))[LWS_SEND_BUFFER_PRE_PADDING]), dataSize, _MappedDataProtocol(_wsOutManage->_dataProtocol));
	}
	else
	{
		unsigned char nullMsgBuf[LWS_SEND_BUFFER_PRE_PADDING + LWS_SEND_BUFFER_POST_PADDING + 1] = { 0 };
		wr = lws_write((struct lws*)_wsi, &nullMsgBuf[LWS_SEND_BUFFER_PRE_PADDING], dataSize, _MappedDataProtocol(_wsOutManage->_dataProtocol));
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

bool FWWsOutSocket::_onReceiveWSI(FW_NET_ACTIVITY_ID activityID, bool isFirst, bool isFinal, bool isBinary, char * in, size_t len)
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

	if (totalLen > (size_t)_wsOutManage->_rSinglePackageMax)
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
		char * buffer = (char*)FW_MALLOC((totalLen > 0) ? (totalLen) : (1));
		if (preLen > 0)
		{
			memcpy(buffer, &(*((std::vector<char>*)_recvBuffer))[0], preLen);
			((std::vector<char>*)_recvBuffer)->clear();
		}
		memcpy(buffer + preLen, in, len);
		_lock.UnLock();
		_wsOutManage->_onWsOutMessage(FWNetMatch(_index, _activityID), buffer, (unsigned int)totalLen, _custom);
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