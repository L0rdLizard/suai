#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void summ(char *arr1, char *arr2, int *result, int n, int size_a, int size_b)
{

}

void raznost(char *arr1, char *arr2, int *result, int n, int size_a, int size_b)
{
    
}

void umn(char *arr1, char *arr2, int *result, int size_a, int size_b)
{
    int ots = 0;
    int ots1 = 0;
    int ots2 = 0;
    int minus = 0;

    if (arr1[0] == '-' || arr2[0] == '-')
        ots++;
    if (arr1[0] == '-')
        ots1 = 1;
    if (arr2[0] == '-')
        ots2 = 1;

    if (arr1[0] == '-' && arr2[0] == '-')
        minus++;

    int n = size_a + size_b + 1;
    for (int i = size_a - 1; i >= ots1; i--)
        for (int j = size_b - 1; j >= ots2; j--)
        {
            result[i + j] += ((int)arr1[i] - 48) * ((int)arr2[j] - 48);
            int temp_result = ((int)arr1[i] - 48) * ((int)arr2[j] - 48);
        }

    for (int i = n - 1; i >= 0; i--)
    {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    for (int i = 0; i < size_a; i++)
        cout << arr1[i];

    cout << " * ";

    for (int i = 0; i < size_b; i++)
        cout << arr2[i];

    if (ots == 1 && minus == 0)
        cout << " = -";
    else
        cout << " = ";

    int count = 0;
    while (result[count] == 0)
    {
        count++;
    }

    for (int i = count; i < n - 2; i++)
        cout << result[i];
    cout << endl;
}