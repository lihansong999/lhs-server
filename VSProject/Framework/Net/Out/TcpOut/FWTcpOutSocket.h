#ifndef __FRAMEWORK_TCPOUTSOCKET_H__
#define __FRAMEWORK_TCPOUTSOCKET_H__

#include "FWTcpOutTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP向外连接套接字
*/
class FW_DLL FWTcpOutSocket
{
	friend class FWTcpOutManageBase;
public:
	FWTcpOutSocket(unsigned int index, FWTcpOutManageBase * tcpOutManage);
	FWTcpOutSocket(const FWTcpOutSocket & other) = delete;
	FWTcpOutSocket& operator=(const FWTcpOutSocket & other) = delete;
	FWTcpOutSocket(FWTcpOutSocket && other) = delete;
	FWTcpOutSocket& operator=(FWTcpOutSocket && other) = delete;
	virtual ~FWTcpOutSocket();

	void CloseSocket(FW_NET_ACTIVITY_ID activityID);

	unsigned int GetIndex() const;

	FW_ID GetCustom();

	FW_NET_ACTIVITY_ID GetActivityID();

	bool SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size);

private:
	bool _initSocket(SOCKET socket, HANDLE completionPortRS, FW_ID custom);

	void _onSendCompleted(unsigned long numberOfBytesTransferred);

	void _onRecvCompleted(unsigned long numberOfBytesTransferred);

	void _postRecvForConnectResultReadying();

	void _postRecvForConnectResult();

	bool _postSend();

	bool _postRecv();

private:
	const unsigned int			_index;

	FW_ID						_custom;

	FWTcpOutManageBase	*		_tcpOutManage;

	volatile FW_NET_ACTIVITY_ID	_activityID;

	volatile LONG				_completionReferenceCount;

	SOCKET						_socket;

	FWLockRecursive				_lock;

	FWOverLappedContext			_sendOverLapped;
	char						_sendBuffer[FW_TCPOUT_SEND_BUF_SIZE];
	void					  *	_sendBuffer2;
	volatile bool				_sending;

	FWOverLappedContext			_recvOverLapped;
	char						_recvBuffer[FW_TCPOUT_RECV_BUF_SIZE];
	void					  *	_recvBuffer2;
};



FW_NS_END


#endif //!__FRAMEWORK_TCPOUTSOCKET_H__