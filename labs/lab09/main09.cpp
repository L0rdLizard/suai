//Написать функции для поразрядного сложения и вычитания длинных целых чисел, представленных строками символов, и тестирующую программу к ним.

// 
#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[6] = {'5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    int *result1 = (int *) malloc(sizeof(int));
    int *result2 = (int *) malloc(sizeof(int));



    int count_result1 = 0;
    count_result1 = max(sizeof(arr1), sizeof(arr2)) + 1;
    result1 = (int *) realloc(result1, count_result1 * sizeof(int));
    for (int i = 0; i < count_result1; i++)
    {
        result1[i] = 0;
    }


    int count_result2 = 0;
    count_result2 = max(sizeof(arr1), sizeof(arr2));
    result2 = (int *) realloc(result2, count_result2 * sizeof(int));
    for (int i = 0; i < count_result2; i++)
    {
        result2[i] = 0;
    }


    summ(arr1, arr2, result1, count_result1);
    razn(arr1, arr2, result2, count_result2);
    return 0;
}