#include <iostream>
#include <Operations.h>
#include <Command.h>
#include <queue.h>

using namespace std;

int main()
{
    // example command
    string cmd = "5*(4+3*2)+1";

    Command myCommand(cmd);
    cout << "Your command result: " << myCommand.get_result() << endl;
    //queue operations
    queue1 obj;
    obj.insertion(107);
    obj.insertion(810);
    obj.insertion(20);
    obj.insertion(120);
    obj.insertion(120);
    obj.traverse();
    obj.deletion();
    obj.traverse();
    return 0;
}
