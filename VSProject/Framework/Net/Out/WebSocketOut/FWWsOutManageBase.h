#ifndef __FRAMEWORK_WSOUTMANAGEBASE_H__
#define __FRAMEWORK_WSOUTMANAGEBASE_H__

#include "FWWsOutTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN

/*
WebSocket�������ӹ������
�ɽ��������ӣ��Լ��������ӵ��׽���
�̳к�ʹ��
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
	maxConnectedCount��������������������
	rSinglePackageMax: ���յ���message����󳤶ȣ�����������ȵĻᱻ��Ϊ�Ƿ����ӣ������Ͽ�
	dataProtocol��Э����������
	disableIPv6���ر�IPv6֧�֣����Ϊfalse��Connect��host��������Ϊ���������ʮ���Ƶ�ַ���޷�����
	*/
	bool Start(unsigned int maxConnectedCount, int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, bool disableIPv6 = true);

	void Stop();

	/*
	��Start��ɺ�һ�����ô˺�������ô��֮���ĳ��ʱ���Ȼ��ص�_onWsOutConnectResult��_onWsOutOverloaded
	custom���Զ������������֮��Ļص���ԭ������
	allowCertVerify��������ǩ��֤�鲢�����������͹���ʧЧ���
	*/
	void Connect(const char * host, FW_ID custom = 0LL, bool allowCertVerify = true);

	/*
	֧�ַ���0��С��message
	*/
	bool SendDataWsOutSocket(const FWNetMatch & netMatch, const char * pData, int size);

	/*
	֧�ַ���0��С��message
	*/
	void SendDataWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseWsOutSocket(const FWNetMatch & netMatch);

	void CloseWsOutSocketBatch(const FWNetMatch * netMatches, unsigned int count);

protected:
	/*
	�ɸ���ʵ��returnһ�������ַ�������ӡLOGʱ�������ֲ�ͬ��FWWsOutManageBase����
	*/
	virtual const char * _getTitle() const;

	/*
	��������������Ѵ����ߣ���ʱ����Э��ɹ���ᱻ�Զ��Ͽ��������ô˺��������Ҳ����ٵ���_onWsOutConnectResult
	*/
	virtual void _onWsOutOverloaded(FW_ID custom) = 0;

	/*
	���ӽ��
	succeedΪtrueʱnetMatch������������
	*/
	virtual void _onWsOutConnectResult(bool succeed, const FWNetMatch & netMatch, FW_ID custom) = 0;

	/*
	���������
	newBuf��message���ݻ�������ʹ����ɺ�������FW_FREE�ͷţ�����sizeΪ0ʱ��ֻҪnewBuf!=NULL�ͱ������FW_FREE�ͷţ�
	size��newBuf�е����ݴ�С��֧��0��С��message��
	*/
	virtual void _onWsOutMessage(const FWNetMatch & netMatch, char * newBuf, unsigned int size, FW_ID custom) = 0;

	/*
	�����ѶϿ�
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