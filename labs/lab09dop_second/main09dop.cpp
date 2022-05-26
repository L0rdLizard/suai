
#include "lab09dop.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // const int size1 = 6;
    // const int size2 = 6;
    // char array1[size1] = {'5', '3', '7', '1', '9', '3'};
    // char array2[size2] = {'1', '2', '3', '4', '5', '6'};
    // char arr1[size1] = {0};
    // char arr2[size2] = {0};
    // for (int i = 0; i < size1; i++) arr1[i] = array1[size1 - i - 1];
    // for (int i = 0; i < size2; i++) arr2[i] = array2[size1 - i - 1];
    // for (int i = 0; i < size2; i++) cout << arr1; 
    // char arr1[size1] = {'3', '9', '1', '7', '3', '5'};
    // char arr2[size2] = {'6', '5', '4', '3', '2', '1'};
    char arr1[6] = {'5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
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
    count_result3 = sizeof(arr1) + sizeof(arr2) + 2;
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
