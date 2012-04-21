#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

class Complex {
private:
    double re, im;
public:
    Complex();
    Complex(double);
    Complex(double, double);
    
    void print();
    void setComplex(double, double);
    void setReal(double); 
    void setImage(double);
    
    double getReal() const;
    double getImage() const;
    double getArg() const;
    double getMod() const;
    
    Complex operator+(const Complex &);
    Complex operator+(double);
    friend Complex operator+(double, const Complex &);
    
    Complex operator-(const Complex &);
    Complex operator-(double);
    friend Complex operator-(double, const Complex &);
    
    Complex operator*(const Complex &);
    Complex operator*(double);
    friend Complex operator*(double, const Complex &);
    
    Complex operator/(const Complex &);
    Complex operator/(double);
    friend Complex operator/(double, const Complex &);
    
    Complex operator=(const Complex);
    Complex operator=(double);
    
    int operator!=(const Complex &);
    int operator!=(double);
    friend int operator!=(double, const Complex &);
    
    int operator==(const Complex &);
    int operator==(double);
    friend int operator==(double, const Complex &);
    
    Complex operator+=(const Complex &);
    Complex operator+=(double);
    friend Complex operator+=(double, const Complex &);
    
    Complex operator-=(const Complex &);
    Complex operator-=(double);
    friend Complex operator-=(double, const Complex &);
    
    Complex operator*=(const Complex &);
    Complex operator*=(double);
    friend Complex operator*=(double, const Complex &);
    
    Complex operator/=(const Complex &);
    Complex operator/=(double);
    friend Complex operator/=(double, const Complex &);
};
