#include <stdio.h>
#include <iostream>
using namespace std;

void summ(char *arr1, char *arr2, int *result, int n)
{
    for (int i = n - 2; i >= 0; i--)
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
    for (int i = 0; i < n - 1; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < n - 1; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
        cout << result[i];
    cout << endl;
}

void razn(char *arr1, char *arr2, int *result, int n)
{
    int flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp_result = ((int)arr1[i] - 48) - ((int)arr2[i] - 48) - flag;
        flag = 0;
        result[i] += temp_result;
        if (temp_result < 0)
        {
            flag++;
            int temp_result2 = ((int)arr1[i] - 48) - ((int)arr2[i] - 48) + 10;
            result[i] = temp_result2;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr1[i];
    cout << " - ";
    for (int i = 0; i < n; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
        cout << result[i];
    cout << endl;
}

void umn(char *arr1, char *arr2, int *result, int size_a, int size_b)
{
    int n = size_a + size_b + 1;
    for (int i = 0; i < size_a; i++)
        for (int j = 0; j < size_b; j++)
        {
            result[i + j - 1] += ((int)arr1[i] - 48) * ((int)arr2[j] - 48);
            cout << result[i + j - 1];
        }
    for (int i = 0; i < n; i++)
    {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    while (result[n] == 0)
        n--;

    for (int i = 0; i < size_a; i++)
        cout << arr1[i];
    cout << " * ";
    for (int i = 0; i < size_b; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
        cout << result[i];
    cout << endl;
}