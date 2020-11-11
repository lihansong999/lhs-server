#ifndef __FRAMEWORK_TCPLISTENSOCKET_H__
#define __FRAMEWORK_TCPLISTENSOCKET_H__

#include "FWTcpSvcTypeDef.h"
#include "../../../Common/FWLock.h"

FW_NS_BEGIN


/*
TCP监听套接字
*/
class FW_DLL FWTcpListenSocket
{
public:
	enum AddrFamily
	{
		AF_V4ONLY = 0,	//只监听IPv4
		AF_V6ONLY,		//只监听IPv6
		/*
		同时监听IPv4和IPv6
		参考 https://tools.ietf.org/html/rfc2553#section-3.7 在接受到使用IPv4协议的连接时，
		Accept参数sockaddr_storage会以sockaddr_in6结构得到，IPv4地址被映射到IPv6，
		例如"150.158.172.137"映射为"::ffff:150.158.172.137"
		*/
		AF_V46MAPPED,
		/*
		同时监听IPv4和IPv6
		内部使用两个套接字分别接受IPv4和IPv6
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