//
// Created by HeeSung Choi on 3/3/25.
//

#ifndef WEBSERV_CONNECTION_HPP
#define WEBSERV_CONNECTION_HPP

class Connection {

public:
	virtual ~Connection() {};
	virtual void onRead() = 0;
	virtual void onWrite() = 0;
	virtual void onError() = 0;
	virtual void onClose() = 0;

};

#endif //WEBSERV_CONNECTION_HPP
