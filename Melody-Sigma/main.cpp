#include <iostream>
/*#include <Command/ComplexCommand.h>
#include <Command/RealCommand.h>
#include <Algorithm/Sorting.h>
#include <Algorithm/TowerOfHanoi.h>
#include <queue>
#include <LinkedList.h>
#include <Records/Records.h>*/
#include <Poly.h>
using namespace std;

int main()
{   /*
    // example command
    string cmd = "fib(5)+5i";//"(2i-6)/(3i+2)";//"0+-7*10*fibonacci(11)+11i"; //"2!+5 +(e+2*PI)*10 +7^2";
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

    //grouped files test
    //Sorting test
    int a[10]={40, 60, 10, 20, 45, 70, 80, 90, 25, 15};
    Sort obj;
    obj.InsertionSort(a, 10);
    obj.print(a, 10);
    cout<<"\n";
    int b[10]={40, 60, 10, 20, 45, 70, 80, 90, 25, 15};
    obj.SelectionSort(b, 10);
    obj.print(b, 10);
    //Tower of Hanoi test
    TowerOfHanoi obj2;
    obj2.tower(4, 'A', 'B', 'C');
}

    //Queue testing
    queue<int> QUE;
    //int ele; //element
    //push operation
    //Through loop
    /*do{
      cin>>ele;
      QUE.push(ele);
      n++;
    }while(n<=5);
    //manually pushing each element
    QUE.push(10);
    QUE.push(20);
    QUE.push(30);
    QUE.push(40);
    QUE.push(50);
    //traverse and pop
    while(!QUE.empty()){
        cout<<QUE.front()<<"  ";
        QUE.pop();
    }

    LinkedList obj;
    obj.insertend(10);
    obj.insertend(20);
    obj.insertend(60);
    obj.insertend(100);
    obj.insertend(110);
    obj.insertend(150);
    obj.traverse();
    cout<<"\n";
    obj.insertloc(55, 1);
    obj.insertloc(105, 5);
    obj.traverse();
    cout<<"\n";
    obj.deleteloc(1);
    cout<<"\n";
    obj.traverse();
    cout<<"\n";
    obj.deleteloc(6);
    cout<<"\n";
    obj.traverse();

    Record obj2;
    obj2.handler();
    */
    Poly obj;
    obj.first();
    obj.second();
    obj.subpoly();
}
