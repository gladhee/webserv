//
// Created by HeeSung Choi on 3/3/25.
//

#ifndef WEBSERV_EVENTLOOP_HPP
#define WEBSERV_EVENTLOOP_HPP

#include <fcntl.h>
#include <sys/event.h>
#include <unistd.h>

#include <iostream>
#include <map>
#include <string>

#include "Connection.hpp"

typedef struct kevent Kevent;

class EventLoop {
private:
    static int const MAX_EVENTS = 32;
    int _kq;
    std::vector<Kevent> _changeList;
    std::map<int, Connection*> _connections;

public:
    EventLoop();

    ~EventLoop();

    void run();

    void addReadEvent(int fd, Connection* conn);

    void addWriteEvent(int fd, Connection* conn);

private:
    EventLoop(const EventLoop&);

    EventLoop& operator=(const EventLoop&);
};

#endif  // WEBSERV_EVENTLOOP_HPP
