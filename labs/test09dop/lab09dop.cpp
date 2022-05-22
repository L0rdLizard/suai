#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void summ(char *arr1, char *arr2, int *result, int n, int size_a, int size_b)
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

    int a = 0;
    int b = 0;
    if (size_a > size_b)
    {
        a = size_a - size_b;
    }
    if (size_b > size_a)
    {
        b = size_b - size_a;
    }
    int razn = max(a, b) + 1;

    for (int i = max(size_a, size_b) - razn; i >= 0; i--)
    {
        result[i + razn] += ((int)arr1[i + a] - 48) + ((int)arr2[i + b] - 48);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    if (a != 0)
    {
        for (int i = ots1; i < a; i++)
        {
            result[i + 1] += ((int)arr1[i] - 48);
        }
    }

    if (b != 0)
    {
        for (int i = 0; i < b; i++)
        {
            result[i + 1] += ((int)arr2[i] - 48);
        }
    }

    for (int i = 0; i < size_a; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < size_b; i++)
        cout << arr2[i];
    cout << " = ";
    int count = 0;
    while (result[count] == 0)
    {
        count++;
    }

    for (int i = count; i < n; i++)
        cout << result[i];
    cout << endl;
}

void raznost(char *arr1, char *arr2, int *result, int n, int size_a, int size_b)
{
    int a = 0;
    int b = 0;
    if (size_a > size_b)
    {
        a = size_a - size_b;
    }

    if (size_b > size_a)
    {
        b = size_b - size_a;
    }

    int razn = max(a, b);

    int flag = 0;
    if (((a == 0) && (b == 0) && (arr1[0] > arr2[0])) || (size_a > size_b))
    {
        for (int i = max(size_a, size_b) - razn - 1; i >= 0; i--)
        {
            int temp_result = ((int)arr1[i + a] - 48) - ((int)arr2[i + b] - 48) - flag;
            flag = 0;
            result[i + razn] += temp_result;
            if (temp_result < 0)
            {
                flag++;
                int temp_result2 = temp_result + 10;
                result[i + razn] = temp_result2;
            }
        }

        if (a != 0)
        {
            for (int i = 0; i < a; i++)
            {
                result[i] += ((int)arr1[i] - 48);
            }
        }

        if (b != 0)
        {
            for (int i = 0; i < b; i++)
            {
                result[i] += ((int)arr2[i] - 48);
            }
        }
        for (int i = 0; i < size_a; i++)
            cout << arr1[i];
        cout << " - ";
        for (int i = 0; i < size_b; i++)
            cout << arr2[i];
        cout << " = ";
        for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
            cout << result[i];
        cout << endl;
    }
    else
    {
        for (int i = max(size_a, size_b) - razn - 1; i >= 0; i--)
        {

            int temp_result = ((int)arr2[i + b] - 48) - ((int)arr1[i + a] - 48) - flag;
            flag = 0;
            result[i + razn] += temp_result;
            if (temp_result < 0)
            {
                flag++;
                int temp_result2 = temp_result + 10;
                result[i + razn] = temp_result2;
            }
        }
        if (a != 0)
        {
            for (int i = 0; i < a; i++)
            {
                result[i] += ((int)arr1[i] - 48);
            }
        }

        if (b != 0)
        {
            for (int i = 0; i < b; i++)
            {
                result[i] += ((int)arr2[i] - 48);
            }
        }
        for (int i = 0; i < size_a; i++)
            cout << arr1[i];
        cout << " - ";
        for (int i = 0; i < size_b; i++)
            cout << arr2[i];
        cout << " = -";
        for (int i = result[0] == 0 ? 1 : 0; i < n; i++)
            cout << result[i];
        cout << endl;
    }
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

    int n = size_a + size_b + 2;
    for (int i = size_a - 1; i >= ots1; i--)
        for (int j = size_b - 1; j >= ots2; j--)
        {
            result[i + j + 1] += ((int)arr1[i] - 48) * ((int)arr2[j] - 48);
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