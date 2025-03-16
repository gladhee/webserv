//
// Created by HeeSung Choi on 3/3/25.
//

#ifndef WEBSERV_CLIENTCONNECTION_HPP
#define WEBSERV_CLIENTCONNECTION_HPP

#include <fcntl.h>
#include <unistd.h>

#include <string>

#include "Connection.hpp"
#include "EventLoop.hpp"

class ClientConnection : public Connection {
private:
	int _clientFd;
	EventLoop* eventLoop;
	std::string _readBuffer;
	std::string _writeBuffer;

public:
	ClientConnection(int fd, EventLoop* ev);
	~ClientConnection();

	virtual void onRead();
	virtual void onWrite();
	virtual void onError();
	virtual void onClose();

private:
	ClientConnection();
	ClientConnection(ClientConnection const&);
	ClientConnection& operator=(ClientConnection const&);
};

#endif  // WEBSERV_CLIENTCONNECTION_HPP
