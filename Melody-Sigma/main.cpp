#include <iostream>
#include <Operations.h>
#include <Command.h>

using namespace std;

int main()
{
    // example command
    string cmd = "5*(4+3*2)+1";

    Command myCommand(cmd);
    cout << "Your command result: " << myCommand.get_result() << endl;

    return 0;
}
