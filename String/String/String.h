#include <iostream>
using namespace std;

class String {   
    class ProxyChar {
        char value;
    };
     
    class Buf {
    public:
        char *string;
        int length, rc;

        Buf(const char * = "");
        ~Buf();
    
        void incRC();
        void decRC();
    };
    
private:
    Buf *buf;
public:
    String(const char * = "");
    String(const String &);
    ~String();
    
    String operator=(const String &);
    String operator+(const String &);
    String operator+=(const String &);
    int getLength() const;
    int operator!() const;
    Buf* getBuf() const;
    int getRC() const;
    char* getString() const;
    
    int operator==(const String &) const;
    int operator!=(const String &) const;
    int operator<(const String &) const;
    int operator>(const String &) const;
    int operator>=(const String &) const;
    
    int operator<=(const String &) const;
    char &operator[](int);
    String operator()(int, int);
    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &, String &);
};

