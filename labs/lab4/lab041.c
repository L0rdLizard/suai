#include <stdio.h>
//Ввести строку. Вывести слова в алфавитном порядке.
int is_char(int ch)
{
   if (
       (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
       (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
      return 1;
   else
      return 0;
}

// ab
// abc

// a higher then b; return 1
// b higher then a; return -1
// a == b; return 0
int dif(char *str, int w1s, int w1e, int w2s, int w2e)
{
   int sizew1 = w1e - w1s;
   int sizew2 = w2e - w2s;
   int minsize = sizew1 < sizew2 ? sizew1 : sizew2;
   for (size_t i = 0; i < minsize; i++)
   {
      if (str[w1s + i] > str[w2s + i])
         return -1;
      else if (str[w1s + i] < str[w2s + i])
         return 1;
   }
   if (sizew1==sizew2) return 0;
   return sizew1<sizew2 ? 1 : -1;
}
void sorting(char *str, int *startmass, int *endmass, int cur_word)
{
   int i = 0, j = 0;
   for (i = 0; i < cur_word; i++)
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
   char str[101] = {0};
   fgets(str, 101, stdin);
   int startmass[100] = {0}, endmass[100] = {0}, end = -1, start = -1;
   for (size_t i = 0; i < 100; i++)
   {
      startmass[i] = -1;
      endmass[i] = -1;
   }
   int cur_word = 0;
   for (int i = 0; i < 101; i++)
   {
      if (is_char(str[i]) == 1)
      {
         if (start == -1)
         {
            start = i;
            startmass[cur_word] = start;
         }
         if (i == 100)
         {
            end = i;
            endmass[cur_word] = end;
            cur_word++;
            start = -1;
            end = -1;
         }
      }
      else
      {
         if (end == -1 && start != -1)
         {
            end = i - 1;
            endmass[cur_word] = end;
            cur_word++;
            start = -1;
            end = -1;
         }
      }
   }

   sorting(str, );
   return 0;
}