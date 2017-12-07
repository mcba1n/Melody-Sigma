#include <iostream>
#include <Operations.h>
#include <Command.h>
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
    string cmd = "PI*(4*2+2!)";
    Command myCommand(cmd, REAL);
    cout << "Your command result: " << myCommand.get_result() << endl;

    return 0;
}
