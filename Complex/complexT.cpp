#include "complexT.h"

////Operations
///////////////////////////////////////+
ComplexT ComplexT::operator+(const ComplexT &a) {
    ComplexT c;
    c.mod = sqrt(pow(getReal() + a.getReal(), 2) + pow(getImage() + a.getImage(), 2));
    c.arg = atan2(getImage() + a.getImage(), getReal() + a.getReal());
    return c;
}

ComplexT ComplexT::operator+(double a) {
    ComplexT c;
    c.mod = sqrt(pow(getReal() + a, 2) + pow(getImage(), 2));
    c.arg = atan2(getImage(), getReal() + a);
    return c;   
}

ComplexT operator+(double a, const ComplexT &b) {
    ComplexT c;
    c.mod = sqrt(pow(b.getReal() + a, 2) + pow(b.getImage(), 2));
    c.arg = atan2(b.getImage(), b.getReal() + a);
    return c;
}
///////////////////////////////////////-
ComplexT ComplexT::operator-(const ComplexT &a) {
    ComplexT c;
    c.mod = sqrt(pow(getReal() - a.getReal(), 2) + pow(getImage() - a.getImage(), 2));
    c.arg = atan2(getImage() - a.getImage(), getReal() - a.getReal());
    return c;
}

ComplexT ComplexT::operator-(double a) {
    ComplexT c;
    c.mod = sqrt(pow(getReal() - a, 2) + pow(getImage(), 2));
    c.arg = atan2(getImage(), getReal() - a);
    return c;   
}

ComplexT operator-(double a, const ComplexT &b) {
    ComplexT c;
    c.mod = sqrt(pow(a - b.getReal(), 2) + pow(b.getImage(), 2));
    c.arg = atan2( - b.getImage(), a - b.getReal());
    return c;
}
///////////////////////////////////////*
ComplexT ComplexT::operator*(const ComplexT &a) {
    ComplexT c;
    c.mod = mod * a.mod;
    c.arg = arg + a.arg;
    return c;
}

ComplexT ComplexT::operator*(double a) {
    ComplexT c;
    c.mod = mod * a;
    c.arg = arg;
    return c;
}

ComplexT operator*(double a, const ComplexT &b) {
    ComplexT c;
    c.mod = b.mod * a;
    c.arg = b.arg;
    return c;
}
///////////////////////////////////////:/
ComplexT ComplexT::operator/(const ComplexT &a) {
    if(a.mod == 0) 
        cout << "Warning: Divide by zero\n";
    else {
        ComplexT c;
        c.mod = mod / a.mod;
        c.arg = arg - a.arg;
        return c;
    }
}

ComplexT ComplexT::operator/(double a) {
    if(a == 0) 
        cout << "Warning: Divide by zero\n";
    else {
        ComplexT c;
        c.mod = mod / a;
        c.arg = arg;
        return c;
    }
}

ComplexT operator/(double a, const ComplexT &b) {
    if(b.getReal() == 0 && b.getImage() == 0) 
        cout << "Warning: Divide by zero\n";
    else {
        ComplexT c = ComplexT(a);
        c /= b;
        return c; 
    }
}
///////////////////////////////////////=
ComplexT ComplexT::operator=(const ComplexT a) {
    mod = a.mod;
    arg = a.arg;  
    return *this;
}

ComplexT ComplexT::operator=(double a) {
    mod = a;
    arg = 0;
    return *this;
}
///////////////////////////////////////!=
int ComplexT::operator!=(const ComplexT &a)         { return !(*this == a); }
int ComplexT::operator!=(double a)                  { return !(*this == a); }
int operator!=(double a, const ComplexT &b)         { return !(floor(b.getReal()) == a && b.getImage() == 0); }
///////////////////////////////////////==
int ComplexT::operator==(const ComplexT &a)         { return fabs(getMod() - a.getMod()) < EPS && fabs(getArg() - a.getArg() < EPS); }
int ComplexT::operator==(double a)                  { return fabs(getReal() - a) < EPS && fabs(getImage()) < EPS; }
int operator==(double a, const ComplexT &b)         { return floor(b.getReal()) == a && b.getImage() == 0; }
///////////////////////////////////////+=
ComplexT ComplexT::operator+=(const ComplexT &a)    { return *this = *this + a; }
ComplexT ComplexT::operator+=(double a)             { return *this = *this + a; }
ComplexT operator+=(double a, const ComplexT &b)    { return a + b; }
///////////////////////////////////////-=
ComplexT ComplexT::operator-=(const ComplexT &a)    { return *this = *this - a; }
ComplexT ComplexT::operator-=(double a)             { return *this = *this - a; }
ComplexT operator-=(double a, const ComplexT &b)    { return a - b; }
///////////////////////////////////////*=
ComplexT ComplexT::operator*=(const ComplexT &a)    { return *this = *this * a; }
ComplexT ComplexT::operator*=(double a)             { return *this = *this * a; }
ComplexT operator*=(double a, const ComplexT &b)    { return a * b; }
///////////////////////////////////////:/=
ComplexT ComplexT::operator/=(const ComplexT &a)    { return *this = *this / a; }
ComplexT ComplexT::operator/=(double a)             { return *this = *this / a; }
ComplexT operator/=(double a, const ComplexT &b)    { return a / b; }
//////////////////////////////////////
ComplexT::ComplexT(): mod(0), arg(0) {}
ComplexT::ComplexT(double re): mod(re), arg(0) {}
ComplexT::ComplexT(double re, double im): mod(sqrt(pow(re, 2) + pow(im, 2))), arg(atan2(im, re)) {}

double ComplexT::getArg() const                     { return arg; }
double ComplexT::getMod() const                     { return mod; }
double ComplexT::getReal() const                    { return mod * cos(arg); }
double ComplexT::getImage() const                   { return mod * sin(arg); }

void ComplexT::print() {
    if(getImage() == 0)     cout << getReal() << "\n";
    else if(getReal() == 0) cout << getImage() << "i\n";
         else               cout << getReal() << (getImage() > 0 ? " + " : " - ") << fabs(getImage()) << "i\n";
}

void ComplexT::setComplex(double re, double im) {
    setReal(re);
    setImage(im);
}

void ComplexT::setReal(double re) { 
    mod = sqrt(pow(re, 2) + pow(mod * sin(arg), 2)); 
    arg = atan2(mod * sin(arg), re); 
}

void ComplexT::setImage(double im) { 
    mod = sqrt(pow(mod * cos(arg), 2) + pow(im, 2)); 
    arg = atan2(im, mod * cos(arg)); 
}
