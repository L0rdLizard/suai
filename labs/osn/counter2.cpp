#include <stdio.h>
#include <iostream>
using namespace std;
char arr[16] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
};

int main()
{
    int w = 0, z = 0;
    z = 241;
    while (z > 0)
        {
            w = w + arr[z & 15];
            cout << (z & 15) << endl;
            z = z >> 4;
        }
    cout << w << endl;
    return 0;   
}