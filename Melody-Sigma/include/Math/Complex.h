#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <cstdio>

class Complex
{
    public:
        Complex();
        Complex(double r, double i);
        virtual ~Complex();
        void setReal(double real);
        void setImag(double imag);
        double getReal();
        double getImag();
        void printComplex();
        std::string toString();

    protected:

    private:
        double imaginary;
        double real;
};

#endif // COMPLEX_H
