//
// Created by Heesung Choi on 3/4/25.
//
#include "StaticLocation.hpp"

StaticLocation::StaticLocation() : _autoindex(false) {
}

StaticLocation::StaticLocation(const std::string& uri, const std::string& root,
                               const std::string& index, const std::string& errorPage,
                               const std::vector<Method>& allowedMethods)
    : _uri(uri),
      _root(root),
      _index(index),
      _errorPage(errorPage),
      _allowedMethods(allowedMethods),
      _autoindex(false) {
}

StaticLocation::StaticLocation(StaticLocation const&)
    : _uri(""), _root(""), _index(""), _errorPage(""), _allowedMethods(), _autoindex(false) {
}

StaticLocation& StaticLocation::operator=(StaticLocation const&) {
    return *this;
}

StaticLocation::~StaticLocation() {
}

bool StaticLocation::canHandleRequest(const std::string& uri) const {
    return uri == _uri;
}
int StaticLocation::handleRequest(const std::string& uri) const {
    // TODO: implement
}
