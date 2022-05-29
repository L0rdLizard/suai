#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void raznost(char *arr1, char *arr2, int *result, int n, int size_a, int size_b, int znak);

void summ(char *arr1, char *arr2, int *result, int n, int size_a, int size_b, int znak)
{
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
    }
    int n2 = n - 1;
    int ots = 0;
    int ots1 = 0;
    int ots2 = 0;
    int minus = 0;
    int a = 0;
    int b = 0;
    if (arr1[0] == '-' || arr2[0] == '-')
        ots++;
    if (arr1[0] == '-')
        ots1 = 1;
    if (arr2[0] == '-')
        ots2 = 1;
    if (arr1[0] == '-' && arr2[0] == '-')
        minus = 1;

    if (size_a > size_b)
    {
        a = size_a - size_b;
    }
    if (size_b > size_a)
    {
        b = size_b - size_a;
    }
    int razn = max(a, b) + 1;

    if (minus == 0 && (ots1 == 1 || ots2 == 1) && znak == 0)
    {
        raznost(arr1, arr2, result, n2, size_a, size_b, 1);
    }
    else
    {
        for (int i = max((size_a - ots1), (size_b - ots2)) - razn + 1; i >= 0; i--)
        {
            if (arr1[i + a] == '-' || arr2[i + b] == '-')
                continue;
            result[i + razn] += ((int)arr1[i + a] - 48) + ((int)arr2[i + b] - 48);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }

        if (size_a - ots1 > size_b - ots2)
        {
            a = (size_a - ots1) - (size_b - ots2);
        }

        if (size_b - ots2 > size_a - ots1)
        {
            b = (size_b - ots2) - (size_a - ots1);
        }

        if (a != 0)
        {
            for (int i = a - ots2; i >= ots1; i--)
            {
                if ((size_a - ots1) == (size_b - ots2))
                    break;
                result[i+1] += ((int)arr1[i] - 48);
            }
        }

        if (b != 0)
        {
            for (int i = b - ots1; i >= ots2; i--)
            {
                if ((size_a - ots1) == (size_b - ots2))
                    break;
                result[i+1] += ((int)arr2[i] - 48);
            }
        }
        // if (a != 0)
        // {
        //     for (int i = ots1; i < a + ots2; i++)
        //     {
        //         result[i + 1] += ((int)arr1[i] - 48);
        //     }
        // }

        // if (b != 0)
        // {
        //     for (int i = ots2; i < b + ots1; i++)
        //     {
        //         result[i + 1] += ((int)arr2[i] - 48);
        //     }
        // }

        for (int i = 0; i < size_a; i++)
            cout << arr1[i];
        // cout << " + ";
        // for (int i = 0; i < size_b; i++)
        //     cout << arr2[i];
        // if (minus == 1)
        //     cout << " = -";
        // else
        //     cout << " = ";
        // int count = 0;
        // while (result[count] == 0)
        // {
        //     count++;
        // }

        // for (int i = count; i < n; i++)
        //     cout << result[i];
        // cout << endl;

        if (znak == 1)
            cout << " - ";
        else
            cout << " + ";
        for (int i = 0; i < size_b; i++)
            cout << arr2[i];
        if (znak == 1 && arr1[0] == '-')
            cout << " = -";
        else
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
}

void raznost(char *arr1, char *arr2, int *result2, int n, int size_a, int size_b, int znak)
{
    int n3 = n + 1;
    int ots = 0;
    int ots1 = 0;
    int ots2 = 0;
    int minus = 0;
    int a = 0;
    int b = 0;
    if (arr1[0] == '-' || arr2[0] == '-')
        ots++;
    if (arr1[0] == '-')
        ots1 = 1;
    if (arr2[0] == '-')
        ots2 = 1;
    if (arr1[0] == '-' && arr2[0] == '-')
        minus = 1;

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
    if (minus == 0 && (ots1 == 1 || ots2 == 1) && znak == 0)
    {
        summ(arr1, arr2, result2, n3, size_a, size_b, 1);
    }
    else
    {
        // if (((a == 0) && (b == 0) && (arr1[ots1] > arr2[ots2])) || (size_a - ots1 > size_b - ots2))
        if (((size_a - ots1 == size_b - ots2) && (arr1[ots1] > arr2[ots2])) || (size_a - ots1 > size_b - ots2))
        {
            for (int i = max((size_a - ots1), (size_b - ots2)) - razn; i >= 0; i--)
            {
                if (arr1[i + a] == '-' || arr2[i + b] == '-')
                    continue;
                int temp_result = ((int)arr1[i + a] - 48) - ((int)arr2[i + b] - 48) - flag;
                flag = 0;
                result2[i + razn] += temp_result;
                if (temp_result < 0)
                {
                    flag++;
                    // result[i + razn - 1] = -1;
                    int temp_result2 = temp_result + 10;
                    result2[i + razn] = temp_result2;
                }
            }

            // if (a + ots2 != 0)
            // {
            //     for (int i = ots1; i < a + ots2; i++)
            //     {
            //         result[i] += ((int)arr1[i] - 48);
            //         flag = 0;
            //     }
            // }

            // if (b + ots1 != 0)
            // {
            //     for (int i = ots2; i < b + ots1; i++)
            //     {
            //         result[i] += ((int)arr2[i] - 48);
            //         flag = 0;
            //     }
            // }
            if (size_a - ots1 > size_b - ots2)
            {
                a = (size_a - ots1) - (size_b - ots2);
            }

            if (size_b - ots2 > size_a - ots1)
            {
                b = (size_b - ots2) - (size_a - ots1);
            }

            if (a != 0)
            {
                for (int i = a - ots2; i >= ots1; i--)
                {
                    if ((size_a - ots1) == (size_b - ots2))
                        break;
                    result2[i] += ((int)arr1[i] - 48) - flag;
                    flag = 0;
                }
            }

            if (b != 0)
            {
                for (int i = b - ots1; i >= ots2; i--)
                {
                    if ((size_a - ots1) == (size_b - ots2))
                        break;
                    result2[i] += ((int)arr2[i] - 48) - flag;
                    flag = 0;
                }
            }
            for (int i = 0; i < size_a; i++)
                cout << arr1[i];
            if (znak == 1)
                cout << " + ";
            else
                cout << " - ";
            for (int i = 0; i < size_b; i++)
                cout << arr2[i];
            if (znak == 1 && arr1[0] == '-')
                cout << " = -";
            else
                cout << " = ";
            for (int i = result2[0] == 0 ? 1 : 0; i < n; i++)
                cout << result2[i];
            cout << endl;
        }
        else
        {
            for (int i = max(size_a, size_b) - razn - 1; i >= 0; i--)
            {
                if (arr1[i + a] == '-' || arr2[i + b] == '-')
                    continue;
                int temp_result = ((int)arr2[i + b] - 48) - ((int)arr1[i + a] - 48) - flag;
                flag = 0;
                result2[i + razn] += temp_result;
                if (temp_result < 0)
                {
                    flag++;
                    // result[i + razn - 1] = -1;
                    int temp_result2 = temp_result + 10;
                    result2[i + razn] = temp_result2;
                }
            }
            // if (a != 0)
            // {
            //     for (int i = 0; i < a; i++)
            //     {
            //         result[i] += ((int)arr1[i] - 48);
            //     }
            // }

            // if (b != 0)
            // {
            //     for (int i = 0; i < b; i++)
            //     {
            //         result[i] += ((int)arr2[i] - 48);
            //     }
            // }
            if (size_a - ots1 > size_b - ots2)
            {
                a = (size_a - ots1) - (size_b - ots2);
            }

            if (size_b - ots2 > size_a - ots1)
            {
                b = (size_b - ots2) - (size_a - ots1);
            }

            if (a != 0)
            {
                for (int i = a - ots2; i >= ots1; i--)
                {
                    result2[i] += ((int)arr1[i] - 48) - flag;
                    flag = 0;
                }
            }

            if (b != 0)
            {
                for (int i = b - ots1; i >= ots2; i--)
                {
                    result2[i] += ((int)arr2[i] - 48) - flag;
                    flag = 0;
                }
            }
            for (int i = 0; i < size_a; i++)
                cout << arr1[i];
            if (znak == 1)
                cout << " + ";
            else
                cout << " - ";
            for (int i = 0; i < size_b; i++)
                cout << arr2[i];
            if (znak == 1 && arr2[0] == '-')
                cout << " = -";
            else
                cout << " = ";
            for (int i = result2[0] == 0 ? 1 : 0; i < n; i++)
                cout << result2[i];
            cout << endl;
        }
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