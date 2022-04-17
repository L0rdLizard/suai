//Написать функции для поразрядного сложения и вычитания длинных целых чисел, представленных строками символов, и тестирующую программу к ним.
#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[6] = {'1', '2', '3', '4', '5', '6'};
    char arr2[6] = {'5', '3', '7', '1', '9', '3'};
    int result[7] = {0};
    summ(arr1, arr2, result);
    for (int i = 0; i < 6; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < 6; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < 7; i++)
        cout << result[i];
    cout << endl;
    return 0;
}