#include <iostream>
#include <Operations.h>

using namespace std;

int main()
{
    // this will be done using class Command later

    Operations std_ops;
    double result;

    result = std_ops.add(10, 20);
    cout << "The result is " << result << endl;

    return 0;
}
