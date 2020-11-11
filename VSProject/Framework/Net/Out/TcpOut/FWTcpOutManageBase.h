#ifndef __FRAMEWORK_TCPOUTMANAGEBASE_H__
#define __FRAMEWORK_TCPOUTMANAGEBASE_H__

#include "FWTcpOutTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP�������ӹ������
�ɽ��������ӣ��Լ��������ӵ��׽���
�̳к�ʹ��
*/
class FW_DLL FWTcpOutManageBase
{
	friend class FWTcpOutSocket;
public:
	FWTcpOutManageBase();
	virtual ~FWTcpOutManageBase();

	/*
	maxConnectedCount��������������������
	threadCountRS��IO�߳�������0Ϊʹ��1��IO�̣߳�������0������ֵΪ׼
	*/
	bool Start(unsigned int maxConnectedCount, unsigned int threadCountRS = 0);
	
	void Stop();

	/*
	��Start��ɺ�һ�����ô˺�������ô��֮���ĳ��ʱ���Ȼ��ص�_onTcpOutConnectResult��_onTcpOutOverloaded
	customΪ�Զ������������֮��Ļص���ԭ������
	*/
	void Connect(const char * addr, unsigned short port, FW_ID custom = 0LL);

	bool SendDataTcpOutSocket(const FWNetMatch & netMatch, const char * pData, int size);

	void SendDataTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseTcpOutSocket(const FWNetMatch & netMatch);

	void CloseTcpOutSocketBatch(const FWNetMatch * netMatches, unsigned int count);

protected:
	/* 
	�ɸ���ʵ��returnһ�������ַ�������ӡLOGʱ�������ֲ�ͬ��FWTcpOutManageBase���� 
	*/
	virtual const char * _getTitle() const;

	/*
	��������������Ѵ����ߣ���ʱ���ӳɹ���ᱻ�Զ�closesocket�������ô˺��������Ҳ����ٵ���_onTcpOutConnectResult
	*/
	virtual void _onTcpOutOverloaded(FW_ID custom) = 0;

	/*
	���ӽ��
	succeedΪtrueʱnetMatch������������
	*/
	virtual void _onTcpOutConnectResult(bool succeed, const FWNetMatch & netMatch, FW_ID custom) = 0;
	
	/*
	������֤
	return = 0��buf������ݻ��������һ��������Ϣ���������ȴ��´�
	return > 0��buf��������ܹ����һ������������Ϣ�����������ɶ��������Ϣ�����ͱ��뷵���������Ĵ�С֮�ͣ����Ժ󽫻����_onTcpOutRecvCompleted
	return < 0���Ͽ�������
	*/
	virtual unsigned int _onTcpOutRecvTest(const char * buf, unsigned int size, FW_ID custom) = 0;

	/* 
	���������
	newBuf�����ݻ�������ʹ����ɺ�������FW_FREE�ͷ�
	size��newBuf�е���Ч���ݴ�С��Ҳ����ǰһ�ε���_onTcpOutRecvTest�����صĴ���0��ֵ
	*/
	virtual void _onTcpOutRecvCompleted(const FWNetMatch & netMatch, char * newBuf, unsigned int size, FW_ID custom) = 0;
	
	/* 
	�����ѶϿ�
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