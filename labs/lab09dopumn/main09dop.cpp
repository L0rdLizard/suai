
#include "lab09dop.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char arr1[7] = {'1', '5', '3', '7', '1', '9', '3'};
    char arr2[6] = {'1', '2', '3', '4', '5', '6'};
    int *result = (int *)malloc(sizeof(int));


    int count_result = 0;
    count_result = sizeof(arr1) + sizeof(arr2) + 1;
    result = (int *)realloc(result, count_result * sizeof(int));
    for (int i = 0; i < count_result; i++)
    {
        result[i] = 0;
    }

    umn(arr1, arr2, result, sizeof(arr1), sizeof(arr2));
    return 0;
}