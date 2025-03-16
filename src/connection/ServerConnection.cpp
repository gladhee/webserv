//
// Created by HeeSung Choi on 3/3/25.
//

#include "ServerConnection.hpp"

ServerConnection::ServerConnection(EventLoop* eventLoop, Router router)
		:eventLoop(eventLoop), router(router) {
}

ServerConnection::ServerConnection(ServerConnection const&) {
}

ServerConnection& ServerConnection::operator=(ServerConnection const&) {
	return *this;
}

ServerConnection::~ServerConnection() {
}

void ServerConnection::onRead() {
	while (true) {
		int clientFd = accept(_fd, NULL, NULL);

		if (clientFd < 0) {
			break;
		}

		fcntl(clientFd, F_SETFL, O_NONBLOCK);
		Connection* conn = new ClientConnection(clientFd, eventLoop);
		eventLoop->addReadEvent(clientFd, conn);
		eventLoop->addWriteEvent(clientFd, conn);

		std::cout << clientFd << " connected" << std::endl;
	}
}
