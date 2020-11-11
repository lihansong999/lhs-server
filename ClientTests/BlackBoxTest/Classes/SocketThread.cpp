#include "stdafx.h"
#include "SocketThread.h"


SocketThread::SocketThread(const char * name)
	:_threadSocketRunning(false)
	, _name(name)
{

}

SocketThread::~SocketThread()
{
	_clearMsgQueueAndCache();
}

void SocketThread::ConnectServer(const std::string & host, int port)
{
	for (int i = 0; i < 200; i++)
	{
		if (!_threadSocketRunning)
		{
			break;
		}
		else 
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}
	if (_threadSocketRunning)
	{
		_eventQueueMutex.lock();
		_eventQueue.push_back(SocketThread::ConnectFailed);
		_eventQueueMutex.unlock();
		return;
	}

	_clearMsgQueueAndCache();

	_threadSocketRunning = true;
	auto t = std::thread(std::bind(&SocketThread::_threadSocket, this, host, port));
	t.detach();
}

void SocketThread::Disconnect()
{
	if (_threadSocketRunning)
	{
		_socket.close();
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}

void SocketThread::SendData(const char * data, int size)
{
	if (_threadSocketRunning)
	{
		if (data && size > 0)
		{
			_socket.send_full(data, size);
		}
	}
}

void SocketThread::AddListener(SocketThreadDelegate * listener)
{
	_listenersMutex.lock();
	_listeners.insert(listener);
	_listenersMutex.unlock();
}

void SocketThread::RemoveListener(SocketThreadDelegate * listener)
{
	_listenersMutex.lock();
	std::set<SocketThreadDelegate*>::iterator it = _listeners.find(listener);
	if (it != _listeners.end())
	{
		_listeners.erase(it);
	}
	_listenersMutex.unlock();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void SocketThread::Update()
{
	std::set<SocketThreadDelegate*> tempListeners;
	_listenersMutex.lock();
	if (_listeners.size() > 0)
	{
		for (std::set<SocketThreadDelegate*>::iterator it = _listeners.begin(); it != _listeners.end(); it++)
		{
			tempListeners.insert(*it);
		}
	}
	_listenersMutex.unlock();

	std::list<Message::MsgPackageRecv*> tempMsgQueue;
	_msgQueueMutex.lock();
	if (_msgQueue.size() > 0)
	{
		for (std::list<Message::MsgPackageRecv*>::iterator it = _msgQueue.begin(); it != _msgQueue.end(); it++)
		{
			tempMsgQueue.push_back(*it);
		}
		_msgQueue.clear();
	}
	_msgQueueMutex.unlock();

	std::list<EVENTTYPE> tempEventQueue;
	_eventQueueMutex.lock();
	if (_eventQueue.size() > 0)
	{
		for (std::list<EVENTTYPE>::iterator it = _eventQueue.begin(); it != _eventQueue.end(); it++)
		{
			tempEventQueue.push_back(*it);
		}
		_eventQueue.clear();
	}
	_eventQueueMutex.unlock();

	for (std::list<EVENTTYPE>::iterator it = tempEventQueue.begin(); it != tempEventQueue.end(); it++)
	{
		for (std::set<SocketThreadDelegate*>::iterator it2 = tempListeners.begin(); it2 != tempListeners.end(); it2++)
		{
			switch ((*it))
			{
			case SocketThread::ConnectSucceed:
				(*it2)->onConnectResult(this, true);
				break;
			case SocketThread::ConnectFailed:
				(*it2)->onConnectResult(this, false);
				break;
			default:
				break;
			}
		}
	}
	
	for (std::list<Message::MsgPackageRecv*>::iterator it = tempMsgQueue.begin(); it != tempMsgQueue.end(); it++)
	{
		for (std::set<SocketThreadDelegate*>::iterator it2 = tempListeners.begin(); it2 != tempListeners.end(); it2++)
		{
			(*it2)->onMessage(this, (*it));
		}
		delete (*it);
	}

	for (std::list<EVENTTYPE>::iterator it = tempEventQueue.begin(); it != tempEventQueue.end(); it++)
	{
		for (std::set<SocketThreadDelegate*>::iterator it2 = tempListeners.begin(); it2 != tempListeners.end(); it2++)
		{
			switch ((*it))
			{
			case SocketThread::Disconnected:
				(*it2)->onDisconnected(this);
				break;
			default:
				break;
			}
		}
	}
}

const char * SocketThread::GetName()
{
	return _name.c_str();
}

void SocketThread::_threadSocket(std::string host, int port)
{
	if (_socket.connect(host.c_str(), port))
	{
		_eventQueueMutex.lock();
		_eventQueue.push_back(SocketThread::ConnectSucceed);
		_eventQueueMutex.unlock();
		while (true)
		{
#define RECV_BUFFER_SIZE	4096
			char buffer[RECV_BUFFER_SIZE];
			bool connected = true;
			_socket.isReadReady(10, 0);
			int length = _socket.recv(buffer, RECV_BUFFER_SIZE);
			if (length == 0)
			{
				break;
			}
			if (length > 0)
			{
				for (int i = 0; i < length; i++)
				{
					_msgRecvCache.push_back(buffer[i]);
				}
				int validCount = 0;
				int totalValidSize = Message::MsgPackageRecv::TestBufferValidity((&(_msgRecvCache[0])), (int)_msgRecvCache.size(), &validCount);
				if (totalValidSize < 0)
				{
					_socket.close();
					break;
				}
				bool err = false;
				int offset = 0;
				while (offset < totalValidSize)
				{
					int validSize = 0;
					Message::MsgPackageRecv * msgPackageRecv = new Message::MsgPackageRecv((&(_msgRecvCache[offset])), totalValidSize - offset, &validSize);
					if (validSize == 0)
					{
						err = true;
						break;
					}
					_msgQueueMutex.lock();
					_msgQueue.push_back(msgPackageRecv);
					_msgQueueMutex.unlock();
					offset += validSize;
				}
				if (err)
				{
					_socket.close();
					break;
				}
				_msgRecvCache.erase(_msgRecvCache.begin(), _msgRecvCache.begin() + totalValidSize);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		_eventQueueMutex.lock();
		_eventQueue.push_back(SocketThread::Disconnected);
		_eventQueueMutex.unlock();
	}
	else
	{
		_eventQueueMutex.lock();
		_eventQueue.push_back(SocketThread::ConnectFailed);
		_eventQueueMutex.unlock();
	}
	_threadSocketRunning = false;
}

void SocketThread::_clearMsgQueueAndCache()
{
	_msgRecvCache.clear();

	_msgQueueMutex.lock();
	for (std::list<Message::MsgPackageRecv*>::iterator it = _msgQueue.begin(); it != _msgQueue.end(); it++)
	{
		delete (*it);
	}
	_msgQueue.clear();
	_msgQueueMutex.unlock();
}
