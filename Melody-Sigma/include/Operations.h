#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <Math.h>


class Operations : public Math
{
    public:
        Operations();
        virtual ~Operations();

        double add(double a, double b);
        double substract(double a, double b);
        double multiply(double a, double b);
        double divide(double a, double b);
        int factorial(int a);
        bool isLeapYear(int year);

    protected:

    private:
};

#endif // OPERATIONS_H
