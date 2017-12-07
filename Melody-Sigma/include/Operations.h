#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <Math.h>
#include "Complex.h"

class Operations : public Math
{
    public:
        Operations();
        virtual ~Operations();

        double add(double a, double b);
        Complex add(Complex a, Complex b);
        double substract(double a, double b);
        Complex substract(Complex a, Complex b);
        double multiply(double a, double b);
        Complex multiply(Complex a, Complex b);
        double divide(double a, double b);
        Complex divide(Complex a, Complex b);
        Complex conjugate(Complex c);
        int factorial(int a);
        bool isLeapYear(int year);
        int fibonacci(int n);
        int floor(double n);
        int ceil(double n);
        bool palindrome(int n);
        double log (double base, double n);
        double exponent(double base, int power);

    protected:

    private:
};

#endif // OPERATIONS_H
