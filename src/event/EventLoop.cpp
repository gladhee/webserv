//
// Created by HeeSung Choi on 3/3/25.
//

#include "event/EventLoop.hpp"

EventLoop::EventLoop() {
	_kq = kqueue();
	if (_kq == -1) {
		perror("kqueue");
		exit(EXIT_FAILURE);
	}
}

EventLoop::EventLoop(EventLoop const&) {
}

EventLoop& EventLoop::operator=(EventLoop const&) {
	return *this;
}

EventLoop::~EventLoop() {
	close(_kq);
}

void EventLoop::run() {
	Kevent eventList[MAX_EVENTS];

	while (true) {
		int nev =
				kevent(_kq, &_changeList[0], static_cast<int>(_changeList.size()), eventList, 8, NULL);

		if (nev < 0) {
			std::cerr << "kevent error" << std::endl;
			continue;
		}

		for (int i = 0; i < nev; ++i) {
			Kevent& curr = eventList[i];
			int fd = static_cast<int>(curr.ident);

			if (_connections.find(fd) == _connections.end()) {
				continue;
			}

			Connection* conn = _connections[fd];

			if (curr.flags & EV_ERROR) {
				int errCode = static_cast<int>(curr.data);
				std::cerr << errCode << "EV_ERROR" << std::endl;
				conn->onError();
				delete conn;
				_connections.erase(fd);
				continue;
			}

			if (curr.flags & EV_EOF) {
				std::cerr << "EV_EOF" << std::endl;
				conn->onClose();
				_connections.erase(fd);
				continue;
			}

			if (curr.filter == EVFILT_READ) {
				conn->onRead();
			}
			if (curr.filter == EVFILT_WRITE) {
				conn->onWrite();
			}
		}
	}
}

void EventLoop::addReadEvent(int fd, Connection* conn) {
	Kevent ev;

	EV_SET(&ev, fd, EVFILT_READ, EV_ADD, 0, 0, conn);
	_changeList.push_back(ev);
	_connections[fd] = conn;
}

void EventLoop::addWriteEvent(int fd, Connection* conn) {
	Kevent ev;

	EV_SET(&ev, fd, EVFILT_WRITE, EV_ADD, 0, 0, conn);
	_changeList.push_back(ev);
	_connections[fd] = conn;
}
