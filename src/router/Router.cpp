//
// Created by Heesung Choi on 3/4/25.
//
#include "Router.hpp"

Router::Router() : _port(0), _host(0), _clientMaxBodySize(0), _locations() {
}

Router::Router(int port, int host, std::string const& serverName, std::string const& errorPage,
               long clientMaxBodySize, std::string const& root,
               std::vector<Location*> const& locations)
    : _port(port),
      _host(host),
      _serverName(serverName),
      _errorPage(errorPage),
      _clientMaxBodySize(clientMaxBodySize),
      _root(root),
      _locations(locations) {
}

Router::Router(Router const&) : _clientMaxBodySize(0), _host(0), _port(0) {
}

Router& Router::operator=(Router const&) {
    return *this;
}

Router::~Router() {
}
