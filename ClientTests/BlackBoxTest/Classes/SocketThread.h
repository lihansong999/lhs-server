#pragma once

#include "BSDTcpSocket.h"
#include "TypeDefine.h"

class SocketThread;
class SocketThreadDelegate
{
public:
	virtual ~SocketThreadDelegate() {};
public:
	virtual void onConnectResult(SocketThread * socketThread, bool s) {};
	virtual void onDisconnected(SocketThread * socketThread) {};
	virtual void onMessage(SocketThread * socketThread, Message::MsgPackageRecv * pack) = 0;
};

class SocketThread
{
	enum EVENTTYPE {
		ConnectSucceed = 0,
		ConnectFailed,
		Disconnected,
	};
public:
	SocketThread(const char * name);
	~SocketThread();
	
	void ConnectServer(const std::string & host, int port);

	void Disconnect();

	void SendData(const char * data, int size);

	void AddListener(SocketThreadDelegate * listener);

	void RemoveListener(SocketThreadDelegate * listener);

	void Update();

	const char * GetName();

private:
	void _threadSocket(std::string host, int port);
	void _clearMsgQueueAndCache();

private:
	const std::string						_name;
	BSDTcpSocket							_socket;
	bool									_threadSocketRunning;
	std::set<SocketThreadDelegate*>			_listeners;
	std::mutex								_listenersMutex;
	std::vector<char>						_msgRecvCache;
	std::list<Message::MsgPackageRecv*>		_msgQueue;
	std::mutex								_msgQueueMutex;
	std::list<EVENTTYPE>					_eventQueue;
	std::mutex								_eventQueueMutex;
};