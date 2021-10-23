#include <stdio.h>

// Написать функцию, которая из двух массивов типа int, упорядоченных по убыванию, формирует новый массив двойной длины, упорядоченный по убыванию (слияние).

int merge(int* arr1, int* arr2){
   int i=0, j=0;

}

int main (int argc, char *argv[]) {
   //privet
   //dorov
   // ты меня слышишь?
   //а должен?
   //там и такая фича есть
   //там чат есть нормальный
   //gde
   //слева live share и там чат в сеансе
   int array1[101] = {0}, array2[101] = {0}, array3[202] = {0};
   int count1 = 0, count2 = 0;
   fgets(array1, 101, stdin);
   fgets(array2, 101, stdin);
   for (int i = 0; i <= 101; i++){
      if (array1[i] != 0) count1++;
   }
   for (int i = 0; i <= 101; i++){
      if (array2[i] != 0) count2++;
   }
   int merge(array1, array2);
   for (int i = 0; i <= (count1+count2); i++)
                    printf("%d", array3[i]);
                printf("\n");
   return 0;
}