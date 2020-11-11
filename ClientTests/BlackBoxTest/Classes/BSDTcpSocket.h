#ifndef __BSDTCPSOCKET_H__
#define __BSDTCPSOCKET_H__

/*************
BSD TCP Socket
non-blocking mode
**************/

/*
platform define
#define BSD_WIN32
#define BSD_LINUX
#define BSD_IOS
*/
#define BSD_WIN32

#if defined(BSD_WIN32)
#include <WinSock2.h>
#include <WS2tcpip.h>
#else
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/time.h>
typedef unsigned int SOCKET;
#endif
#include <stdio.h>
#include <memory.h>
#include <assert.h>

#ifndef INVALID_SOCKET
#define INVALID_SOCKET	(SOCKET)~(0)
#endif

#if defined(BSD_WIN32)
#define	BSD_EWOULDBLOCK	WSAEWOULDBLOCK
#define BSD_EINPROGRESS	WSAEINPROGRESS
#define BSD_EAGAIN		WSAEWOULDBLOCK	
#define BSD_EINTR		WSAEINTR
#else
#define	BSD_EWOULDBLOCK	EWOULDBLOCK
#define BSD_EINPROGRESS	EINPROGRESS
#define BSD_EAGAIN		EAGAIN
#define BSD_EINTR		EINTR
#endif

class BSDTcpSocket
{
public:
	BSDTcpSocket();
	BSDTcpSocket(BSDTcpSocket && other);
	BSDTcpSocket& operator=(BSDTcpSocket && other);
	~BSDTcpSocket();

private:
	BSDTcpSocket(SOCKET s);							//for accept
	BSDTcpSocket(BSDTcpSocket & other);				//deprecated
	BSDTcpSocket& operator=(BSDTcpSocket & other);	//deprecated

public:
	/* 
	support ipv4 ipv6
	return true is succeed
	return false is failed and closed
	*/
	bool connect(const char * addr, unsigned short port, int time_out_seconds = 10);

	/*
	return true is succeed
	return false is failed and closed
	*/
	bool bindListen(unsigned short port, bool ipv6 = false);
	
	/*
	full copy send
	return true is succeed
	return false is closed 
	*/
	bool send_full(const char * buffer, const int length);

	/* 
	return > 0 is completed copy size
	return == 0 is closed
	return < 0 is waiting
	*/
	int send(const char * buffer, const int length);

	/*
	return > 0 is completed copy size
	return == 0 is closed
	return < 0 is waiting
	*/
	int recv(char * buffer, const int length);

	/*
	return returnValue.isInvalid() != true is succeed
	listenSocket.isInvalid() == true is closed, listenSocket.getError() can be viewed
	*/
	BSDTcpSocket accept(struct sockaddr_storage * out_addr = nullptr);

	/*
	get socket readable
	*/
	bool isReadReady(int time_out_seconds, int time_out_microseconds);

	/*
	get socket writable
	*/
	bool isWriteReady(int time_out_seconds, int time_out_microseconds);

	/*
	return socket error code
	*/
	int getError();

	/*
	close socket
	*/
	void close();

	/*
	return true if socket is INVALID_SOCKET
	*/
	bool isInvalid();

	/*
	return socket handle value
	*/
	SOCKET getSocket();

public:
	/*
	for berkeley sockets
	*/
	static SOCKET find_max_socket(SOCKET * arr, int count);

private:
	void _block();
	void _unBlock();
	bool _selectConnect(int time_out_seconds, int time_out_microseconds);
	void _resetProtoBufSize();
	void _setError(int e);

private:
	SOCKET	_socket;
	int		_protoSndbufSize;
};


#endif //__BSDTCPSOCKET_H__
