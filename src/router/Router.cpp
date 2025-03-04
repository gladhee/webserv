//
// Created by Heesung Choi on 3/4/25.
//
#include "Router.hpp"

Router::Router() : port(0), host(0), clientMaxBodySize(0), locations() {
}

Router::Router(int port, int host, std::string const& serverName, std::string const& errorPage,
               long clientMaxBodySize, std::string const& root,
               std::vector<Location*> const& locations)
    : port(port),
      host(host),
      serverName(serverName),
      errorPage(errorPage),
      clientMaxBodySize(clientMaxBodySize),
      root(root),
      locations(locations) {
}

Router::Router(Router const&) : clientMaxBodySize(0), host(0), port(0) {
}

Router& Router::operator=(Router const&) {
    return *this;
}

Router::~Router() {
}
