#include <iostream>
#include <Operations.h>
#include <Command.h>
#include <queue.h>
#include <linkedlist.h>
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
    //linked list testing
    cout<<"\n";
    linkedlist obj2;
    obj2.insertbeg(90);
    obj2.insertend(100);
    obj2.insertbeg(16);
    obj2.insertend(10);
    //obj2.insertloc(80, 2);
    obj2.insertend(800);
    obj2.traverse();
    obj2.deletebeg();
    obj2.traverse();
    obj2.deleteend();
    obj2.traverse();
    return 0;
}
