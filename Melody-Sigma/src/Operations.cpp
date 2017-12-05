#include "Operations.h"

Operations::Operations()
{
    //ctor
}

Operations::~Operations()
{
    //dtor
}
double e = 2.71828;
double pi = 3.14159;
// basic operations here

double Operations::add(double a, double b)
{
    return a + b;
}
double Operations::substract(double a, double b){
    return a-b;
}
double Operations::multiply(double a, double b){
    return a*b;
}
double Operations::divide(double a, double b){
    return a/b;
}

int Operations::factorial(int a){
    int result;
    if(a == 0 || a == 1)
        result = 1;
    else{
        result = a*Operations::factorial(a-1);
    }
    return result;
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


