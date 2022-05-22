#include <stdio.h>
#include <iostream>
using namespace std;

void summ(char *arr1, char *arr2, int *result, int n)
{
    for (int i = n-2; i >= 0; i--)
    {
        int temp_result = ((int)arr1[i] - 48) + ((int)arr2[i] - 48);
        result[i + 1] += temp_result;
        if (temp_result > 9)
        {
            int temp_result2 = (temp_result - (temp_result % 10)) / 10;
            result[i] = temp_result2;
            result[i + 1] %= 10;
        }
    }
    for (int i = 0; i < n-1; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < n-1; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
        cout << result[i];
    cout << endl;
}

