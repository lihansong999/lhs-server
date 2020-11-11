#ifndef __FRAMEWORK_WSSVCMANAGEBASE_H__
#define __FRAMEWORK_WSSVCMANAGEBASE_H__

#include "FWWsSvcTypeDef.h"
#include "../../../Common/FWPTW32Lock.h"

FW_NS_BEGIN


/*
WebSocket����������
�ɽ������ӣ��Լ��������ӵ��׽���
�̳к�ʹ��
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
		WSAF_V4ONLY = 0,	//ֻ����IPv4
		WSAF_V6ONLY,		//ֻ����IPv6
		/*
		ͬʱ����IPv4��IPv6
		�ο� https://tools.ietf.org/html/rfc2553#section-3.7 �ڽ��ܵ�ʹ��IPv4Э�������ʱ��
		IPv4��ַ��ӳ�䵽IPv6������"150.158.172.137"ӳ��Ϊ"::ffff:150.158.172.137"
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
	port�������˿ں�
	maxConnectedCount��������������
	threadCountRS��poll�߳�������0ΪCPU������*2/3�����ٻ���һ���̣߳���������0������ֵΪ׼
	rSinglePackageMax: ���յ���message����󳤶ȣ�����������ȵĻᱻ��Ϊ�Ƿ����ӣ������Ͽ�
	dataProtocol��Э����������
	addrFamily��ѡ��֧�ֵĵ�ַ�壬Ĭ��ֻ֧��IPv4
	*/
	bool Start(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, WSAddrFamily wsAddrFamily = WSAF_V4ONLY);

	/*
	port�������˿ں�
	maxConnectedCount��������������
	threadCountRS��poll�߳�������0ΪCPU������*2/3�����ٻ���һ���̣߳���������0������ֵΪ׼
	certFilePath����Կ�ļ�·��
	keyFilePath��˽Կ�ļ�·��
	keyFilePassword��˽Կ����
	rSinglePackageMax: ���յ���message����󳤶ȣ�����������ȵĻᱻ��Ϊ�Ƿ����ӣ������Ͽ�
	dataProtocol��Э����������
	addrFamily��ѡ��֧�ֵĵ�ַ�壬Ĭ��ֻ֧��IPv4
	*/
	bool StartTLS(unsigned short port, unsigned int maxConnectedCount, unsigned int threadCountRS, const char * certFilePath, const char * keyFilePath, const char * keyFilePassword = "", int rSinglePackageMax = INT_MAX, WSDataProtocol dataProtocol = WSDP_TEXT, WSAddrFamily wsAddrFamily = WSAF_V4ONLY);

	void Stop();

	/*
	֧�ַ���0��С��message
	*/
	bool SendDataWsSvcSocket(const FWNetMatch & netMatch, const char * pData, int size);

	/*
	֧�ַ���0��С��message
	*/
	void SendDataWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count, const char * pData, int size);

	void CloseWsSvcSocket(const FWNetMatch & netMatch);

	void CloseWsSvcSocketBatch(const FWNetMatch * netMatches, unsigned int count);

	bool GetWsSvcSocketInfo(const FWNetMatch & netMatch, FWSvcSocketInfo * out_svcSocketInfo);

	int GetConnectedCount();

protected:
	/*
	�ɸ���ʵ��returnһ�������ַ�������ӡLOGʱ�������ֲ�ͬ��FWWsSvcManageBase����
	*/
	virtual const char * _getTitle() const;

	/*
	�Ƿ�ܾ��˴�����Э�飬Ĭ��ʼ�շ���false
	true���ܾ�
	false�����ܾ�
	*/
	virtual bool _onWsSvcReject(const char * ip46, unsigned short port);

	/*
	����Э�������
	*/
	virtual void _onWsSvcEstablishe(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo) = 0;

	/*
	���������
	newBuf��message���ݻ�������ʹ����ɺ�������FW_FREE�ͷţ�����sizeΪ0ʱ��ֻҪnewBuf!=NULL�ͱ������FW_FREE�ͷţ�
	size��newBuf�е����ݴ�С��֧��0��С��message��
	*/
	virtual void _onWsSvcMessage(const FWNetMatch & netMatch, const FWSvcSocketInfo & svcSocketInfo, char * newBuf, unsigned int size) = 0;

	/*
	�����ѶϿ�
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