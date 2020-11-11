#ifndef __FRAMEWORK_TCPOUTMANAGEBASE_H__
#define __FRAMEWORK_TCPOUTMANAGEBASE_H__

#include "FWTcpOutTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP向外连接管理基类
可接向外连接，以及管理连接的套接字
继承后使用
*/
class FW_DLL FWTcpOutManageBase
{
	friend class FWTcpOutSocket;
public:
	FWTcpOutManageBase();
	virtual ~FWTcpOutManageBase();

	/*
	maxConnectedCount：管理的最大向外连接数
	threadCountRS：IO线程数，传0为使用1个IO线程，传大于0以所传值为准
	*/
	bool Start(unsigned int maxConnectedCount, unsigned int threadCountRS = 0);
	
	void Stop();

	/*
	当Start完成后，一旦调用此函数，那么在之后的某个时间必然会回调_onTcpOutConnectResult或_onTcpOutOverloaded
	custom为自定义参数，会在之后的回调中原样传入
	*/
	void Connect(const char * addr, unsigned short port, FW_ID custom = 0LL);

	bool SendDataTcpOutSocket(const FWNetMatch & netMatch, const char * pData, int size);

	void SendDataTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseTcpOutSocket(const FWNetMatch & netMatch);

	void CloseTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count);

protected:
	/* 
	可覆盖实现return一个常量字符串，打印LOG时可以区分不同的FWTcpOutManageBase子类 
	*/
	virtual const char * _getTitle() const;

	/*
	如果向外连接数已达上线，此时连接成功后会被自动closesocket，并调用此函数，而且不会再调用_onTcpOutConnectResult
	*/
	virtual void _onTcpOutOverloaded(FW_ID custom) = 0;

	/*
	连接结果
	succeed为true时netMatch参数才有意义
	*/
	virtual void _onTcpOutConnectResult(bool succeed, const FWNetMatch & netMatch, FW_ID custom) = 0;
	
	/*
	接收验证
	return = 0：buf里的数据还不够组成一个完整消息包，继续等待下次
	return > 0：buf里的数据能够组成一个或多个完整消息包（如果能组成多个完整消息包，就必须返回这多个包的大小之和），稍后将会调用_onTcpOutRecvCompleted
	return < 0：断开此连接
	*/
	virtual unsigned int _onTcpOutRecvTest(const char * buf, unsigned int size, FW_ID custom) = 0;

	/* 
	接收已完成
	newBuf：数据缓冲区，使用完成后必须调用FW_FREE释放
	size：newBuf中的有效数据大小，也就是前一次调用_onTcpOutRecvTest所返回的大于0的值
	*/
	virtual void _onTcpOutRecvCompleted(const FWNetMatch & netMatch, char * newBuf, unsigned int size, FW_ID custom) = 0;
	
	/* 
	连接已断开
	*/
	virtual void _onTcpOutClose(const FWNetMatch & netMatch, FW_ID custom) = 0;

private:
	void _threadConnect(void * pPromiseStart, FW_ID id, const char * addr, unsigned short port, FW_ID custom);
	bool _selectConnect(SOCKET socket);

	FWTcpOutSocket * _newSocket(bool * out_overloaded);
	void _deleteSocket(FWTcpOutSocket * pTcpOutSocket);
	FWTcpOutSocket * _getSocket(unsigned int index);

	void _threadSocketRS(void * pPromiseStart);

private:
	volatile bool				_running;

	HANDLE						_completionPortRS;

	void					*	_pThreadSocketRSVector;

	void					*	_pThreadConnectIDSet;
	void					*	_threadConnectIDContainerMutex;

	void					*	_socketVector;
	void					*	_socketFreeIndexDeque;
	void					*	_socketFreeIndexSet;
	FWLockRecursive				_freeIndexContainerLock;
};



FW_NS_END


#endif //!__FRAMEWORK_TCPOUTMANAGEBASE_H__