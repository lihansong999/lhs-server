#ifndef __FRAMEWORK_TCPSVCSOCKET_H__
#define __FRAMEWORK_TCPSVCSOCKET_H__

#include "FWTcpSvcTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP·þÎñÌ×½Ó×Ö
*/
class FW_DLL FWTcpSvcSocket
{
	friend class FWTcpSvcManageBase;
public:
	FWTcpSvcSocket(unsigned int index, FWTcpSvcManageBase * tcpSvcManage);
	FWTcpSvcSocket(const FWTcpSvcSocket & other) = delete;
	FWTcpSvcSocket& operator=(const FWTcpSvcSocket & other) = delete;
	FWTcpSvcSocket(FWTcpSvcSocket && other) = delete;
	FWTcpSvcSocket& operator=(FWTcpSvcSocket && other) = delete;
	virtual ~FWTcpSvcSocket();

	void CloseSocket(FW_NET_ACTIVITY_ID activityID);

	unsigned int GetIndex() const;

	FW_NET_ACTIVITY_ID GetActivityID();

	bool GetSocketInfo(FW_NET_ACTIVITY_ID activityID, FWSvcSocketInfo * out_scvSocketInfo);

	bool SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size);

private:
	bool _initSocket(SOCKET socket, HANDLE completionPortRS, const char * ip46, unsigned short port);

	void _onSendCompleted(unsigned long numberOfBytesTransferred);

	void _onRecvCompleted(unsigned long numberOfBytesTransferred);

	void _postRecvForAcceptReadying();

	void _postRecvForAccept();

	bool _postSend();

	bool _postRecv();

private:
	const unsigned int			_index;

	FWTcpSvcManageBase	*		_tcpSvcManage;

	volatile FW_NET_ACTIVITY_ID	_activityID;

	volatile LONG				_completionReferenceCount;

	SOCKET						_socket;

	FWSvcSocketInfo				_svcSocketInfo;

	FWLockRecursive				_lock;

	FWOverLappedContext			_sendOverLapped;
	char						_sendBuffer[FW_TCPSVC_SEND_BUF_SIZE];
	void					  *	_sendBuffer2;
	volatile bool				_sending;

	FWOverLappedContext			_recvOverLapped;
	char						_recvBuffer[FW_TCPSVC_RECV_BUF_SIZE];
	void					  *	_recvBuffer2;
};



FW_NS_END


#endif //!__FRAMEWORK_TCPSVCSOCKET_H__