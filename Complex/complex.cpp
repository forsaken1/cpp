#include "complex.h"

////Operations
///////////////////////////////////////+
Complex Complex::operator+(const Complex &a) {
    return Complex(re + a.re, im + a.im);
}

Complex Complex::operator+(double a) {
    return Complex(re + a, im);   
}

Complex operator+(double a, const Complex &b) {
    return Complex(a + b.getReal(), b.getImage());
}
///////////////////////////////////////-
Complex Complex::operator-(const Complex &a) {
    return Complex(re - a.re, im - a.im);
}

Complex Complex::operator-(double a) {
    return Complex(re - a, im);   
}

Complex operator-(double a, const Complex &b) {
    return Complex(a - b.getReal(), - b.getImage());    
}
///////////////////////////////////////*
Complex Complex::operator*(const Complex &a) {
    return Complex(re * a.re - im * a.im, im * a.re + re * a.im);
}

Complex Complex::operator*(double a) {
    return Complex(re * a, im * a);
}

Complex operator*(double a, const Complex &b) {
    return Complex(a * b.getReal(), a * b.getImage());  
}
///////////////////////////////////////:/
Complex Complex::operator/(const Complex &a) {
    if(a.getReal() == 0 && a.getImage() == 0) 
        cout << "Warning: Divide by zero\n";
    else 
        return Complex((re * a.re + im * a.im) / (pow(a.re, 2) + pow(a.im, 2)), 
                       (im * a.re - re * a.im) / (pow(a.re, 2) + pow(a.im, 2)));
}

Complex Complex::operator/(double a) {
    if(a == 0) 
        cout << "Warning: Divide by zero\n";
    else 
        return Complex(re / a, im / a);
}

Complex operator/(double a, const Complex &b) {
    if(b.getReal() == 0 && b.getImage() == 0) 
        cout << "Warning: Divide by zero\n";
    else {
        Complex c = Complex(a);
        c /= b;
        return c; 
    }
}
///////////////////////////////////////=
Complex Complex::operator=(const Complex a) {
    re = a.re;
    im = a.im;  
    return *this;
}

Complex Complex::operator=(double a) {
    re = a;
    return *this;
}
///////////////////////////////////////!=
int Complex::operator!=(const Complex &a)   { return !(re == a.re && im == a.im); }
int Complex::operator!=(double a)           { return !(re == a && im == 0); }
int operator!=(double a, const Complex &b)  { return !(b.getReal() == a && b.getImage() == 0); }
///////////////////////////////////////==
int Complex::operator==(const Complex &a)   { return re == a.re && im == a.im; }
int Complex::operator==(double a)           { return re == a && im == 0; }
int operator==(double a, const Complex &b)  { return b.getReal() == a && b.getReal() == 0; }
///////////////////////////////////////+=
Complex Complex::operator+=(const Complex &a) { return *this = *this + a; }
Complex Complex::operator+=(double a)         { return *this = *this + a; }
Complex operator+=(double a, const Complex &b) { return a + b; }
///////////////////////////////////////-=
Complex Complex::operator-=(const Complex &a)   { return *this = *this - a; }
Complex Complex::operator-=(double a)           { return *this = *this - a; }
Complex operator-=(double a, const Complex &b)  { return a - b; }
///////////////////////////////////////*=
Complex Complex::operator*=(const Complex &a)   { return *this = *this * a; }
Complex Complex::operator*=(double a)           { return *this = *this * a; }
Complex operator*=(double a, const Complex &b)  { return a * b; }
///////////////////////////////////////:/=
Complex Complex::operator/=(const Complex &a)   { return *this = *this / a; }
Complex Complex::operator/=(double a)           { return *this = *this / a; }
Complex operator/=(double a, const Complex &b)  { return a / b; }
//////////////////////////////////////
Complex::Complex(): re(0), im(0) {}
Complex::Complex(double _re): re(_re), im(0) {}
Complex::Complex(double _re, double _im): re(_re), im(_im) {}

double Complex::getArg() const      { return atan2(im, re); }
double Complex::getMod() const      { return sqrt(re * re + im * im); }
double Complex::getReal() const     { return re; }
double Complex::getImage() const    { return im; }

void Complex::print() {
    if(im == 0)      cout << re << "\n";
    else if(re == 0) cout << im << "i\n";
         else        cout << re << (im > 0 ? " + " : " - ") << fabs(im) << "i\n";
}

void Complex::setComplex(double _re, double _im) {
    setReal(_re);
    setImage(_im);
}

void Complex::setReal(double _re)   { re = _re; }
void Complex::setImage(double _im)  { im = _im; }
