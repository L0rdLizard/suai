#include <stdio.h>
#include <stdlib.h>

// Ввести строку и слово. Вывести порядковые номера слов в строке, совпадающих с введенным словом.

int is_char(int ch)
{
   if (
       (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
       (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
      return 1;
   else
      return 0;
}

int is_same(char *str, char *word, int startw, int endw, int cur_word, int count)
{
   int size = endw - startw + 1;
   int flag = 1;
   if (size == count)
   {
      for (int i = 0; i < count; i++)
      {
         if (str[startw + i] != word[i])
            flag = 0;
      }
   }
   else
      flag = 0;
   return flag;
}
int main(int argc, char *argv[])
{
   int start = -1, end = -1, flag = 1;
   // int startmass[100] = {0};
   // int endmass[100] = {0};
   char c;

   int countword = 0, capacityword = 1;
   char *word = (char *)malloc(sizeof(char));
   while ((c = getchar()) != '\n' || flag == 0)
   {
      if (flag == 0)
      {
         flag = 1;
      }
      else
      {
         word[(countword)++] = c;
         if (countword >= capacityword)
         {
            capacityword *= 2;
            word = (char *)realloc(word, capacityword * sizeof(char));
         }
      }
   }

   flag = 1;
   int countstr = 0, capacitystr = 1;
   char *str = (char *)malloc(sizeof(char));

   while ((c = getchar()) != '\n' || flag == 0)
   {
      if (flag == 0)
      {
         flag = 1;
      }
      else
      {
         str[(countstr)++] = c;
         if (countstr >= capacitystr)
         {
            capacitystr *= 2;
            str = (char *)realloc(str, capacitystr * sizeof(char));
         }
      }
   }

   int countstart = 0, capacitystart = 1;
   int *startmass = (char *)malloc(sizeof(int));

   int countend = 0, capacityend = 1;
   int *endmass = (char *)malloc(sizeof(int));

   // for (size_t i = 0; i < 100; i++)
   // {
   //    startmass[i] = -1;
   //    endmass[i] = -1;
   // }
   int cur_word = 0;
   for (int i = 0; i < countstr; i++)
   {
      if (is_char(str[i]) == 1)
      {
         if (start == -1)
         {
            start = i;
            // startmass[cur_word] = start;
            startmass[(countstart)++] = start;
            if (countstart >= capacitystart)
            {
               capacitystart *= 2;
               startmass = (int *)realloc(startmass, capacitystart * sizeof(int));
            }
            if (i == countstr - 1)
            {
               end = i;
               // endmass[cur_word] = end;
               endmass[(countend)++] = end;
               if (countend >= capacityend)
               {
                  capacityend *= 2;
                  endmass = (int *)realloc(endmass, capacityend * sizeof(int));
               }

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
               // endmass[cur_word] = end;
               endmass[(countend)++] = end;
               if (countend >= capacityend)
               {
                  capacityend *= 2;
                  endmass = (int *)realloc(endmass, capacityend * sizeof(int));
               }
               cur_word++;
               start = -1;
               end = -1;
            }
         }
      }
      for (int i = 0; i < cur_word; i++)
      {
         if (is_same(str, word, startmass[i], endmass[i], cur_word, countword) == 1)
         {
            printf("%d ", (i + 1));
         }
      }
      free(startmass);
      free(endmass);
      free(str);
      free(word);
      return 0;
   }