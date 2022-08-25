#include <iostream>
#include <ostream>
using namespace std;

int main()
{
    int* ptr;
    int var = 6;
    ptr = &var;
    cout << *ptr << endl;

    int& ref = var;
    ref++;
    var++;
    cout << ref << endl;
    cout << var << endl;
    return 0;
}