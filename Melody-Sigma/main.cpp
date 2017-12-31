#include <iostream>
#include <RealCommand.h>

using namespace std;

int main()
{
    // example command
    string cmd = "7*10*fibonacci(11)"; //"2!+5 +(e+2*PI)*10 +7^2";
    int mode = REAL;

    if (mode == REAL) {
        RealCommand realCommand(cmd);
        cout << "Your command result: " << realCommand.get_result() << endl;
    } else if (mode == COMPLEX) {
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        cout << "Invalid command mode" << endl;
    }
}
