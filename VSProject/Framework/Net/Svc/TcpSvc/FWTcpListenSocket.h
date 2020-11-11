#ifndef __FRAMEWORK_TCPLISTENSOCKET_H__
#define __FRAMEWORK_TCPLISTENSOCKET_H__

#include "FWTcpSvcTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP�����׽���
*/
class FW_DLL FWTcpListenSocket
{
public:
	enum AddrFamily
	{
		AF_V4ONLY = 0,	//ֻ����IPv4
		AF_V6ONLY,		//ֻ����IPv6
		/*
		ͬʱ����IPv4��IPv6
		�ο� https://tools.ietf.org/html/rfc2553#section-3.7 �ڽ��ܵ�ʹ��IPv4Э�������ʱ��
		Accept����sockaddr_storage����sockaddr_in6�ṹ�õ���IPv4��ַ��ӳ�䵽IPv6��
		����"150.158.172.137"ӳ��Ϊ"::ffff:150.158.172.137"
		*/
		AF_V46MAPPED,
		/*
		ͬʱ����IPv4��IPv6
		�ڲ�ʹ�������׽��ֱַ����IPv4��IPv6
		*/
		AF_V46DUAL,
	};
public:
	FWTcpListenSocket();
	FWTcpListenSocket(const FWTcpListenSocket & other) = delete;
	FWTcpListenSocket& operator=(const FWTcpListenSocket & other) = delete;
	FWTcpListenSocket(FWTcpListenSocket && other);
	FWTcpListenSocket& operator=(FWTcpListenSocket && other);
	virtual ~FWTcpListenSocket();

	bool InitSocket(unsigned short port, AddrFamily addrFamily = AF_V4ONLY);

	SOCKET Accept(struct sockaddr_storage * out_addr);

	void CloseSocket();

	AddrFamily GetAddrFamily() const;

private:
	SOCKET		_socket;
	SOCKET		_socket6;
	AddrFamily	_addrFamily;
};


FW_NS_END


#endif //!__FRAMEWORK_TCPLISTENSOCKET_H__