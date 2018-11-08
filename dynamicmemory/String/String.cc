#include <iostream>
#include <cstring>
#include <cstdint>
#include <algorithm>
#include "String.hh"

using namespace std;

String::String(): capacity(0), len(0), s(nullptr) {}
String::String(const char str[]): capacity(strlen(str)), len(strlen(str)), s(new char[capacity]) {
	for (uint32_t i = 0; i < len; i++) {
		s[i] = str[i];
	}
}

String::String(const char str[], uint32_t mult): capacity(strlen(str) * mult), len(strlen(str) * mult), s(new char[capacity]) {
	for (uint32_t i = 0, c = 0; i < mult; i++) {
		for (uint32_t j = 0; j < strlen(str); j++, c++) {
			s[c] = str[j];
		}
	}
}
//copy constructor
String::String(const String& orig) {
	this->len = orig.len;
	this->capacity = orig.capacity;
	this->s = new char[len];
	for (int i = 0; i < len; i++) {
		s[i] = orig.s[i];
	}
}

String::~String() {
	delete [] s;
}

void String::expandCapacity(uint32_t addedLen, uint32_t not_copyLen = 0) {
	if (this->len + addedLen > this->capacity) {
		this->capacity *= 2;
		char* copy = new char[this->capacity];
		for (uint32_t i = 0; i < this->len - not_copyLen; ++i) {
			copy[i] = this->s[i];
		}
		swap(this->s, copy);
	}
}

String& String::operator =(const String& orig) {
	String copy(orig);
	this->len = copy.length();
	this->capacity = copy.getCapacity();
	swap(this->s, copy.s);

	return *this;
}


uint32_t String::length() const {
	return this->len;
}
uint32_t String::getCapacity() const {
	return this->capacity;
}

void String::operator +=(const char str[] ) {
	uint32_t addedLen = strlen(str);

	// check if we should double the capacity
	expandCapacity(addedLen);
	for (uint32_t i = 0; i < addedLen; ++i) {
		this->s[this->len + i] = str[i];
	}
	this->len += addedLen;
}
void String::operator +=(const String& str) {
	uint32_t addedLen = str.len;
	expandCapacity(addedLen);
	for (uint32_t i = 0; i < addedLen; ++i) {
		this->s[this->len + i] = str[i];
	}
	this->len += addedLen;
}

String String::operator +(const String& str) const {
	char* res = new char[this->len + str.len];
	for (uint32_t i = 0; i < this->len; ++i) {
		res[i] = s[i];
	}
	for (uint32_t i = 0; i < str.len; ++i) {
		res[this->len + i] = str[i];
	}
	String ans(res);
	return ans;
}

char String::operator [](const uint32_t pos) const {
	return s[pos];
}
char& String::operator [](uint32_t pos) {
	return s[pos];
}

String String::substring(uint32_t pos, uint32_t length) const {
	char* tempStr = new char[length];
	for (int i = 0; i < length; i++) {
		tempStr[i] = s[pos + i];
	}
	String ans(tempStr);
	return ans;
}
void String::replace(char replace_ee, char replace_er) {
	for (uint32_t i = 0; i < len; ++i) {
		if (s[i] == replace_ee) {
			s[i] = replace_er;
		}
	}
}
void String::insert(uint32_t pos, const String& str) {
		uint32_t addedLen = str.length();
		if (this->len + addedLen > this->capacity) {
			this->capacity *= 2;
			char* copy = new char[this->capacity];
			for (uint32_t i = 0; i < pos; ++i) {
				copy[i] = this->s[i];
			}
			for (uint32_t i = pos; i < this->len; ++i) {
				copy[i + addedLen] = this->s[i];
			}
			swap(this->s, copy);
		} else {
			// this should be backwards, otherwise causes overwrite errors.
			for (uint32_t i = this->len; i >= pos ; --i) {
				this->s[i + addedLen] = this->s[i];
			}
		}
		for (uint32_t i = 0; i < addedLen; ++i) {
			this->s[i + pos] = str[i];
		}
		this->len += addedLen;
}

std::ostream& operator<<(std::ostream& s, const String& str) {
	for (int i = 0; i < str.len; i++) {
		s << str[i];
	}
	return s;
}
