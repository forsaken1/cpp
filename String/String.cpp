#include "String.h"

//class Buf
String::Buf::Buf(const char *s) { 
    length = strlen(s);
    string = new char[length + 1];
    rc = 1;
    strcpy(string, s);
}

String::Buf::~Buf() { 
    delete [] string; 
}

void String::Buf::operator++() {
    rc++;
}
        
void String::Buf::operator--() {
    rc--;
	if(rc < 1) this->~Buf();
}

//class String
String::String(const char *s) {
    buf = new Buf(s);
}

String::String(const String &s) {
    buf = s.buf;
    ++(*buf);
}

String::~String() { 
    --(*buf);
}
    
String String::operator=(const String &s) {
    if(&s != this) {
        --(*buf);
        buf = s.buf;  
        ++(*buf);
    }
    else cout << "Warning: assignment of a String to itself\n";
    return *this;
}

String String::operator+(const String &str) {
    String Str;
    Str.buf->length = buf->length + str.GetLength();
    Str.buf->string = new char[Str.buf->length + 1];
    Str.buf->rc = 1;
    strcpy(Str.buf->string, buf->string);
    strcat(Str.buf->string, str.buf->string);
    return Str;
}
    
String String::operator+=(const String &s)    { return *this = *this + s; }
int String::GetLength() const                 { return buf->length; }
int String::operator!() const                 { return buf->length == 0; }

int String::operator==(const String &s) const { return strcmp(buf->string, s.buf->string) == 0; }
int String::operator!=(const String &s) const { return strcmp(buf->string, s.buf->string) != 0; } 
int String::operator<(const String &s) const  { return strcmp(buf->string, s.buf->string) < 0; }
int String::operator>(const String &s) const  { return strcmp(buf->string, s.buf->string) > 0; }
int String::operator>=(const String &s) const { return strcmp(buf->string, s.buf->string) >= 0; }
int String::operator<=(const String &s) const { return strcmp(buf->string, s.buf->string) <= 0; }

int String::operator==(const char *s) const { return strcmp(buf->string, s) == 0; }
int String::operator!=(const char *s) const { return strcmp(buf->string, s) != 0; } 
int String::operator<(const char *s) const  { return strcmp(buf->string, s) < 0; }
int String::operator>(const char *s) const  { return strcmp(buf->string, s) > 0; }
int String::operator>=(const char *s) const { return strcmp(buf->string, s) >= 0; }
int String::operator<=(const char *s) const { return strcmp(buf->string, s) <= 0; }

ProxyChar String::operator[](int index) { 
    if(0 <= index && index < buf->length)
        return ProxyChar(buf->string, index);
    else cout << "Warning: out of range\n";
}

String String::operator()(int index, int _length) {  
    if(0 <= index && index < buf->length) {
        String str;
        int i, j = 0;
        
        if(_length + index >= buf->length || _length == 0) _length = buf->length - index;
        str.buf->length = _length + 1;
        str.buf->string = new char[_length + 1];
        for(i = index; i < index + _length; i++, j++)
            str.buf->string[j] = buf->string[i];
        str.buf->string[j] = '\0';
        return str;
    }
    else cout << "Warning: out of range\n";
}

ostream &operator<<(ostream &output, const String &s) {
    output << s.buf->string;
    return output;
}

istream &operator>>(istream &input, String &s) {
	char buf[100];
	cin.get(buf, 100, '\n');	
	char c;
	if(cin.get(c) && c != '\n') {
		
	}
	strcpy(s.buf->string, buf);
    return input;
}

int String::getRC() const {
	return buf->rc;
}
