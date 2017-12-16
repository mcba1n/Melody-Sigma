#include <iostream>
#include <Operations.h>
#include <Command.h>
#include <Complex.h>
#include <Poly.h>
#include <TowerOfHanoi.h>
#include <InsertionSort.h>
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
    string cmd = "2!+5 +(e+2*PI)*10 +7^2";
    Command myCommand(cmd, REAL);
    cout << "Your command result: " << myCommand.get_result() << endl;
    cout<<"\n";
    //polynomial test
    system("cls");
    /*Poly obj;
    obj.first();
    obj.second();
    obj.addpoly();

    TowerOfHanoi obj;
    obj.tower(4, 'A', 'B', 'C');
    */
    InsertionSort obj;
    int arr[]={10, 20, 40, 7, 5, 2, 1, 9, 6, 8};
    int n=10;
    obj.ins_sort(arr, n);
    obj.print(arr, n);
    return 0;
}
