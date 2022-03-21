#include <stdio.h>

char count_ones(unsigned long long n)
{
   char w = 0; 
   int z = n;
   while (z > 0)
   {
      w = w + (z & 1);
      z = z >> 1;
   }
   return w;
}

int main()
{
   char arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
   for (int i = 0; i < 8; i++)
   {
      printf("%d\n", count_ones(arr[i]));
   }
   return 0;
}