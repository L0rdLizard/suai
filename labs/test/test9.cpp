#include <iostream>
#include <math.h>
using namespace std;
void summ(int *arr1, int *arr2, int *result)
{
    for (int i = 5; i >= 0; i--)
    {
        result[i + 1] += arr1[i] + arr2[i];
        if (result[i + 1] > 9)
        {
            result[i] = (result[i + 1] - result[i + 1] % 10) / 10;
            result[i + 1] %= 10;
        }
    }
}

int main()
{
    // int arr1[6] = {1, 2, 3, 4, 5, 6},
    //     arr2[6] = {5, 3, 7, 1, 9, 3},
    //     result[7] = {0, 0, 0, 0, 0, 0, 0};
    char arr1[6] = {'1', '2', '3', '4', '5', '6'},
         arr2[6] = {'5', '3', '7', '1', '9', '3'},
         result[7] = {'0', '0', '0', '0', '0', '0', '0'};
    // char a[] = {'3'}, b[] = {'2'};
    // char a[] = {'3'}, b[] = {'2'};
    // int c = 0;
    // c = atoi(a) + atoi(b);
    // cout << c;
    char a = '2';
    int num = a - 48;
    cout << num;

    for (int i = 5; i >= 0; i--)
    {
        // char a1 = arr1[i];
        // char a2 = arr2[i];
        char a1[] = {arr1[i]};
        char a2[] = {arr2[i]};
        result[i + 1] += atoi(a1) + atoi(a2);
        if (result[i + 1] > 9)
        {
            result[i] = (result[i + 1] - result[i + 1] % 10) / 10;
            result[i + 1] %= 10;
        }
    }

    // summ(arr1, arr2, result);
    // for (int i = 0; i < 6; i++)
    //     cout << arr1[i];
    // cout << " + ";
    // for (int i = 0; i < 6; i++)
    //     cout << arr2[i];
    // cout << " = ";
    // for (int i = result[0] == 0 ? 1 : 0; i < 7; i++)
    //     cout << result[i];
    // cout << endl;
    // system("pause");
    return 0;
}