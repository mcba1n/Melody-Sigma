#include <iostream>
#include <Command/ComplexCommand.h>
#include <Command/RealCommand.h>

using namespace std;

int main()
{
    // user command input
    string cmd = "-5i-10.0-100+20+fib(5.0)";//"-7*10*fib(11)+11i"; //"2!+5 +(e+2*PI)*10 +7^2";
    cout << cmd << endl;
    int mode = REAL;

    // evaluation
    if (mode == REAL) {
        RealCommand realCommand(cmd);
        cout << "[REAL]>> " << realCommand.get_result() << endl;
    } else if (mode == COMPLEX) {
        ComplexCommand complexCommand(cmd);
        cout << "[COMPLEX]>> " << complexCommand.get_result().toString() << endl;
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        cout << "Invalid command mode" << endl;
    }
}
