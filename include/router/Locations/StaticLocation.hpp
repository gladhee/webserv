//
// Created by Heesung Choi on 3/4/25.
//

#ifndef WEBSERV_STATICLOCATION_HPP
#define WEBSERV_STATICLOCATION_HPP

#include <string>
#include <vector>

#include "Location.hpp"
#include "Method.hpp"

class StaticLocation : public Location {
private:
    std::string const _uri;
    std::string const _root;
    std::string const _index;
    std::string const _errorPage;
    std::vector<Method> const _allowedMethods;
    bool const _autoindex;

public:
    StaticLocation(std::string const& uri, std::string const& root, std::string const& index,
                   std::string const& errorPage, std::vector<Method> const& allowedMethods);

    bool canHandleRequest(std::string const& uri) const;
    int handleRequest(std::string const& uri) const;

    ~StaticLocation();

private:
    StaticLocation();
    StaticLocation(StaticLocation const&);
    StaticLocation& operator=(StaticLocation const&);
};

#endif  // WEBSERV_STATICLOCATION_HPP
