#include "Operations.h"

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



// advanced operations here

