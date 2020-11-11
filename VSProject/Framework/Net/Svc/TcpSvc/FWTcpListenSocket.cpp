#include "FWTcpListenSocket.h"
#include "../../../Common/FWOutPut.h"

FW_NS_BEGIN


FWTcpListenSocket::FWTcpListenSocket()
	:_socket(INVALID_SOCKET)
	, _socket6(INVALID_SOCKET)
	, _addrFamily(AF_V4ONLY)
{

}

FWTcpListenSocket::FWTcpListenSocket(FWTcpListenSocket && other)
{
	//copy
	_socket = other._socket;
	_socket6 = other._socket6;
	_addrFamily = other._addrFamily;

	//clear
	other._socket = INVALID_SOCKET;
	other._socket6 = INVALID_SOCKET;
	other._addrFamily = AF_V4ONLY;
}

FWTcpListenSocket& FWTcpListenSocket::operator=(FWTcpListenSocket && other)
{
	this->CloseSocket();

	//copy
	_socket = other._socket;
	_socket6 = other._socket6;
	_addrFamily = other._addrFamily;

	//clear
	other._socket = INVALID_SOCKET;
	other._socket6 = INVALID_SOCKET;
	other._addrFamily = AF_V4ONLY;

	return *this;
}

FWTcpListenSocket::~FWTcpListenSocket()
{
	this->CloseSocket();
}

bool FWTcpListenSocket::InitSocket(unsigned short port, AddrFamily addrFamily /*= AF_V4ONLY*/)
{
	if (_socket != INVALID_SOCKET || _socket6 != INVALID_SOCKET)
	{
		FW_LOG_ERROR("%s", "_socket != INVALID_SOCKET or _socket6 != INVALID_SOCKET");
		return false;
	}

	_addrFamily = addrFamily;

	if (_addrFamily == AF_V4ONLY)
	{
		if ((_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		{
			FW_LOG_ERROR("%s%d", "WSASocket 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}
	else if (_addrFamily == AF_V6ONLY || _addrFamily == AF_V46DUAL)
	{
		if ((_socket6 = WSASocket(AF_INET6, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		{
			FW_LOG_ERROR("%s%d", "WSASocket 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
		if (_addrFamily == AF_V46DUAL)
		{
			if ((_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
			{
				FW_LOG_ERROR("%s%d", "WSASocket 失败，错误码：", (int)WSAGetLastError());
				return false;
			}
		}
	}
	else if (_addrFamily == AF_V46MAPPED)
	{
		if ((_socket = WSASocket(AF_INET6, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
		{
			FW_LOG_ERROR("%s%d", "WSASocket 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}
	else
	{
		FW_LOG_ERROR("%s%d", "不支持 _addrFamily = ", (int)_addrFamily);
		return false;
	}

	int r = 0;

	//LPFN_ACCEPTEX					lpfnAcceptEx;
	//LPFN_GETACCEPTEXSOCKADDRS		lpfnGetAcceptExSockAddrs;
	//DWORD rBytes = 0;
	//GUID guidAcceptEx = WSAID_ACCEPTEX;
	//r = WSAIoctl(_socket, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidAcceptEx, sizeof(guidAcceptEx), &lpfnAcceptEx, sizeof(lpfnAcceptEx), &rBytes, NULL, NULL);
	//if (r != 0)
	//{
	//	FW_LOG_ERROR("%s%d", "装载扩展函数AcceptEx失败，错误码：", (int)WSAGetLastError());
	//}
	//r = 0;
	//rBytes = 0;
	//GUID guidGetAcceptExSockaddrs = WSAID_GETACCEPTEXSOCKADDRS;
	//r = WSAIoctl(_socket, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidGetAcceptExSockaddrs, sizeof(guidGetAcceptExSockaddrs), &lpfnGetAcceptExSockAddrs, sizeof(lpfnGetAcceptExSockAddrs), &rBytes, NULL, NULL);
	//if (r != 0)
	//{
	//	FW_LOG_ERROR("%s%d", "装载扩展函数GetAcceptExSockaddrs失败，错误码：", (int)WSAGetLastError());
	//}
	
	if (_addrFamily == AF_V4ONLY)
	{
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY; //::inet_addr("0.0.0.0");
		addr.sin_port = ::htons(port);
		if ((r = ::bind(_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))) == SOCKET_ERROR)
		{
			FW_LOG_ERROR("%s%d", "bind 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}
	else if (_addrFamily == AF_V6ONLY || _addrFamily == AF_V46DUAL)
	{
		int value = 1;
		r = setsockopt(_socket6, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&value, sizeof(value));
		if (r == SOCKET_ERROR)
		{
			FW_LOG_WRNING("%s%d", "打开 IPV6_V6ONLY 失败，将继续接受使用IPv4协议的客户端连接，错误码：", (int)WSAGetLastError());
		}
		struct sockaddr_in6 addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin6_family = AF_INET6;
		addr.sin6_addr = in6addr_any;
		addr.sin6_port = ::htons(port);
		if ((r = ::bind(_socket6, (struct sockaddr*)&addr, sizeof(struct sockaddr_in6))) == SOCKET_ERROR)
		{
			FW_LOG_ERROR("%s%d", "bind 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
		if (_addrFamily == AF_V46DUAL)
		{
			struct sockaddr_in addr;
			memset(&addr, 0, sizeof(addr));
			addr.sin_family = AF_INET;
			addr.sin_addr.s_addr = INADDR_ANY; //::inet_addr("0.0.0.0");
			addr.sin_port = ::htons(port);
			if ((r = ::bind(_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in))) == SOCKET_ERROR)
			{
				FW_LOG_ERROR("%s%d", "bind 失败，错误码：", (int)WSAGetLastError());
				return false;
			}
		}
	}
	else if (_addrFamily == AF_V46MAPPED)
	{
		int value = 0;
		r = setsockopt(_socket, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&value, sizeof(value));
		if (r == SOCKET_ERROR)
		{
			FW_LOG_WRNING("%s%d", "关闭 IPV6_V6ONLY 失败，将无法接受使用IPv4协议的客户端连接，错误码：", (int)WSAGetLastError());
		}
		struct sockaddr_in6 addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin6_family = AF_INET6;
		addr.sin6_addr = in6addr_any;
		addr.sin6_port = ::htons(port);
		if ((r = ::bind(_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in6))) == SOCKET_ERROR)
		{
			FW_LOG_ERROR("%s%d", "bind 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}
	else
	{
		FW_LOG_ERROR("%s%d", "不支持 _addrFamily = ", (int)_addrFamily);
		return false;
	}

	if (_socket != INVALID_SOCKET)
	{
		r = ::listen(_socket, SOMAXCONN);
		if (r == SOCKET_ERROR)
		{
			FW_LOG_ERROR("%s%d", "listen 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}
	if (_socket6 != INVALID_SOCKET)
	{
		r = ::listen(_socket6, SOMAXCONN);
		if (r == SOCKET_ERROR)
		{
			FW_LOG_ERROR("%s%d", "listen 失败，错误码：", (int)WSAGetLastError());
			return false;
		}
	}

	return true;
}

SOCKET FWTcpListenSocket::Accept(struct sockaddr_storage * out_addr)
{
	int addrLen = sizeof(struct sockaddr_storage);
	SOCKET s = INVALID_SOCKET;
	if (_addrFamily == AF_V4ONLY || _addrFamily == AF_V46MAPPED)
	{
		if (_socket != INVALID_SOCKET)
		{
			s = WSAAccept(_socket, (struct sockaddr *)out_addr, &addrLen, NULL, NULL);
		}
	}
	else if (_addrFamily == AF_V6ONLY)
	{
		if (_socket6 != INVALID_SOCKET)
		{
			s = WSAAccept(_socket6, (struct sockaddr *)out_addr, &addrLen, NULL, NULL);
		}
	}
	else if (_addrFamily == AF_V46DUAL)
	{
		do {
			if (_socket == INVALID_SOCKET || _socket6 == INVALID_SOCKET)
				return s;
			//struct timeval timeout = { 0, 0 };
			//timeout.tv_sec = 10L;
			//timeout.tv_usec = 0L;
			fd_set rfd;
			FD_ZERO(&rfd);
			FD_SET(_socket, &rfd);
			FD_SET(_socket6, &rfd);
			int r = ::select(0/*((_socket > _socket6) ? (_socket + 1) : (_socket6 + 1))*/, &rfd, NULL, NULL, NULL/*&timeout*/);
			if (r == 0)
			{
				continue;
			}
			if (r == SOCKET_ERROR)
			{
				int e = WSAGetLastError();
				if (e != WSAEINTR && e != WSAENOTSOCK && e != WSAEINVAL)
				{
					FW_LOG_ERROR("%s%d", "::select 出现未预见错误，错误码：", e);
				}
				return s;
			}
			if (FD_ISSET(_socket, &rfd))
			{
				s = WSAAccept(_socket, (struct sockaddr *)out_addr, &addrLen, NULL, NULL);
				break;
			}
			else if (FD_ISSET(_socket6, &rfd))
			{
				s = WSAAccept(_socket6, (struct sockaddr *)out_addr, &addrLen, NULL, NULL);
				break;
			}
			else
			{
				// already call CloseSocket()
				return s;
			}
		} while (true);
	}
	if (s == INVALID_SOCKET)
	{
		int e = WSAGetLastError();
		if (e != WSAEINTR && e != WSAENOTSOCK && e != WSAECONNRESET)
		{
			FW_LOG_ERROR("%s%d", "WSAAccept 出现未预见错误，错误码：", e);
		}
	}
	return s;
}

void FWTcpListenSocket::CloseSocket()
{
	_addrFamily = AF_V4ONLY;
	SOCKET temp = _socket;
	SOCKET temp6 = _socket6;
	_socket = INVALID_SOCKET;
	_socket6 = INVALID_SOCKET;
	if (temp != INVALID_SOCKET)
	{
		::closesocket(temp);
	}
	if (temp6 != INVALID_SOCKET)
	{
		::closesocket(temp6);
	}
}

FWTcpListenSocket::AddrFamily FWTcpListenSocket::GetAddrFamily() const
{
	return _addrFamily;
}


FW_NS_END