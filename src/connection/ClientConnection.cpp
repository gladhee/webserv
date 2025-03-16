//
// Created by HeeSung Choi on 3/3/25.
//

#include "ClientConnection.hpp"

ClientConnection::ClientConnection() {
}

ClientConnection::ClientConnection(int fd, EventLoop* ev)
		:_clientFd(fd), eventLoop(ev) {
	fcntl(_clientFd, F_SETFL, O_NONBLOCK);
}

ClientConnection::ClientConnection(ClientConnection const&) {
}

ClientConnection& ClientConnection::operator=(ClientConnection const&) {
	return *this;
}

ClientConnection::~ClientConnection() {
	close(_clientFd);
}

void ClientConnection::onRead() {
	char buf[1024];
	ssize_t n = ::read(_clientFd, buf, sizeof(buf));
	if (n < 0) {
		onClose();
		return;
	}

	_readBuffer.append(buf, n);

	std::cout << "_readBuffer: " << _readBuffer << std::endl;
}

void ClientConnection::onWrite() {
	if (_writeBuffer.empty()) {
		return;
	}
	ssize_t n = ::write(_clientFd, _writeBuffer.c_str(), _writeBuffer.size());
	if (n < 0) {
		onError();
		return;
	}
	else if (n == 0) {
		onClose();
		return;
	}

	_writeBuffer.erase(0, n);
}

void ClientConnection::onError() {
	std::cerr << _clientFd << " error" << std::endl;
	::close(_clientFd);
}

void ClientConnection::onClose() {
	std::cerr << _clientFd << " closed" << std::endl;
	::close(_clientFd);
}
