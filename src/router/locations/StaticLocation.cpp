//
// Created by Heesung Choi on 3/4/25.
//
#include "StaticLocation.hpp"

StaticLocation::StaticLocation()
		:_autoindex(false) {
}

StaticLocation::StaticLocation(std::string const& uri, std::string const& root, std::string const& index,
		std::string const& errorPage, std::vector<Method> const& allowedMethods)
		:_uri(uri),
		 _root(root),
		 _index(index),
		 _errorPage(errorPage),
		 _allowedMethods(allowedMethods),
		 _autoindex(false) {
}

StaticLocation::StaticLocation(StaticLocation const&)
		:_uri(""), _root(""), _index(""), _errorPage(""), _allowedMethods(), _autoindex(false) {
}

StaticLocation& StaticLocation::operator=(StaticLocation const&) {
	return *this;
}

StaticLocation::~StaticLocation() {
}

bool StaticLocation::canHandleRequest(std::string const& uri) const {
	return uri == _uri;
}
int StaticLocation::handleRequest(std::string const& uri) const {
	// TODO: implement
}
