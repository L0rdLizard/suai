
#include "lab09dop.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[7] = {'-', '5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    // char arr1[6] = {'5', '1', '2', '1', '4', '3'};
    // char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    int *result1 = (int *)malloc(sizeof(int));
    int *result2 = (int *)malloc(sizeof(int));
    int *result3 = (int *)malloc(sizeof(int));

    int count_result1 = 0;
    count_result1 = max(sizeof(arr1), sizeof(arr2)) + 1;
    result1 = (int *)realloc(result1, count_result1 * sizeof(int));
    for (int i = 0; i < count_result1; i++)
    {
        result1[i] = 0;
    }

    int count_result2 = 0;
    count_result2 = max(sizeof(arr1), sizeof(arr2));
    result2 = (int *)realloc(result2, count_result2 * sizeof(int));
    for (int i = 0; i < count_result2; i++)
    {
        result2[i] = 0;
    }

    int count_result3 = 0;
    count_result3 = sizeof(arr1) + sizeof(arr2) + 1;
    result3 = (int *)realloc(result3, count_result3 * sizeof(int));
    for (int i = 0; i < count_result3; i++)
    {
        result3[i] = 0;
    }

    summ(arr1, arr2, result1, count_result1, sizeof(arr1), sizeof(arr2));
    raznost(arr1, arr2, result2, count_result2, sizeof(arr1), sizeof(arr2));
    umn(arr1, arr2, result3, sizeof(arr1), sizeof(arr2));
    return 0;
}