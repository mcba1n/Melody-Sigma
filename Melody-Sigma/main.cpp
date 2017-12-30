#include <iostream>
#include <Operations.h>
#include <RealCommand.h>
#include <Complex.h>
using namespace std;

int main()
{
    Operations ops;
    Complex complex1= Complex(20,-4);
    Complex complex2 = Complex(3,2);
    Complex add = ops.add(complex1,complex2);
    Complex subs = ops.substract(complex1,complex2);
    Complex mult = ops.multiply(complex1,complex2);
    Complex div = ops.divide(complex1,complex2);
    Complex conj = ops.conjugate(complex1);
    add.printComplex();
    subs.printComplex();
    mult.printComplex();
    div.printComplex();
    conj.printComplex();

    // example command
    string cmd = "7*10*add(100, 2)"; //"2!+5 +(e+2*PI)*10 +7^2";
    int mode = REAL;

    if (mode == REAL) {
        RealCommand realCommand(cmd);
        cout << "Your command result: " << realCommand.get_result() << endl;
    } else if (mode == COMPLEX) {
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        std::cout << "Invalid command mode" << std::endl;
    }

    return 0;
}
