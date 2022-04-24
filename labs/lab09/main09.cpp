//Написать функции для поразрядного сложения и вычитания длинных целых чисел, представленных строками символов, и тестирующую программу к ним.
#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[6] = {'5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    int result1[7] = {0};
    int result2[6] = {0};
    // int count_result = max(sizeof(arr1), sizeof(arr2)) + 1;
    // int *result = new int[count_result];
    summ(arr1, arr2, result1);
    razn(arr1, arr2, result2);
    return 0;
}