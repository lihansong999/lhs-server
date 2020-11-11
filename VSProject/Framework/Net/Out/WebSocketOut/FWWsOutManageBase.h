#ifndef __FRAMEWORK_WSOUTMANAGEBASE_H__
#define __FRAMEWORK_WSOUTMANAGEBASE_H__

#include "FWWsOutTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN

/*
WebSocket向外连接管理基类
可接向外连接，以及管理连接的套接字
继承后使用
*/
class FW_DLL FWWsOutManageBase
{
	friend class FWWsOutSocket;
	friend int _WS_Callback_Function2(FWWsOutManageBase *, void *, int, void *, void *, size_t);
	friend void * _Thread_Out(void *);
	friend void _Connect(FWWsOutManageBase * self, void * context);
public:
	enum WSDataProtocol
	{
		WSDP_TEXT = 0,
		WSDP_BINARY,
	};
public:
	FWWsOutManageBase();
	~FWWsOutManageBase();

	/*
	maxConnectedCount：管理的最大向外连接数
	rSinglePackageMax: 接收单个message的最大长度，超过这个长度的会被视为非法连接，立即断开
	dataProtocol：协议数据类型
	disableIPv6：关闭IPv6支持，如果为false，Connect的host参数必须为域名，点分十进制地址将无法连接
	*/
	bool Start(unsigned int maxConnectedCount, int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, bool disableIPv6 = true);

	void Stop();

	/*
	当Start完成后，一旦调用此函数，那么在之后的某个时间必然会回调_onWsOutConnectResult或_onWsOutOverloaded
	custom：自定义参数，会在之后的回调中原样传入
	allowCertVerify：信任自签发证书并忽略域名检测和过期失效检测
	*/
	void Connect(const char * host, FW_ID custom = 0LL, bool allowCertVerify = true);

	/*
	支持发送0大小的message
	*/
	bool SendDataWsOutSocket(const FWNetMatch & netMatch, const char * pData, int size);

	/*
	支持发送0大小的message
	*/
	void SendDataWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseWsOutSocket(const FWNetMatch & netMatch);

	void CloseWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count);

protected:
	/*
	可覆盖实现return一个常量字符串，打印LOG时可以区分不同的FWWsOutManageBase子类
	*/
	virtual const char * _getTitle() const;

	/*
	如果向外连接数已达上线，此时握手协议成功后会被自动断开，并调用此函数，而且不会再调用_onWsOutConnectResult
	*/
	virtual void _onWsOutOverloaded(FW_ID custom) = 0;

	/*
	连接结果
	succeed为true时netMatch参数才有意义
	*/
	virtual void _onWsOutConnectResult(bool succeed, const FWNetMatch & netMatch, FW_ID custom) = 0;

	/*
	接收已完成
	newBuf：message数据缓冲区，使用完成后必须调用FW_FREE释放（包括size为0时，只要newBuf!=NULL就必须调用FW_FREE释放）
	size：newBuf中的数据大小（支持0大小的message）
	*/
	virtual void _onWsOutMessage(const FWNetMatch & netMatch, char * newBuf, unsigned int size, FW_ID custom) = 0;

	/*
	连接已断开
	*/
	virtual void _onWsOutClose(const FWNetMatch & netMatch, FW_ID custom) = 0;

private:
	FWWsOutSocket * _newSocket();
	void _deleteSocket(FWWsOutSocket * pWsOutSocket);
	FWWsOutSocket * _getSocket(unsigned int index);
	void _closeAllUsingSocket();
	void _cancelAllConnectEvent();

private:
	volatile bool			_running;

	int						_rSinglePackageMax;

	WSDataProtocol			_dataProtocol;

	void				  *	_pthread;

	void                  *	_connectEventList;
	FWPTW32LockRecursive	_connectEventContainerLock;

	intptr_t				_wsiSessionDataActivity;
	void				  *	_wsiSessionDataMap;

	void				  *	_socketVector;
	void				  *	_socketFreeIndexDeque;
	void				  *	_socketFreeIndexSet;
	FWPTW32LockRecursive	_freeIndexContainerLock;
};


FW_NS_END


#endif //!__FRAMEWORK_WSOUTMANAGEBASE_H__