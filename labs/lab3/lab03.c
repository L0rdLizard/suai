#include <stdio.h>

// Написать функцию, которая из двух массивов типа int, упорядоченных по убыванию, формирует новый массив двойной длины, упорядоченный по убыванию (слияние).

void merge(int *arr1, int *arr2, int *newmass, int size1, int size2)
{

   int i = 0, j = 0, cnt = 0, n = (size1+size2);
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
   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - i - 1; j++)
      {
         if (newmass[j] > newmass[j + 1])
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
   //privet
   //dorov
   // ты меня слышишь?
   //а должен?
   //там и такая фича есть
   //там чат есть нормальный
   //gde
   //слева live share и там чат в сеансе
   int array1[5] = {1, 3, 13, 64, 122};
   int array2[5] = {2, 3, 24, 69, 420};
   int newmass[10] = {0};
   int size1 = 5, size2 = 5;
   merge(array1, array2, &newmass, size1, size2);
   for (int i = 0; i < (size1 + size2); i++)
      printf("%d ", newmass[i]);
   printf("\n");
   return 0;
}