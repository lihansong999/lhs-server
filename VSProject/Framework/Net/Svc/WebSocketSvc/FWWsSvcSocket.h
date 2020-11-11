#ifndef __FRAMEWORK_WSSVCSOCKET_H__
#define __FRAMEWORK_WSSVCSOCKET_H__

#include "FWWsSvcTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN


/*
WebSocket·þÎñÌ×½Ó×Ö
*/
class FW_DLL FWWsSvcSocket
{
	friend class FWWsSvcManageBase;
	friend int _WS_Callback_Function2(FWWsSvcManageBase *, void *, int, void *, void *, size_t);
public:
	FWWsSvcSocket(unsigned int index, FWWsSvcManageBase * wsSvcManage);
	FWWsSvcSocket(const FWWsSvcSocket & other) = delete;
	FWWsSvcSocket& operator=(const FWWsSvcSocket & other) = delete;
	FWWsSvcSocket(FWWsSvcSocket && other) = delete;
	FWWsSvcSocket& operator=(FWWsSvcSocket && other) = delete;
	virtual ~FWWsSvcSocket();

	void CloseSocket(FW_NET_ACTIVITY_ID activityID);

	unsigned int GetIndex() const;

	FW_NET_ACTIVITY_ID GetActivityID();

	bool GetSocketInfo(FW_NET_ACTIVITY_ID activityID, FWSvcSocketInfo * out_svcSocketInfo);

	bool SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size);

private:
	bool _initSocket(void * wsi, const char * ip46, unsigned short port);

	void _onCloseSocketWSI(FW_NET_ACTIVITY_ID activityID);

	bool _onWriteableWSI(FW_NET_ACTIVITY_ID activityID);

	bool _onReceiveWSI(FW_NET_ACTIVITY_ID activityID, bool isFirst, bool isFinal, bool isBinary, char * in, size_t len);

private:
	const unsigned int			_index;

	FWWsSvcManageBase		  *	_wsSvcManage;

	volatile void			  *	_wsi;

	volatile FW_NET_ACTIVITY_ID	_activityID;

	FWSvcSocketInfo				_svcSocketInfo;

	FWPTW32LockRecursive		_lock;

	void					  *	_sendBuffer;
	void					  *	_sendDataSize;

	void					  *	_recvBuffer;
};


FW_NS_END


#endif //!__FRAMEWORK_WSSVCSOCKET_H__