#include <iostream>
#include <RealCommand.h>
#include <ComplexCommand.h>
#include <queue>
#include <Sorting.h>
using namespace std;

int main()
{   /*
    // example command
    string cmd = "fib(5)+5i";//"(2i-6)/(3i+2)";//"0+-7*10*fibonacci(11)+11i"; //"2!+5 +(e+2*PI)*10 +7^2";
    int mode = COMPLEX;

    if (mode == REAL) {
        RealCommand realCommand(cmd);
        cout << "[REAL]: " << realCommand.get_result() << endl;
    } else if (mode == COMPLEX) {
        ComplexCommand complexCommand(cmd);
        cout << "[COMPLEX]: " << complexCommand.get_result().toString() << endl;
    } else if (mode == POLY) {
    } else if (mode == MATRIX) {
    } else {
        cout << "Invalid command mode" << endl;
    }
    */
    /*Queue testing
    queue<int> QUE;
    //int ele; //element
    int n=1;
    //push operation
    //Through loop
    //do{
    //  cin>>ele;
    // QUE.push(ele);
    // n++;
    //}while(n<=5);
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
    */
    //Sorting test
    int a[10]={40, 60, 10, 20, 45, 70, 80, 90, 25, 15};
    Sort obj;
    obj.InsertionSort(a, 10);
    obj.print(a, 10);
    cout<<"\n";
    int b[10]={40, 60, 10, 20, 45, 70, 80, 90, 25, 15};
    obj.SelectionSort(b, 10);
    obj.print(b, 10);
}
