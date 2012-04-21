#include <cstdlib>
#include <iostream>
#include <cmath>
#define EPS 0.001
using namespace std;

class ComplexT {
private:
    double mod, arg;
public:
    ComplexT();
    ComplexT(double);
    ComplexT(double, double);
    
    void print();
    void setComplex(double, double);
    void setReal(double); 
    void setImage(double);
    
    double getReal() const;
    double getImage() const;
    double getArg() const;
    double getMod() const;
    
    ComplexT operator+(const ComplexT &);
    ComplexT operator+(double);
    friend ComplexT operator+(double, const ComplexT &);
    
    ComplexT operator-(const ComplexT &);
    ComplexT operator-(double);
    friend ComplexT operator-(double, const ComplexT &);
    
    ComplexT operator*(const ComplexT &);
    ComplexT operator*(double);
    friend ComplexT operator*(double, const ComplexT &);
    
    ComplexT operator/(const ComplexT &);
    ComplexT operator/(double);
    friend ComplexT operator/(double, const ComplexT &);
    
    ComplexT operator=(const ComplexT);
    ComplexT operator=(double);
    
    int operator!=(const ComplexT &);
    int operator!=(double);
    friend int operator!=(double, const ComplexT &);
    
    int operator==(const ComplexT &);
    int operator==(double);
    friend int operator==(double, const ComplexT &);
    
    ComplexT operator+=(const ComplexT &);
    ComplexT operator+=(double);
    friend ComplexT operator+=(double, const ComplexT &);
    
    ComplexT operator-=(const ComplexT &);
    ComplexT operator-=(double);
    friend ComplexT operator-=(double, const ComplexT &);
    
    ComplexT operator*=(const ComplexT &);
    ComplexT operator*=(double);
    friend ComplexT operator*=(double, const ComplexT &);
    
    ComplexT operator/=(const ComplexT &);
    ComplexT operator/=(double);
    friend ComplexT operator/=(double, const ComplexT &);
};
