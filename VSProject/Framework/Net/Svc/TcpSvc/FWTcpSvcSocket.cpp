#include "FWTcpSvcSocket.h"
#include "FWTcpSvcManageBase.h"
#include "../../../Common/FWOutPut.h"
#include "../../../Common/FWTools.h"

FW_NS_BEGIN

FWTcpSvcSocket::FWTcpSvcSocket(unsigned int index, FWTcpSvcManageBase * tcpSvcManage)
	:_index(index)
	, _tcpSvcManage(tcpSvcManage)
	, _activityID(0)
	, _socket(INVALID_SOCKET)
	, _sending(false)
	, _completionReferenceCount(0)
{
	_sendBuffer2 = new std::vector<char>();
	((std::vector<char>*)_sendBuffer2)->reserve(FW_TCPSVC_SEND_BUF_SIZE);
	_recvBuffer2 = new std::vector<char>();
	((std::vector<char>*)_recvBuffer2)->reserve(FW_TCPSVC_RECV_BUF_SIZE);
}

FWTcpSvcSocket::~FWTcpSvcSocket()
{
	delete ((std::vector<char>*)_sendBuffer2);
	delete ((std::vector<char>*)_recvBuffer2);
}

void FWTcpSvcSocket::CloseSocket(FW_NET_ACTIVITY_ID activityID)
{
	FWLockScopeController lsc(&_lock);

	if (activityID != _activityID)
	{
		return;
	}
	if (_socket != INVALID_SOCKET)
	{
		//::shutdown(_socket, SD_BOTH);
		::closesocket(_socket);
		_socket = INVALID_SOCKET;
	}
}

unsigned int FWTcpSvcSocket::GetIndex() const
{
	return _index;
}

FW_NET_ACTIVITY_ID FWTcpSvcSocket::GetActivityID()
{
	FWLockScopeController lsc(&_lock);
	return _activityID;
}

bool FWTcpSvcSocket::GetSocketInfo(FW_NET_ACTIVITY_ID activityID, FWSvcSocketInfo * out_scvSocketInfo)
{
	FWLockScopeController lsc(&_lock);
	if (activityID == _activityID)
	{
		if (out_scvSocketInfo)
		{
			*out_scvSocketInfo = _svcSocketInfo;
			return true;
		}
	}
	return false;
}

bool FWTcpSvcSocket::SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size)
{
	FWLockScopeController lsc(&_lock);

	if (activityID != _activityID)
	{
		return false;
	}
	if (!pData || size <= 0)
	{
		return false;
	}
	if (_socket == INVALID_SOCKET)
	{
		return false;
	}

	((std::vector<char>*)_sendBuffer2)->reserve(((std::vector<char>*)_sendBuffer2)->size() + size);
	for (int i = 0; i < size; i++)
	{
		((std::vector<char>*)_sendBuffer2)->push_back(pData[i]);
	}

	return this->_postSend();
}

bool FWTcpSvcSocket::_initSocket(SOCKET socket, HANDLE completionPortRS, const char * ip46, unsigned short port)
{
	FWLockScopeController lsc(&_lock);

	if (_sending)
	{
		FW_LOG_ERROR("%s", "_sending == true");
	}
	if (_completionReferenceCount != 0)
	{
		FW_LOG_ERROR("%s", "_completionReferenceCount != 0");
	}
	if (_socket != INVALID_SOCKET)
	{
		FW_LOG_ERROR("%s", "_socket != INVALID_SOCKET");
	}

	volatile static FW_NET_ACTIVITY_ID ActivityIDBase = 0;
	_activityID = InterlockedIncrement64(&ActivityIDBase);
	_sending = false;
	_completionReferenceCount = 0;
	_socket = socket;
	strcpy_s(_svcSocketInfo.Ip46, sizeof(_svcSocketInfo.Ip46), ip46);
	_svcSocketInfo.Port = port;
	_svcSocketInfo.InitTime = FW_TIME();
	_svcSocketInfo.LastReceivedTime = _svcSocketInfo.InitTime;

	((std::vector<char>*)_sendBuffer2)->clear();
	((std::vector<char>*)_recvBuffer2)->clear();

	BOOL optval = TRUE;
	if (0 == ::setsockopt(_socket, SOL_SOCKET, SO_KEEPALIVE, (char *)&optval, sizeof(optval)))
	{
		tcp_keepalive in_keepalive;
		tcp_keepalive out_keepalive;
		in_keepalive.onoff = TRUE;
		in_keepalive.keepalivetime = 60000;	//多长时间（ms）没有数据交互就开始发送keep-alive探测数据包。
		in_keepalive.keepaliveinterval = 2000;	//开始探测后，每隔多长时间（ms）发送一个keep-alive探测数据包，2000 XP 2003 默认发5次，Vista之后的系统默认10次。
		DWORD bytesReturned = 0;
		if (0 != WSAIoctl(_socket, SIO_KEEPALIVE_VALS, &in_keepalive, sizeof(in_keepalive), &out_keepalive, sizeof(out_keepalive), &bytesReturned, NULL, NULL))
		{
			FW_LOG_WRNING_DEBUG("%s%d", "SIO_KEEPALIVE_VALS 设置失败，错误码：", (int)WSAGetLastError());
		}
	}
	else
	{
		FW_LOG_WRNING_DEBUG("%s%d", "SO_KEEPALIVE 设置失败，错误码：", (int)WSAGetLastError());
	}

	HANDLE r = CreateIoCompletionPort((HANDLE)_socket, completionPortRS, (ULONG_PTR)this, 0);
	if (r == NULL)
	{
		FW_LOG_ERROR("%s%d", "绑定套接字到完成端口失败，错误码：", (int)GetLastError());
		_socket = INVALID_SOCKET;
		return false;
	}
	return true;
}

void FWTcpSvcSocket::_onSendCompleted(unsigned long numberOfBytesTransferred)
{
	_lock.Lock();

	_sending = false;
	_completionReferenceCount--;

	bool isComplete = false;
	bool canDelete = _completionReferenceCount == 0;

	do
	{
		if (isNegative(_completionReferenceCount))
		{
			FW_LOG_ERROR("%s", "_completionReferenceCount < 0");
			canDelete = true;
			break;
		}
		if (numberOfBytesTransferred == 0)
		{
			break;
		}
		if (isNegative(numberOfBytesTransferred))
		{
			FW_LOG_ERROR("%s", "numberOfBytesTransferred < 0");
			break;
		}
		if (((std::vector<char>*)_sendBuffer2)->size() < numberOfBytesTransferred)
		{
			FW_LOG_ERROR("%s", "_sendBuffer2->size() < numberOfBytesTransferred");
			break;
		}

		((std::vector<char>*)_sendBuffer2)->erase(((std::vector<char>*)_sendBuffer2)->begin(), ((std::vector<char>*)_sendBuffer2)->begin() + numberOfBytesTransferred);

		if (!this->_postSend())
		{
			break;
		}

		isComplete = true;
	} while (false);
	
	FWSvcSocketInfo svcSocketInfo = _svcSocketInfo;
	FWNetMatch netMatch(_index, _activityID);

	if (!isComplete)
	{
		this->CloseSocket(_activityID);
	}

	_lock.UnLock();

	if (!isComplete && canDelete)
	{
		_tcpSvcManage->_onTcpSvcClose(netMatch, svcSocketInfo);
		_tcpSvcManage->_deleteSocket(this);
	}
}

void FWTcpSvcSocket::_onRecvCompleted(unsigned long numberOfBytesTransferred)
{
	_lock.Lock();

	_completionReferenceCount--;
	
	bool isComplete = false;
	bool canDelete = _completionReferenceCount == 0;
	char * buffer = nullptr;
	unsigned int bufSize = 0;

	do
	{
		if (isNegative(_completionReferenceCount))
		{
			FW_LOG_ERROR("%s", "_completionReferenceCount < 0");
			canDelete = true;
			break;
		}
		if (numberOfBytesTransferred == 0)
		{
			break;
		}
		if (isNegative(numberOfBytesTransferred))
		{
			FW_LOG_ERROR("%s", "numberOfBytesTransferred < 0");
			break;
		}
		if (numberOfBytesTransferred > FW_TCPSVC_RECV_BUF_SIZE)
		{
			FW_LOG_ERROR("%s", "numberOfBytesTransferred > FW_TCPSVC_RECV_BUF_SIZE");
			break;
		}

		unsigned int surplusSize = (unsigned int)numberOfBytesTransferred;
		bool handled = false;
		if (((std::vector<char>*)_recvBuffer2)->size() == 0)
		{
			handled = true;
			unsigned int usedSize = _tcpSvcManage->_onTcpSvcRecvTest(_recvBuffer, (unsigned int)numberOfBytesTransferred);
			if (isNegative(usedSize))
			{
				FW_LOG_WRNING_DEBUG("%s%s", "usedSize < 0，IP：", _svcSocketInfo.Ip46);
				break;
			}
			if (usedSize > (unsigned int)numberOfBytesTransferred)
			{
				FW_LOG_ERROR("%s", "usedSize > numberOfBytesTransferred");
				break;
			}
			if (usedSize > 0)
			{
				_svcSocketInfo.LastReceivedTime = FW_TIME();

				buffer = (char*)FW_MALLOC(sizeof(char) * usedSize);
				bufSize = usedSize;
				memcpy(buffer, _recvBuffer, usedSize);
			}
			surplusSize = (unsigned int)numberOfBytesTransferred - usedSize;
		}
		if (surplusSize > 0)
		{
			const unsigned int offset = (unsigned int)numberOfBytesTransferred - surplusSize;
			((std::vector<char>*)_recvBuffer2)->reserve(((std::vector<char>*)_recvBuffer2)->size() + surplusSize);
			for (unsigned int i = offset; i < surplusSize + offset; i++)
			{
				((std::vector<char>*)_recvBuffer2)->push_back(_recvBuffer[i]);
			}
		}
		if (!handled)
		{
			unsigned int usedSize2 = (unsigned int)_tcpSvcManage->_onTcpSvcRecvTest(&((*((std::vector<char>*)_recvBuffer2))[0]), (unsigned int)((std::vector<char>*)_recvBuffer2)->size());
			if (isNegative(usedSize2))
			{
				FW_LOG_WRNING_DEBUG("%s%s", "usedSize2 < 0，IP：", _svcSocketInfo.Ip46);
				break;
			}
			if (((std::vector<char>*)_recvBuffer2)->size() < usedSize2)
			{
				FW_LOG_ERROR("%s", "_recvBuffer2->size() < usedSize2");
				break;
			}
			if (usedSize2 > 0)
			{
				_svcSocketInfo.LastReceivedTime = FW_TIME();

				buffer = (char*)FW_MALLOC(sizeof(char) * usedSize2);
				bufSize = usedSize2;
				memcpy(buffer, &((*((std::vector<char>*)_recvBuffer2))[0]), usedSize2);

				((std::vector<char>*)_recvBuffer2)->erase(((std::vector<char>*)_recvBuffer2)->begin(), ((std::vector<char>*)_recvBuffer2)->begin() + usedSize2);
			}
		}

		if (!this->_postRecv())
		{
			break;
		}

		isComplete = true;
	} while (false);
	
	FWSvcSocketInfo svcSocketInfo = _svcSocketInfo;
	FWNetMatch netMatch(_index, _activityID);

	if (!isComplete)
	{
		this->CloseSocket(_activityID);
	}

	_lock.UnLock();

	if (buffer)
	{
		_tcpSvcManage->_onTcpSvcRecvCompleted(netMatch, svcSocketInfo, buffer, bufSize);
	}

	if (!isComplete && canDelete)
	{
		_tcpSvcManage->_onTcpSvcClose(netMatch, svcSocketInfo);
		_tcpSvcManage->_deleteSocket(this);
	}
}

void FWTcpSvcSocket::_postRecvForAcceptReadying()
{
	FWLockScopeController lsc(&_lock);

	_completionReferenceCount++;
}

void FWTcpSvcSocket::_postRecvForAccept()
{
	_lock.Lock();

	_completionReferenceCount--; //Readying

	bool isComplete = false;
	bool canDelete = _completionReferenceCount == 0;
	
	if (_socket != INVALID_SOCKET)
	{
		DWORD dwFlags = 0;
		DWORD dwBytes = 0;
		_recvOverLapped.Clear();
		_recvOverLapped.Type = FW_OLCT_RECV;
		_recvOverLapped.WsaBuf.buf = _recvBuffer;
		_recvOverLapped.WsaBuf.len = FW_TCPSVC_RECV_BUF_SIZE;
		int r = WSARecv(_socket, &_recvOverLapped.WsaBuf, 1, &dwBytes, &dwFlags, (OVERLAPPED*)&_recvOverLapped.Overlapped, NULL);

		if (r == SOCKET_ERROR)
		{
			int e = WSAGetLastError();
			if (e == WSA_IO_PENDING)
			{
				_completionReferenceCount++;
				isComplete = true;
			}
			else
			{
				if (e != WSAENETDOWN && e != WSAENETRESET && e != WSAECONNABORTED && e != WSAECONNRESET && e != WSAENOTCONN && e != WSAESHUTDOWN /*&& e != WSAETIMEDOUT*/ && e != WSAEDISCON /*&& e != WSA_OPERATION_ABORTED*/)
				{
					FW_LOG_ERROR("%s%d", "WSARecv 失败，出现未预见错误，错误码：", e);
				}
			}
		}
		else if (r == 0)
		{
			_completionReferenceCount++;
			isComplete = true;
		}
		else
		{
			FW_LOG_ERROR("%s%d", "WSARecv 失败，返回值：", r);
		}
	}

	FWSvcSocketInfo svcSocketInfo = _svcSocketInfo;
	FWNetMatch netMatch(_index, _activityID);

	if (!isComplete)
	{
		this->CloseSocket(_activityID);
	}

	_lock.UnLock();

	if (!isComplete && canDelete)
	{
		_tcpSvcManage->_onTcpSvcClose(netMatch, svcSocketInfo);
		_tcpSvcManage->_deleteSocket(this);
	}
}

bool FWTcpSvcSocket::_postSend()
{
	FWLockScopeController lsc(&_lock);

	if (_sending)
	{
		return true;
	}
	if (_socket == INVALID_SOCKET)
	{
		return false;
	}
	if (((std::vector<char>*)_sendBuffer2)->size() == 0)
	{
		return true;
	}

	size_t sendSize = (((std::vector<char>*)_sendBuffer2)->size() > FW_TCPSVC_SEND_BUF_SIZE) ? (FW_TCPSVC_SEND_BUF_SIZE) : (((std::vector<char>*)_sendBuffer2)->size());
	memcpy(_sendBuffer, &((*((std::vector<char>*)_sendBuffer2))[0]), sendSize);

	_sendOverLapped.Clear();
	_sendOverLapped.Type = FW_OLCT_SEND;
	_sendOverLapped.WsaBuf.buf = _sendBuffer;
	_sendOverLapped.WsaBuf.len = (ULONG)sendSize;
	int r = WSASend(_socket, &_sendOverLapped.WsaBuf, 1, NULL, 0, (OVERLAPPED*)&_sendOverLapped.Overlapped, NULL);

	if (r == SOCKET_ERROR)
	{
		int e = WSAGetLastError();
		if (e == WSA_IO_PENDING)
		{
			_completionReferenceCount++;
			_sending = true;
			return true;
		}
		else
		{
			if (e != WSAENETDOWN && e != WSAENETRESET && e != WSAECONNABORTED && e != WSAECONNRESET && e != WSAENOTCONN && e != WSAESHUTDOWN /*&& e != WSA_OPERATION_ABORTED*/)
			{
				FW_LOG_ERROR("%s%d", "WSASend 失败，出现未预见错误，错误码：", e);
			}
			return false;
		}
	}
	else if (r == 0)
	{
		_completionReferenceCount++;
		_sending = true;
		return true;
	}

	FW_LOG_ERROR("%s%d", "WSASend 失败，返回值：", r);

	return false;
}

bool FWTcpSvcSocket::_postRecv()
{
	FWLockScopeController lsc(&_lock);

	if (_socket == INVALID_SOCKET)
	{
		return false;
	}

	DWORD dwFlags = 0;
	DWORD dwBytes = 0;
	_recvOverLapped.Clear();
	_recvOverLapped.Type = FW_OLCT_RECV;
	_recvOverLapped.WsaBuf.buf = _recvBuffer;
	_recvOverLapped.WsaBuf.len = FW_TCPSVC_RECV_BUF_SIZE;
	int r = WSARecv(_socket, &_recvOverLapped.WsaBuf, 1, &dwBytes, &dwFlags, (OVERLAPPED*)&_recvOverLapped.Overlapped, NULL);

	if (r == SOCKET_ERROR)
	{
		int e = WSAGetLastError();
		if (e == WSA_IO_PENDING)
		{
			_completionReferenceCount++;
			return true;
		}
		else
		{
			if (e != WSAENETDOWN && e != WSAENETRESET && e != WSAECONNABORTED && e != WSAECONNRESET && e != WSAENOTCONN && e != WSAESHUTDOWN /*&& e != WSAETIMEDOUT*/ && e != WSAEDISCON /*&& e != WSA_OPERATION_ABORTED*/)
			{
				FW_LOG_ERROR("%s%d", "WSARecv 失败，出现未预见错误，错误码：", e);
			}
			return false;
		}
	}
	else if (r == 0)
	{
		_completionReferenceCount++;
		return true;
	}

	FW_LOG_ERROR("%s%d", "WSARecv 失败，返回值：", r);

	return false;
}


FW_NS_END