#include "classString.h"
///////////////////////////////////////class Buf
String::Buf::Buf(const char *s) { 
    length = strlen(s);
    string = new char[length + 1];
    rc = 1;
    strcpy(string, s);
}

String::Buf::~Buf() { 
    delete [] string; 
}

void String::Buf::incRC() {
    rc++;
}
        
void String::Buf::decRC() {
    rc--;
}
///////////////////////////////////////class String
String::String(const char *s) {
    buf = new Buf(s);
}

String::String(const String &s) {
    buf = s.getBuf();
    buf->incRC();
}

String::~String() { 
    buf->decRC();
    if(getRC() < 1) buf->~Buf();
}
    
String String::operator=(const String &s) {
    if(&s != this) {
        buf->decRC();
        buf = s.getBuf();  
        buf->incRC();
    }
    else cout << "Warning: assignment of a String to itself\n";
    return *this;
}

String String::operator+(const String &str) {
    String Str;
    Str.buf->length = buf->length + str.getLength();
    Str.buf->string = new char[Str.buf->length + 1];
    Str.buf->rc = 1;
    strcpy(Str.buf->string, buf->string);
    strcat(Str.buf->string, str.buf->string);
    return Str;
}

    
String String::operator+=(const String &s)    { return *this + s; }
String::Buf* String::getBuf() const           { return buf; }
char* String::getString() const               { return buf->string; }
int String::getRC() const                     { return buf->rc; }
int String::getLength() const                 { return buf->length; }
int String::operator!() const                 { return buf->length == 0; }
int String::operator==(const String &s) const { return strcmp(getString(), s.getString()) == 0; }
int String::operator!=(const String &s) const { return strcmp(getString(), s.getString()) != 0; } 
int String::operator<(const String &s) const  { return strcmp(getString(), s.getString()) < 0; }
int String::operator>(const String &s) const  { return strcmp(getString(), s.getString()) > 0; }
int String::operator>=(const String &s) const { return strcmp(getString(), s.getString()) >= 0; }
int String::operator<=(const String &s) const { return strcmp(getString(), s.getString()) <= 0; }

char &String::operator[](int index) { 
    if(0 <= index && index < buf->length)
        return buf->string[index];
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
    output << s.getString();
    return output;   
}

istream &operator>>(istream &input, String &s) {
    char* buffer = new char[1000];
    char* temp;
    
    while(cin.get(buffer, 1000)) {
        if(!s) {
            temp = new char[s.buf->length + 1];
            strcpy(temp, s.buf->string);
            delete [] s.buf->string;
        }
        else temp = new char[0];
        s.buf->length += cin.gcount();
        s.buf->string = new char[s.buf->length + 1];
        strcpy(s.buf->string, temp);
        strcat(s.buf->string, buffer);
        delete [] temp;
    }
    delete [] buffer;
    return input;
}
