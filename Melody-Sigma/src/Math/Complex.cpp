<<<<<<< HEAD:Melody-Sigma/src/Math/Complex.cpp
#include "Math/Complex.h"
=======
#include "Complex.h"
#include <stdio.h>
>>>>>>> 9df04d8e23226b94463c3078047ad44738918fd6:Melody-Sigma/src/Complex.cpp

Complex::Complex()
{
    //ctor
    real = NULL;
    imaginary = NULL;
}

Complex::Complex(double r, double i){
    real = r;
    imaginary = i;
}

Complex::~Complex()
{
    //dtor
}

void Complex::setReal(double r){
    real = r;
}

void Complex::setImag(double i){
    imaginary = i;
}

double Complex::getReal(){
    return real;
}

double Complex::getImag(){
    return imaginary;
}

std::string Complex::toString(){
    // append real part
    std::string res;
    if (real < 0) res.push_back('-');
    char buf[100];
    sprintf(buf, "%f", real);
    res = buf;

    // append imag part
    sprintf(buf, "%f", imaginary);
    if (imaginary >= 0) res.push_back('+');
    res.append(buf);
    res.push_back('i');

    return res;
}
