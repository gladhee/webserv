//
// Created by Heesung Choi on 3/4/25.
//

#ifndef WEBSERV_ROUTER_HPP
#define WEBSERV_ROUTER_HPP

#include <string>
#include <vector>

#include "Location.hpp"

class Router {
private:
	int const _port;
	int const _host;
	std::string const _serverName;
	std::string const _errorPage;
	long const _clientMaxBodySize;
	std::string const _root;
	std::vector<Location*> const _locations;

public:
	Router(int port, int host, std::string const& serverName, std::string const& errorPage,
			long clientMaxBodySize, std::string const& root,
			std::vector<Location*> const& locations);

	~Router();

private:
	Router();
	Router(Router const&);
	Router& operator=(Router const&);
};

#endif  // WEBSERV_ROUTER_HPP
