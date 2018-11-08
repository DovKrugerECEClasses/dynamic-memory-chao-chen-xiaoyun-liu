#pragma once
#include <iostream>

class String {
private:
	uint32_t capacity;
	uint32_t len;
	char* s;
	void expandCapacity(uint32_t, uint32_t);
public:
  String();
	String(const char*);
	String(const char*, uint32_t);
	//copy constructor
	String(const String&);
	~String();

	String& operator =(const String& orig);

	uint32_t length() const;
	uint32_t getCapacity() const;

	void operator += (const char str[]);
	void operator += (const String&);
	String operator +(const String&) const;

	char operator [](const uint32_t pos) const;
	char& operator [](uint32_t pos);

	String substring(uint32_t, uint32_t) const;
	void replace(char, char);
	void insert(uint32_t, const String&);

  friend std::ostream& operator<<(std::ostream& s, const String& str);
};
