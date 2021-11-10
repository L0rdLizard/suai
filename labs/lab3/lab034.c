#include <stdio.h>

// Написать функцию, которая из двух массивов типа int, упорядоченных по убыванию, формирует новый массив двойной длины, упорядоченный по убыванию (слияние).
int bred(int a)
{
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}
void merge(int *arr1, int *arr2, int *newmass, int size1, int size2)
{
    int i = 0, j = 0, k = 0;
    int arri[5];
    int arrj[5];
    for (i = 0; i < 5; i++)
    {
        if (bred(arr1[i]) == 1)
            arri[i] = 1;
        else
            arri[i] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        if (bred(arr2[i]) == 1)
            arrj[i] = 1;
        else
            arrj[i] = 0;
    }
    i = 0;
    while(i<size1 && j<size2)
    {
        
    }
}

int main(int argc, char *argv[])
{
    int array1[] = {122, 64, 13, 3 ,1};
    int array2[] = {80, 69, 24, 3, 2};
    int newmass[10] = {0};
    int size1 = 5, size2 = 5;
    merge(array1, array2, newmass, size1, size2);
    for (int i = 0; i < 10; i++)
        printf("%d ", newmass[i]);
    putchar('\n');
    return 0;
}