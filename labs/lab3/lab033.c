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
    int i = 0, j = 0, k = 0, cnt = 0, n = (size1+size2);
    int arri[10];

    for (int i = 0; i < size1; i++)
    {
        newmass[cnt] = arr1[i];
        cnt++;
    }

    for (int i = 0; i < size2; i++)
    {
        newmass[cnt] = arr2[i];
        cnt++;
    }
    i = 0;
    for (i = 0; i < 10; i++)
    {
        if (bred(newmass[i]) == 1)
            arri[i] = 1;
        else
            arri[i] = 0;
    }
    i = 0;    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (newmass[j] < newmass[j + 1])
            {
                int tmp = newmass[j];
                newmass[j] = newmass[j + 1];
                newmass[j + 1] = tmp;
            }
        }
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