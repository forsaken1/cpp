
#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class ProxyChar {
	char* string;
	int index;
public:
	ProxyChar(char* str, int ind): string(str), index(ind) {}
	operator char() { return string[index]; }
	ProxyChar operator=(const char &ch) { string[index] = ch; return *this; }
	int operator==(const char &ch) { return string[index] == ch; }
};

class String {      

    class Buf {
    public:
		friend String;

        char *string;
        int length, rc;

        Buf(const char * = "");
        ~Buf();
    
        void operator++();
        void operator--();
    };
    
    Buf *buf;
public:
    String(const char * = "");
    String(const String &);
    ~String();
    
    String operator=(const String &);
    String operator+(const String &);
    String operator+=(const String &);
    int GetLength() const;
    int operator!() const;
    
    int operator==(const String &) const;
    int operator!=(const String &) const;
    int operator<(const String &) const;
    int operator>(const String &) const;
    int operator>=(const String &) const;
    int operator<=(const String &) const;

	int operator==(const char *) const;
    int operator!=(const char *) const;
    int operator<(const char *) const;
    int operator>(const char *) const;
    int operator>=(const char *) const;
    int operator<=(const char *) const;

    ProxyChar operator[](int);
	String operator()(int, int);
    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &, String &);

	int getRC() const; //for debug
};

#endif STRING_H
