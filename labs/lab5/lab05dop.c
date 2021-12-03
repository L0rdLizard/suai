#include <stdio.h>
#include <stdlib.h>

// Ввести строку и слово. Вывести порядковые номера слов в строке, совпадающих с введенным словом.
int strrealloc(char *str, int countstr, int capacitystr)
{
   int flag = 1;
   char c;
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
}

int wordrealloc(char *word, int countword, int capacityword)
{
   int flag = 1;
   char c;
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
}

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
   int start = -1, end = -1;

   int countword = 0, capacityword = 1;
   char *word = (char *)malloc(sizeof(char));
   wordrealloc(word, countword, capacityword);

   int countstr = 0, capacitystr = 1;
   char *str = (char *)malloc(sizeof(char));
   strrealloc(str, countstr, capacitystr);

   int countstart = 0, capacitystart = 1;
   // int *startmass = (int *)malloc(sizeof(int));

   int countend = 0, capacityend = 1;
   // int *endmass = (int *)malloc(sizeof(int));
   int N = 2, M = 1;
   int **A = (int **)malloc(N * sizeof(int *));
   for (int i = 0; i < N; i++)
   {
      A[i] = (int *)malloc(M * sizeof(int));
   }

   int cur_word = 0;
   for (int i = 0; i < countstr; i++)
   {
      if (is_char(str[i]) == 1)
      {
         if (start == -1)
         {
            start = i;
            bordermass[(countstart)++][0] = start;
            if (countstart >= capacitystart)
            {
               capacitystart *= 2;
               bordermass = (int *)realloc(bordermass, capacitystart * sizeof(int));
            }
         }
         if (i == countstr - 1)
         {
            end = i;
            bordermass[(countend)++][1] = end;
            if (countend >= capacityend)
            {
               capacityend *= 2;
               bordermass = (int *)realloc(bordermass, capacityend * sizeof(int));
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
            bordermass[(countend)++][1] = end;
            if (countend >= capacityend)
            {
               capacityend *= 2;
               bordermass = (int *)realloc(bordermass, capacityend * sizeof(int));
            }
            cur_word++;
            start = -1;
            end = -1;
         }
      }
   }
   for (int i = 0; i < cur_word; i++)
   {
      if (is_same(str, word, bordermass[i][0], bordermass[i][1], cur_word, countword) == 1)
      {
         printf("%d ", (i + 1));
      }
   }
   // free(startmass);
   // free(endmass);
   free(bordermass);
   free(str);
   free(word);
   return 0;
}