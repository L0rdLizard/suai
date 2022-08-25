#include <iostream>
#include <ostream>
using namespace std;

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % 10 + 1;
        cout << a << endl;
    }
    return 0;
}