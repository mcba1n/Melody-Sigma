#include "Operations.h"
#include "Complex.h"

Operations::Operations()
{
    //ctor
}

Operations::~Operations()
{
    //dtor
}

// basic operations here

double Operations::add(double a, double b)
{
    return a + b;
}

Complex Operations::add(Complex a, Complex b){
    Complex result;
    result.setReal(a.getReal()+b.getReal());
    result.setImag(a.getImag()+b.getImag());
    return result;
}

double Operations::substract(double a, double b){
    return a-b;
}
Complex Operations::substract(Complex a, Complex b){
    Complex result;
    result.setReal(a.getReal()-b.getReal());
    result.setImag(a.getImag()-b.getImag());
    return result;
}

double Operations::multiply(double a, double b){
    return a*b;
}

Complex Operations::multiply(Complex a, Complex b){
    Complex result;
    double real = a.getReal()*b.getReal()-a.getImag()*b.getImag();
    double imag = a.getReal()*b.getImag()+a.getImag()*b.getReal();
    result.setReal(real);
    result.setImag(imag);
    return result;
}

double Operations::divide(double a, double b){
    return a/b;
}

Complex Operations::divide(Complex a, Complex b){
    Complex result;
    Complex bconjugate = conjugate(b);
    double denominator = multiply(b,bconjugate).getReal();
    Complex numerator = multiply(a,bconjugate);
    numerator.printComplex();
    result.setReal(numerator.getReal()/denominator);
    result.setImag(numerator.getImag()/denominator);
    return result;
}

Complex Operations::conjugate(Complex c){
    Complex result;
    result.setReal(c.getReal());
    result.setImag(-c.getImag());
    return result;
}

int Operations::factorial(int a){
    if(a == 0 || a == 1) return 1;
    else return a*factorial(a-1);
}

int Operations::floor(double a){
    return a/1;
}

int Operations::ceil(double a){
   int result;
   if(floor(a) == a) //check if integer
        result = a;
    else
        result = floor(a)+1;
    return result;
}

double Operations::exponent(double base, int power) {
    if (power == 0) {
        return 1;
    } else if (power == 1) {
        return base;
    } else {
        return base*exponent(base, power-1);
    }
}

double Operations::log(double base, double n){
    return 0;
}

// advanced operations here

bool Operations::isLeapYear(int year){
    bool result;
    if(year % 4 == 0){ //first condition
        if(year % 100 == 0 && year % 400 != 0) //multiples of 100 are not leap years except if they are multiples of 400
            result = false;
        else
            result = true;
    }
    else //not multiple of 4, therefore not a leap year
        result = false;

    return result;
    }

int Operations::fibonacci(int n){
    int result;
    if(n == 1 || n == 2)
        result = 1;
    else
        result = fibonacci(n-1)+fibonacci(n-2);
    return result;
}

bool Operations::palindrome(int n){
    return 0;
}


