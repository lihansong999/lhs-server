#ifndef __FRAMEWORK_TCPSVCMANAGEBASE_H__
#define __FRAMEWORK_TCPSVCMANAGEBASE_H__

#include "FWTcpSvcTypeDef.h"
#include "../../../Common/FWLock.h"
#include "FWTcpListenSocket.h"

FW_NS_BEGIN


/*
TCP服务管理基类
可接受连接，以及管理连接的套接字
继承后使用
*/
class FW_DLL FWTcpSvcManageBase
{
	friend class FWTcpSvcSocket;
public:
	FWTcpSvcManageBase();
	virtual ~FWTcpSvcManageBase();

	/*
	port：监听端口号
	maxConnectedCount：最大承载连接数
	threadCountRS：IO线程数，传0为CPU核心数-1（至少会有一个线程），传大于0以所传值为准
	addrFamily：选择支持的地址族，默认只支持IPv4
	*/
	bool Start(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, FWTcpListenSocket::AddrFamily addrFamily = FWTcpListenSocket::AF_V4ONLY);
	
	void Stop();

	bool SendDataTcpSvcSocket(const FWNetMatch & netMatch, const char * pData, int size);

	void SendDataTcpSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseTcpSvcSocket(const FWNetMatch & netMatch);

	void CloseTcpSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count);

	bool GetTcpSvcSocketInfo(const FWNetMatch & netMatch, FWSvcSocketInfo * out_svcSocketInfo);

	int GetConnectedCount();

protected:
	/* 
	可覆盖实现return一个常量字符串，打印LOG时可以区分不同的FWTcpSvcManageBase子类 
	*/
	virtual const char * _getTitle() const;

	/*
	是否拒绝此次连接，默认始终返回false
	true：拒绝
	false：不拒绝
	*/
	virtual bool _onTcpSvcReject(const char * ip46, unsigned short port);

	/*
	如果连接数已达上线，此时有连接进来会被自动closesocket，并调用此函数
	*/
	virtual void _onTcpSvcOverloaded();

	/* 
	连接已完成
	*/
	virtual void _onTcpSvcAccepted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;
	
	/*
	接收验证
	return = 0：buf里的数据还不够组成一个完整消息包，继续等待下次
	return > 0：buf里的数据能够组成一个或多个完整消息包（如果能组成多个完整消息包，就必须返回这多个包的大小之和），稍后将会调用_onTcpSvcRecvCompleted
	return < 0：断开此连接
	*/
	virtual unsigned int _onTcpSvcRecvTest(const char * buf, unsigned int size) = 0;

	/* 
	接收已完成
	newBuf：数据缓冲区，使用完成后必须调用FW_FREE释放
	size：newBuf中的有效数据大小，也就是前一次调用_onTcpSvcRecvTest所返回的大于0的值
	*/
	virtual void _onTcpSvcRecvCompleted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) = 0;
	
	/* 
	连接已断开
	*/
	virtual void _onTcpSvcClose(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;

private:
	FWTcpSvcSocket * _newSocket(bool * out_overloaded);
	void _deleteSocket(FWTcpSvcSocket * pTcpSvcSocket);
	FWTcpSvcSocket * _getSocket(unsigned int index);

	void _threadAccept(void * pPromiseStart);
	void _threadSocketRS(void * pPromiseStart);

private:
	volatile bool				_running;

	volatile long				_connectedCount;

	FWTcpListenSocket			_tcpListenSocket;

	void					*	_pThreadAccept;

	HANDLE						_completionPortRS;

	void					*	_pThreadSocketRSVector;
	
	void					*	_socketVector;
	void					*	_socketFreeIndexDeque;
	void					*	_socketFreeIndexSet;
	FWLockRecursive				_freeIndexContainerLock;
};



FW_NS_END


#endif //!__FRAMEWORK_TCPSVCMANAGEBASE_H__