//
// Created by Heesung Choi on 3/4/25.
//

#ifndef WEBSERV_LOCATION_HPP
#define WEBSERV_LOCATION_HPP

#include <string>

class Location {

public:
	virtual bool canHandleRequest(std::string const& uri) const = 0;
	virtual int handleRequest(std::string const& uri) const = 0;

};

#endif  // WEBSERV_LOCATION_HPP
