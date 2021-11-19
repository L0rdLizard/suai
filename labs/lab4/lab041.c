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
// contain; return 1
// not contain; return -1
int contain(char *str, int w1s, int w1e, int *newstartmass, int *newendmass, int cur_word){
   for (int i=0; i<cur_word; i++){
      if (newstartmass[i] == -1) break;
      if ((w1e-w1s)!=(newendmass[i]-newstartmass[i])) continue;
      int flag = 1;
      for (int j=0; j < (w1e-w1s+1); j++)
         if (str[w1s+j] != str[newstartmass[i]+j]) flag = 0;
      if (flag == 1) return 1;
   }
   return -1;
}

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
   for (int i = 0; i < cur_word - 1; i++)
   {
      for (int j = (cur_word-1); j > i; j--)
      {
         if (dif(str, startmass[j], endmass[j], startmass[j-1], endmass[j-1]) == 1)
         {
            int tmpst = startmass[j-1];
            int tmpend = endmass[j-1];
            startmass[j-1] = startmass[j];
            endmass[j-1] = endmass[j];
            startmass[j] = tmpst;
            endmass[j] = tmpend;
         }
      }
   }
}

int main(int argc, char *argv[])
{
   char str[101] = {0};
   fgets(str, 101, stdin);
   int startmass[100] = {0}, endmass[100] = {0}, newstartmass[100] = {0}, newendmass[100] = {0}, end = -1, start = -1;
   for (size_t i = 0; i < 100; i++)
   {
      startmass[i] = -1;
      endmass[i] = -1;
      newstartmass[i] = -1;
      newendmass[i] = -1;
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
   sorting(str, startmass, endmass, cur_word);
   int count = 0;
   for (int i = 0; i < cur_word; i++){
      if(contain(str, startmass[i], endmass[i], newstartmass, newendmass, cur_word) == -1){
         newstartmass[count] = startmass[i];
         newendmass[count] = endmass[i];
         count++;
      }
   }
   for (int i=0; i < count; i++){
      for (int j=0; j < (newendmass[i]-newstartmass[i]+1); j++){
         printf("%c",str[newstartmass[i]+j]);
      }
      printf("\n");
   }
   return 0;
}