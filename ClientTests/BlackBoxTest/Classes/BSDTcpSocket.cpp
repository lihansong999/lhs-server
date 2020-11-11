#include "stdafx.h"
#include "BSDTcpSocket.h"

#if defined(BSD_WIN32)
#pragma comment (lib,"ws2_32.lib")
#endif

#if defined(BSD_WIN32)
#define FIND_MAX_SOCKET_PLUS_ONE_FOR_SELECT(s, c)	0
#else
#define FIND_MAX_SOCKET_PLUS_ONE_FOR_SELECT(s, c)	(BSDTcpSocket::find_max_socket(s, c) + 1)	//Berkeley sockets
#endif


BSDTcpSocket::BSDTcpSocket()
	:_socket(INVALID_SOCKET)
	, _protoSndbufSize(0)
{
#if defined(BSD_WIN32)
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

BSDTcpSocket::BSDTcpSocket(BSDTcpSocket && other)
{
#if defined(BSD_WIN32)
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

	//copy
	_socket = other._socket;
	_protoSndbufSize = other._protoSndbufSize;

	//clear
	other._socket = INVALID_SOCKET;
	other._protoSndbufSize = 0;
}

BSDTcpSocket& BSDTcpSocket::operator=(BSDTcpSocket && other)
{
	this->close();

	//copy
	_socket = other._socket;
	_protoSndbufSize = other._protoSndbufSize;

	//clear
	other._socket = INVALID_SOCKET;
	other._protoSndbufSize = 0;

	return *this;
}

BSDTcpSocket::~BSDTcpSocket()
{
	this->close();
#if defined(BSD_WIN32)
	WSACleanup();
#endif
}

BSDTcpSocket::BSDTcpSocket(SOCKET s)
	:_socket(s)
	, _protoSndbufSize(0)
{
#if defined(BSD_WIN32)
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
	if (_socket != INVALID_SOCKET)
	{
		this->_unBlock();
		this->_resetProtoBufSize();
#if defined(BSD_IOS)
		int set = 1;
		::setsockopt(_socket, SOL_SOCKET, SO_NOSIGPIPE, (void*)&set, sizeof(int));
#endif
	}
}

BSDTcpSocket::BSDTcpSocket(BSDTcpSocket & other)
{
	//deprecated
	assert(false);
}

BSDTcpSocket& BSDTcpSocket::operator=(BSDTcpSocket & other)
{
	//deprecated
	assert(false);
	return *this;
}

bool BSDTcpSocket::connect(const char * addr, unsigned short port, int time_out_seconds /*= 10*/)
{
	this->close();
	char post_str[32] = {};
#if defined(BSD_WIN32)
	sprintf_s(post_str, sizeof(post_str), "%d", (int)port);
#else
	sprintf(post_str, "%d", (int)port);
#endif
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	struct addrinfo * res;
	if (0 != getaddrinfo(addr, post_str, &hints, &res))
		return false;
	bool ret = false;
	for (struct addrinfo * tmp = res; tmp != NULL; tmp = tmp->ai_next)
	{
		if (tmp->ai_family == AF_INET || tmp->ai_family == AF_INET6)
		{
			if (tmp->ai_socktype != SOCK_STREAM)
				continue;
			if (tmp->ai_protocol != 0 && tmp->ai_protocol != IPPROTO_IP && tmp->ai_protocol != IPPROTO_TCP)
				continue;
			_socket = ::socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
			if (_socket == INVALID_SOCKET)
				continue;
#if defined(BSD_IOS)
			int set = 1;
			::setsockopt(_socket, SOL_SOCKET, SO_NOSIGPIPE, (void*)&set, sizeof(int));
#endif
			this->_unBlock();
			if (::connect(_socket, tmp->ai_addr, (int)tmp->ai_addrlen) < 0)
			{
				int err = this->getError();
				if (err == BSD_EINTR || err == BSD_EWOULDBLOCK || err == BSD_EINPROGRESS)
				{
					if (this->_selectConnect(time_out_seconds, 0))
					{
						ret = true;
						break;
					}
					else
					{
						this->close();
					}
				}
				else
				{
					this->close();
				}
			}
			else
			{
				ret = true;
				break;
			}
		}
	}
	freeaddrinfo(res);
	if (ret)
		this->_resetProtoBufSize();
	return ret;
}

bool BSDTcpSocket::bindListen(unsigned short port, bool ipv6 /*= false*/)
{
	this->close();
	_socket = ::socket(ipv6 ? AF_INET6 : AF_INET, SOCK_STREAM, 0);
	if (_socket == INVALID_SOCKET)
		return false;
	int r = 0;
	if (ipv6)
	{
		int value = 1; //OpenBSD only 1
		setsockopt(_socket, IPPROTO_IPV6, IPV6_V6ONLY, (char*)&value, sizeof(value));
		if (r < 0)
		{
			//IPV6_V6ONLY open failed
			int err = this->getError();
			this->close();
			this->_setError(err);
			return false;
		}
		struct sockaddr_in6 addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin6_family = AF_INET6;
		addr.sin6_addr = in6addr_any;
		addr.sin6_port = ::htons(port);
		r = ::bind(_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in6));
	}
	else 
	{
		struct sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = INADDR_ANY; //::inet_addr("0.0.0.0");
		addr.sin_port = ::htons(port);
		r = ::bind(_socket, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
	}
	if (r < 0)
	{
		int err = this->getError();
		this->close();
		this->_setError(err);
		return false;
	}
	r = ::listen(_socket, 32);
	if (r < 0)
	{
		int err = this->getError();
		this->close();
		this->_setError(err);
		return false;
	}
	this->_unBlock();
#if defined(BSD_IOS)
	int set = 1;
	::setsockopt(_socket, SOL_SOCKET, SO_NOSIGPIPE, (void*)&set, sizeof(int));
#endif
	return true;
}

bool BSDTcpSocket::send_full(const char * buffer, const int length)
{
	if (_socket == INVALID_SOCKET)
		return false;

	unsigned int flags = 0;
#if defined(BSD_LINUX)
	flags = MSG_NOSIGNAL;
#endif

	int offset = 0;
	do 
	{
		int r = this->send(buffer + offset, length - offset);
		if (r > 0)
		{
			offset += r;
			if (offset != length)
			{
#if defined(BSD_WIN32)
				Sleep(1);
#else
				usleep(1000);
#endif
			}
		}
		else if (r == 0)
		{
			break;
		}
		else if (r < 0)
		{
#if defined(BSD_WIN32)
			Sleep(5);
#else
			usleep(5000);
#endif
		}
	} while (offset < length);

	return offset == length;
}

int BSDTcpSocket::send(const char * buffer, const int length)
{
	if (_socket == INVALID_SOCKET)
		return 0;
	
	unsigned int flags = 0;
#if defined(BSD_LINUX)
	flags = MSG_NOSIGNAL;
#endif

	int r = ::send(_socket, buffer, ((length > _protoSndbufSize) ? (_protoSndbufSize) : (length)), flags);
	if (r < 0)
	{
		int err = this->getError();
		if (err == BSD_EINTR || err == BSD_EAGAIN || err == BSD_EWOULDBLOCK)
		{
			//go on
			return -1;
		}
		else
		{
			this->close();
			this->_setError(err);
			return 0;
		}
	}
	else if (r == 0)
	{
		this->close();
		return 0;
	}
	else
	{
		return r;
	}
}

int BSDTcpSocket::recv(char * buffer, const int length)
{
	if (_socket == INVALID_SOCKET)
		return 0;

	unsigned int flags = 0;
#if defined(BSD_LINUX)
	flags = MSG_NOSIGNAL;
#endif

	int r = ::recv(_socket, buffer, length, flags);
	if (r < 0)
	{
		int err = this->getError();
		if (err == BSD_EINTR || err == BSD_EAGAIN || err == BSD_EWOULDBLOCK)
		{
			//go on
			return -1;
		}
		else
		{
			this->close();
			this->_setError(err);
			return 0;
		}
	}
	else if (r == 0)
	{
		this->close();
		return 0;
	}
	else
	{
		return r;
	}
}

BSDTcpSocket BSDTcpSocket::accept(struct sockaddr_storage * out_addr /*= nullptr*/)
{
	int addrLen = sizeof(struct sockaddr_storage);
	SOCKET s = INVALID_SOCKET;
	if (out_addr)
	{
		s = ::accept(_socket, (struct sockaddr*)out_addr, &addrLen);
	}
	else
	{
		struct sockaddr_storage clientAddr;
		memset(&clientAddr, 0, sizeof(clientAddr));
		s = ::accept(_socket, (struct sockaddr*)&clientAddr, &addrLen);
	}
	if (s == INVALID_SOCKET)
	{
		int err = this->getError();
		if (err != BSD_EINTR && err != BSD_EAGAIN && err != BSD_EWOULDBLOCK)
		{
			this->close();
			this->_setError(err);
		}
	}
	return BSDTcpSocket(s);
}

bool BSDTcpSocket::isReadReady(int time_out_seconds, int time_out_microseconds)
{
	if (_socket == INVALID_SOCKET)
		return false;
	fd_set rfd;
	struct timeval timeout = { 0, 0 };
	timeout.tv_sec = time_out_seconds;
	timeout.tv_usec = time_out_microseconds;
	FD_ZERO(&rfd);
	FD_SET(_socket, &rfd);
#if defined(BSD_LINUX) || defined(BSD_IOS)
	/*
	在linux中宏FD_SETSIZE所代表的是fd_set结构中能容纳的文件描述符的最大值减一。
	*/
	assert(_socket < FD_SETSIZE);
#elif defined(BSD_WIN32)
	/*
	在windows中宏FD_SETSIZE所代表的是fd_set结构中最多能容纳多少个文件描述符。
	*/
	assert(1 <= FD_SETSIZE);
#endif
	return ::select(FIND_MAX_SOCKET_PLUS_ONE_FOR_SELECT(&_socket, 1), &rfd, nullptr, nullptr, &timeout) > 0 && FD_ISSET(_socket, &rfd);
}

bool BSDTcpSocket::isWriteReady(int time_out_seconds, int time_out_microseconds)
{
	if (_socket == INVALID_SOCKET)
		return false;
	fd_set wfd;
	struct timeval timeout = { 0, 0 };
	timeout.tv_sec = time_out_seconds;
	timeout.tv_usec = time_out_microseconds;
	FD_ZERO(&wfd);
	FD_SET(_socket, &wfd);
#if defined(BSD_LINUX) || defined(BSD_IOS)
	/*
	在linux中宏FD_SETSIZE所代表的是fd_set结构中能容纳的文件描述符的最大值减一。
	*/
	assert(_socket < FD_SETSIZE);
#elif defined(BSD_WIN32)
	/*
	在windows中宏FD_SETSIZE所代表的是fd_set结构中最多能容纳多少个文件描述符。
	*/
	assert(1 <= FD_SETSIZE);
#endif
	return ::select(FIND_MAX_SOCKET_PLUS_ONE_FOR_SELECT(&_socket, 1), nullptr, &wfd, nullptr, &timeout) > 0 && FD_ISSET(_socket, &wfd);
}

int BSDTcpSocket::getError()
{
#if defined(BSD_WIN32)
	return (WSAGetLastError());
#else
	return (errno);
#endif
}

void BSDTcpSocket::close()
{
	if (_socket != INVALID_SOCKET)
	{
#if defined(BSD_WIN32)
		::shutdown(_socket, SD_BOTH);
		::closesocket(_socket);
#else
		::shutdown(_socket, SHUT_RDWR);
		::close(_socket);
#endif
		_socket = INVALID_SOCKET;
		_protoSndbufSize = 0;
	}
}

bool BSDTcpSocket::isInvalid()
{
	return _socket == INVALID_SOCKET;
}

SOCKET BSDTcpSocket::getSocket()
{
	return _socket;
}

SOCKET BSDTcpSocket::find_max_socket(SOCKET * arr, int count)
{
	if (count > 0)
	{
		SOCKET max = arr[0];
		for (int i = 1; i < count; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}
	return INVALID_SOCKET;
}

void BSDTcpSocket::_block()
{
	if (_socket != INVALID_SOCKET)
	{
#if defined(BSD_WIN32)
		u_long ul = 0;
		::ioctlsocket(_socket, FIONBIO, &ul);
#else
		int flags = ::fcntl(_socket, F_GETFL);
		flags &= (~O_NONBLOCK);
		::fcntl(_socket, F_SETFL, O_NONBLOCK);
#endif
	}
}

void BSDTcpSocket::_unBlock()
{
	if (_socket != INVALID_SOCKET)
	{
#if defined(BSD_WIN32)
		u_long ul = 1;
		::ioctlsocket(_socket, FIONBIO, &ul);
#else
		int flags = ::fcntl(_socket, F_GETFL);
		flags |= O_NONBLOCK;
		::fcntl(_socket, F_SETFL, O_NONBLOCK);
#endif
	}
}

bool BSDTcpSocket::_selectConnect(int time_out_seconds, int time_out_microseconds)
{
	bool ret = false;
	fd_set rfd;
	fd_set wfd;
	fd_set efd;
	struct timeval timeout = { 0, 0 };
	timeout.tv_sec = time_out_seconds;
	timeout.tv_usec = time_out_microseconds;
	FD_ZERO(&rfd);
	FD_ZERO(&wfd);
	FD_ZERO(&efd);
	FD_SET(_socket, &rfd);
	FD_SET(_socket, &wfd);
	FD_SET(_socket, &efd);
#if defined(BSD_LINUX) || defined(BSD_IOS)
	/*
	在linux中宏FD_SETSIZE所代表的是fd_set结构中能容纳的文件描述符的最大值减一。
	*/
	assert(_socket < FD_SETSIZE);
#elif defined(BSD_WIN32)
	/*
	在windows中宏FD_SETSIZE所代表的是fd_set结构中最多能容纳多少个文件描述符。
	*/
	assert(1 <= FD_SETSIZE);
#endif
	if (::select(FIND_MAX_SOCKET_PLUS_ONE_FOR_SELECT(&_socket, 1), &rfd, &wfd, &efd, &timeout) > 0)
	{
		bool except = true;
		if (FD_ISSET(_socket, &efd))
		{
			//Maybe it's out-of-band or error.
			//Out-of-band data will only be reported in this way if the option SO_OOBINLINE is FALSE.(SO_OOBINLINE default FALSE)
			//If a socket is processing a connect call (nonblocking), failure of the connect attempt is indicated in exceptfds (application must then call getsockopt
			//SO_ERROR to determine the error value to describe why the failure occurred). This document does not define which other errors will be included.
			volatile int err = 0;
			socklen_t l = sizeof(err);
			except = ::getsockopt(_socket, SOL_SOCKET, SO_ERROR, (char*)&err, &l) == 0 && err == 0;
		}
		if (except)
		{
			if (FD_ISSET(_socket, &wfd))
			{
				if (FD_ISSET(_socket, &rfd))
				{
					volatile int err = 0;
					socklen_t l = sizeof(err);
					ret = ::getsockopt(_socket, SOL_SOCKET, SO_ERROR, (char*)&err, &l) == 0 && err == 0;
				}
				else
				{
					ret = true;
				}
			}
		}
	}
	return ret;
}

void BSDTcpSocket::_resetProtoBufSize()
{
	_protoSndbufSize = 0;
	if (_socket != INVALID_SOCKET)
	{
		socklen_t optlen = sizeof(int);
		int r = ::getsockopt(_socket, SOL_SOCKET, SO_SNDBUF, (char*)&_protoSndbufSize, &optlen);
		if (r < 0 || _protoSndbufSize <= 0)
		{
			_protoSndbufSize = 1024;
			::setsockopt(_socket, SOL_SOCKET, SO_SNDBUF, (char*)&_protoSndbufSize, sizeof(int));
		}
		optlen = sizeof(int);
		int protoRcvbufSize = 0;
		r = ::getsockopt(_socket, SOL_SOCKET, SO_RCVBUF, (char*)&protoRcvbufSize, &optlen);
		if (r < 0 || protoRcvbufSize <= 0)
		{
			protoRcvbufSize = 1024;
			::setsockopt(_socket, SOL_SOCKET, SO_RCVBUF, (char*)&protoRcvbufSize, sizeof(int));
		}
	}
}

void BSDTcpSocket::_setError(int e)
{
#if defined(BSD_WIN32)
	WSASetLastError(e);
#else
	(errno) = e;
#endif
}