#ifndef __FRAMEWORK_TCPSVCMANAGEBASE_H__
#define __FRAMEWORK_TCPSVCMANAGEBASE_H__

#include "FWTcpSvcTypeDef.h"
#include "../../../Common/FWLock.h"
#include "FWTcpListenSocket.h"

FW_NS_BEGIN


/*
TCP����������
�ɽ������ӣ��Լ��������ӵ��׽���
�̳к�ʹ��
*/
class FW_DLL FWTcpSvcManageBase
{
	friend class FWTcpSvcSocket;
public:
	FWTcpSvcManageBase();
	virtual ~FWTcpSvcManageBase();

	/*
	port�������˿ں�
	maxConnectedCount��������������
	threadCountRS��IO�߳�������0ΪCPU������-1�����ٻ���һ���̣߳���������0������ֵΪ׼
	addrFamily��ѡ��֧�ֵĵ�ַ�壬Ĭ��ֻ֧��IPv4
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
	�ɸ���ʵ��returnһ�������ַ�������ӡLOGʱ�������ֲ�ͬ��FWTcpSvcManageBase���� 
	*/
	virtual const char * _getTitle() const;

	/*
	�Ƿ�ܾ��˴����ӣ�Ĭ��ʼ�շ���false
	true���ܾ�
	false�����ܾ�
	*/
	virtual bool _onTcpSvcReject(const char * ip46, unsigned short port);

	/*
	����������Ѵ����ߣ���ʱ�����ӽ����ᱻ�Զ�closesocket�������ô˺���
	*/
	virtual void _onTcpSvcOverloaded();

	/* 
	���������
	*/
	virtual void _onTcpSvcAccepted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;
	
	/*
	������֤
	return = 0��buf������ݻ��������һ��������Ϣ���������ȴ��´�
	return > 0��buf��������ܹ����һ������������Ϣ�����������ɶ��������Ϣ�����ͱ��뷵���������Ĵ�С֮�ͣ����Ժ󽫻����_onTcpSvcRecvCompleted
	return < 0���Ͽ�������
	*/
	virtual unsigned int _onTcpSvcRecvTest(const char * buf, unsigned int size) = 0;

	/* 
	���������
	newBuf�����ݻ�������ʹ����ɺ�������FW_FREE�ͷ�
	size��newBuf�е���Ч���ݴ�С��Ҳ����ǰһ�ε���_onTcpSvcRecvTest�����صĴ���0��ֵ
	*/
	virtual void _onTcpSvcRecvCompleted(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) = 0;
	
	/* 
	�����ѶϿ�
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