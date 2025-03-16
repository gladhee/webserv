//
// Created by HeeSung Choi on 3/16/25.
//

#ifndef WEBSERV_CONFIGTOKENIZER_HPP
#define WEBSERV_CONFIGTOKENIZER_HPP

#include <string>
#include <fcntl.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

enum TokenType {
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_SEMICOLON,
	TOKEN_END
};

struct Token {
	TokenType type;
	std::string value;
	int line;

	Token(TokenType t, std::string const& v, int l)
			:type(t), value(v), line(l) {
	}
	Token(TokenType t, char v, int l)
			:type(t), line(l) {
		value.push_back(v);
	}
};

class ConfigTokenizer {
private:
	static char const NEWLINE = '\n';
	static char const SPACE = ' ';
	static char const TAB = '\t';
	static char const COMMENT = '#';
	static char const LBRACE = '{';
	static char const RBRACE = '}';
	static char const SEMICOLON = ';';

	std::string _config;
	size_t _pos;
	int _line;

public:
	explicit ConfigTokenizer(std::string const& path);
	~ConfigTokenizer();

	std::vector<Token> tokenize();

private:
	ConfigTokenizer();
	ConfigTokenizer(ConfigTokenizer const&);
	ConfigTokenizer& operator=(ConfigTokenizer const&);

	void skipWhitespaceAndComments();
	Token getNextToken();
	Token readIdentifier();
	Token readNumber();
};

#endif //WEBSERV_CONFIGTOKENIZER_HPP
