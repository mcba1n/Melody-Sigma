#include <iostream>
#include <Operations.h>
#include <Command.h>
#include <queue.h>
#include <linkedlist.h>
#include <complex.h>
using namespace std;

int main()
{
    // example command
    string cmd = "4*2+4!";
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
    Command myCommand(cmd);
    cout << "Your command result: " << myCommand.get_result() << endl;
    //queue operations
    return 0;
}
