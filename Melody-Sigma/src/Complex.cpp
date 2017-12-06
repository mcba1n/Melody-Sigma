#include "Complex.h"
#include <iostream>

Complex::Complex()
{
    //ctor
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
void Complex::printComplex(){
    if(this->getImag() >= 0){
        std::cout << getReal() << "+" << getImag() << "i" << std::endl;
    }
    else
        std::cout << getReal() << getImag() << "i" << std::endl;
}
