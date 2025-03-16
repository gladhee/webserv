//
// Created by HeeSung Choi on 3/3/25.
//

#ifndef WEBSERV_SERVERCONNECTION_HPP
#define WEBSERV_SERVERCONNECTION_HPP

#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

#include "ClientConnection.hpp"
#include "Connection.hpp"
#include "EventLoop.hpp"
#include "Router.hpp"

class ServerConnection : public Connection {
private:
	EventLoop* eventLoop;
	Router router;
	int _fd;

public:
	ServerConnection(EventLoop* eventLoop, Router router);
	~ServerConnection();

	virtual void onRead();
	virtual void onWrite();
	virtual void onError();
	virtual void onClose();

private:
	ServerConnection();
	ServerConnection(ServerConnection const&);
	ServerConnection& operator=(ServerConnection const&);
};

#endif  // WEBSERV_SERVERCONNECTION_HPP
