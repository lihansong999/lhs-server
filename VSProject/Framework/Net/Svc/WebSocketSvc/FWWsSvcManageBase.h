#ifndef __FRAMEWORK_WSSVCMANAGEBASE_H__
#define __FRAMEWORK_WSSVCMANAGEBASE_H__

#include "FWWsSvcTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN


/*
WebSocket服务管理基类
可接受连接，以及管理连接的套接字
继承后使用
*/
class FW_DLL FWWsSvcManageBase
{
	friend class FWWsSvcSocket;
	friend int _WS_Callback_Function2(FWWsSvcManageBase *, void *, int, void *, void *, size_t);
	friend void * _Thread_Svc(void *);
	friend void * _Thread_Sub_Svc(void *);
public:
	enum WSAddrFamily
	{
		WSAF_V4ONLY = 0,	//只监听IPv4
		WSAF_V6ONLY,		//只监听IPv6
		/*
		同时监听IPv4和IPv6
		参考 https://tools.ietf.org/html/rfc2553#section-3.7 在接受到使用IPv4协议的连接时，
		IPv4地址被映射到IPv6，例如"150.158.172.137"映射为"::ffff:150.158.172.137"
		*/
		WSAF_V46MAPPED,
	};
	enum WSDataProtocol
	{
		WSDP_TEXT = 0,
		WSDP_BINARY,
	};
public:
	FWWsSvcManageBase();
	~FWWsSvcManageBase();

	/*
	port：监听端口号
	maxConnectedCount：最大承载连接数
	threadCountRS：poll线程数，传0为CPU核心数*2/3（至少会有一个线程），传大于0以所传值为准
	rSinglePackageMax: 接收单个message的最大长度，超过这个长度的会被视为非法连接，立即断开
	dataProtocol：协议数据类型
	addrFamily：选择支持的地址族，默认只支持IPv4
	*/
	bool Start(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, WSAddrFamily wsAddrFamily = WSAF_V4ONLY);

	/*
	port：监听端口号
	maxConnectedCount：最大承载连接数
	threadCountRS：poll线程数，传0为CPU核心数*2/3（至少会有一个线程），传大于0以所传值为准
	certFilePath：公钥文件路径
	keyFilePath：私钥文件路径
	keyFilePassword：私钥密码
	rSinglePackageMax: 接收单个message的最大长度，超过这个长度的会被视为非法连接，立即断开
	dataProtocol：协议数据类型
	addrFamily：选择支持的地址族，默认只支持IPv4
	*/
	bool StartTLS(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, const char * certFilePath, const char * keyFilePath, const char * keyFilePassword = "", int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, WSAddrFamily wsAddrFamily = WSAF_V4ONLY);

	void Stop();

	/*
	支持发送0大小的message
	*/
	bool SendDataWsSvcSocket(const FWNetMatch & netMatch, const char * pData, int size);

	/*
	支持发送0大小的message
	*/
	void SendDataWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseWsSvcSocket(const FWNetMatch & netMatch);

	void CloseWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count);

	bool GetWsSvcSocketInfo(const FWNetMatch & netMatch, FWSvcSocketInfo * out_svcSocketInfo);

	int GetConnectedCount();

protected:
	/*
	可覆盖实现return一个常量字符串，打印LOG时可以区分不同的FWWsSvcManageBase子类
	*/
	virtual const char * _getTitle() const;

	/*
	是否拒绝此次握手协议，默认始终返回false
	true：拒绝
	false：不拒绝
	*/
	virtual bool _onWsSvcReject(const char * ip46, unsigned short port);

	/*
	握手协议已完成
	*/
	virtual void _onWsSvcEstablishe(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;

	/*
	接收已完成
	newBuf：message数据缓冲区，使用完成后必须调用FW_FREE释放（包括size为0时，只要newBuf!=NULL就必须调用FW_FREE释放）
	size：newBuf中的数据大小（支持0大小的message）
	*/
	virtual void _onWsSvcMessage(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) = 0;

	/*
	连接已断开
	*/
	virtual void _onWsSvcClose(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;

private:
	FWWsSvcSocket * _newSocket();
	void _deleteSocket(FWWsSvcSocket * pWsSvcSocket);
	FWWsSvcSocket * _getSocket(unsigned int index);
	void _closeAllUsingSocket();

private:
	volatile bool			_running;

	int						_rSinglePackageMax;

	WSDataProtocol			_dataProtocol;

	volatile long			_connectedCount;

	void				  *	_pthread;

	void				  *	_socketVector;
	void				  *	_socketFreeIndexDeque;
	void				  *	_socketFreeIndexSet;
	FWPTW32LockRecursive	_freeIndexContainerLock;
};


FW_NS_END


#endif //!__FRAMEWORK_WSSVCMANAGEBASE_H__