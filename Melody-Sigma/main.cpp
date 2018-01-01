#include <iostream>
#include <RealCommand.h>
#include <ComplexCommand.h>

using namespace std;

int main()
{
    // example command
    string cmd = "(2i-6)/(3i+2)";//"0+-7*10*fibonacci(11)+11i"; //"2!+5 +(e+2*PI)*10 +7^2";
    int mode = REAL;

    if (mode == REAL) {
        RealCommand realCommand(cmd);
        cout << "REAL mode, result: " << realCommand.get_result() << endl;
    } else if (mode == COMPLEX) {
        ComplexCommand complexCommand(cmd);
        cout << "COMPLEX mode, result: " << "[convert Complex result to string]" << endl;
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        cout << "Invalid command mode" << endl;
    }
}
