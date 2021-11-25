#include <stdio.h>

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

int is_same(char *str, char word, int amount_words){

}

int main(int argc, char *argv[])
{
   int amount_words;
   char word;
   return 0;
}