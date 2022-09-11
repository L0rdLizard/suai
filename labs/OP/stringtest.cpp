#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int a[3] = {1, 2, 3};
    int b[6] = {1, 2, 3};
    // int c = memcmp(a, b, sizeof(int)* 3);
    // memcpy(b, a, sizeof(int)*3);
    strcat(b, a);
    cout << b[2] << endl;
    return 0;
}