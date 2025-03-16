//
// Created by HeeSung Choi on 3/16/25.
//

#ifndef WEBSERV_OPTIONAL_HPP
#define WEBSERV_OPTIONAL_HPP

template<class T>
class Optional {
private:
	T _value;
	bool _hasValue;

public:
	Optional()
			:_hasValue(false) {
	}

	explicit Optional(T const& value)
			:_value(value), _hasValue(true) {
	}

	Optional(Optional const& other)
			:_value(other._value), _hasValue(other._hasValue) {
	}

	Optional& operator=(Optional const& other) {
		_value = other._value;
		_hasValue = other._hasValue;

		return *this;
	}

	~Optional() {
	}

	T const& operator*() const {
		return _value;
	}

	T& operator*() {
		return _value;
	}

	T const* operator->() const {
		return &_value;
	}

	T* operator->() {
		return &_value;
	}

	bool hasValue() const {
		return _hasValue;
	}

	T const& value() const {
		return _value;
	}

	T& value() {
		return _value;
	}
};

#endif //WEBSERV_OPTIONAL_HPP
