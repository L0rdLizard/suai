#include <stdio.h>

// Написать функцию, которая из двух массивов типа int, упорядоченных по убыванию, формирует новый массив двойной длины, упорядоченный по убыванию (слияние).

void merge(int *arr1, int *arr2, int *newmass, int size1, int size2)
{
    int i = 0, j = 0, k = 0, n = (size1+size2);
    while(i<size1 && j<size2)
    {
        if (arr1[i] > arr2[j]) 
            newmass[k++]=arr1[i++];
        else 
            newmass[k++]=arr2[j++]; 
    }
    while(i<size1)
        newmass[k++]=arr1[i++];
    while(j<size2)
        newmass[k++]=arr2[j++]; 
}

int main(int argc, char *argv[])
{
   int array1[] = {122, 64, 13, 3 ,1};
   int array2[] = {80, 69, 24, 3, 2};
   int newmass[10] = {0};
   int size1 = 5, size2 = 5;
   merge(array1, array2, newmass, size1, size2);
   for (int i = 0; i < (size1 + size2); i++)
      printf("%d ", newmass[i]);
   putchar('\n');
   return 0;
}