//
// Created by HeeSung Choi on 3/16/25.
//

#include "ConfigTokenizer.hpp"

ConfigTokenizer::ConfigTokenizer()
		:_pos(), _line() {
}

ConfigTokenizer::ConfigTokenizer(std::string const& path)
		:_pos(0), _line(1) {
	std::ifstream in(path.c_str());
	std::stringstream ss;

	if (!in.is_open()) {
		throw std::runtime_error("Cannot open file");
	}

	ss << in.rdbuf();
	_config = ss.str();
	in.close();
}

ConfigTokenizer::ConfigTokenizer(ConfigTokenizer const&) {
}

ConfigTokenizer& ConfigTokenizer::operator=(ConfigTokenizer const&) {
	return *this;
}

ConfigTokenizer::~ConfigTokenizer() {
}

std::vector<Token> ConfigTokenizer::tokenize() {
	std::vector<Token> tokens;
	Token token = getNextToken();

	while (token.type != TOKEN_END) {
		tokens.push_back(token);
		token = getNextToken();
	}

	tokens.push_back(token);

	return tokens;
}

void ConfigTokenizer::skipWhitespaceAndComments() {
	while (_pos < _config.length()) {
		char ch = _config[_pos];
		if (::isspace(ch)) {
			if (ch == NEWLINE)
				_line++;
			_pos++;
		}
		else if (ch == COMMENT) {
			while (_pos < _config.length() && _config[_pos] != NEWLINE)
				_pos++;
		}
		else {
			break;
		}
	}
}

Token ConfigTokenizer::getNextToken() {
	skipWhitespaceAndComments();
	if (_pos >= _config.length()) {
		return Token(TOKEN_END, "", _line);
	}
	char ch = _config[_pos];

	if (ch == LBRACE) {
		_pos++;
		return Token(TOKEN_LBRACE, LBRACE, _line);
	}
	if (ch == RBRACE) {
		_pos++;
		return Token(TOKEN_RBRACE, RBRACE, _line);
	}
	if (ch == SEMICOLON) {
		_pos++;
		return Token(TOKEN_SEMICOLON, SEMICOLON, _line);
	}

	if (isdigit(ch)) {
		return readNumber();
	}

	return readIdentifier();
}

Token ConfigTokenizer::readNumber() {
	size_t start = _pos;
	while (_pos < _config.length() && isdigit(_config[_pos])) {
		_pos++;
	}

	return Token(TOKEN_NUMBER, _config.substr(start, _pos - start), _line);
}

Token ConfigTokenizer::readIdentifier() {
	size_t start = _pos;
	while (_pos < _config.length()) {
		char ch = _config[_pos];
		if (isspace(ch) || ch == RBRACE || ch == LBRACE || ch == SEMICOLON) {
			break;
		}

		_pos++;
	}
	return Token(TOKEN_IDENTIFIER, _config.substr(start, _pos - start), _line);
}
