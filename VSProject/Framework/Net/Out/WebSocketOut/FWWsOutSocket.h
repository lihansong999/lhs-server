#ifndef __FRAMEWORK_WSOUTSOCKET_H__
#define __FRAMEWORK_WSOUTSOCKET_H__

#include "FWWsOutTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN


/*
WebSocket向外连接接字
*/
class FW_DLL FWWsOutSocket
{
	friend class FWWsOutManageBase;
	friend int _WS_Callback_Function2(FWWsOutManageBase *, void *, int, void *, void *, size_t);
public:
	FWWsOutSocket(unsigned int index, FWWsOutManageBase * wsOutManage);
	FWWsOutSocket(const FWWsOutSocket & other) = delete;
	FWWsOutSocket& operator=(const FWWsOutSocket & other) = delete;
	FWWsOutSocket(FWWsOutSocket && other) = delete;
	FWWsOutSocket& operator=(FWWsOutSocket && other) = delete;
	virtual ~FWWsOutSocket();

	void CloseSocket(FW_NET_ACTIVITY_ID activityID);

	unsigned int GetIndex() const;

	FW_ID GetCustom();

	FW_NET_ACTIVITY_ID GetActivityID();

	bool SendData(FW_NET_ACTIVITY_ID activityID, const char * pData, int size);

private:
	bool _initSocket(void * wsi, FW_ID custom);

	void _onCloseSocketWSI(FW_NET_ACTIVITY_ID activityID);

	bool _onWriteableWSI(FW_NET_ACTIVITY_ID activityID);

	bool _onReceiveWSI(FW_NET_ACTIVITY_ID activityID, bool isFirst, bool isFinal, bool isBinary, char * in, size_t len);

private:
	const unsigned int			_index;

	FW_ID						_custom;

	FWWsOutManageBase		  *	_wsOutManage;

	volatile void			  *	_wsi;

	volatile FW_NET_ACTIVITY_ID	_activityID;

	FWPTW32LockRecursive		_lock;

	void					  *	_sendBuffer;
	void					  *	_sendDataSize;

	void					  *	_recvBuffer;
};


FW_NS_END


#endif //!__FRAMEWORK_WSOUTSOCKET_H__