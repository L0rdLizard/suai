#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    long long n = 1, i = 1, k = 1;
    cin >> n;
    unsigned long long c[66] = {0};
    c[0] = 1;
    for (k = 1; k <= n; k++)
    {
        for (i = k; i >= 1; i--)
        {
            c[i] = c[i - 1] + c[i];
        }
    }
    for (i = 0; i <= n; i++)
    {
        cout << c[i] << "  ";
    }
}