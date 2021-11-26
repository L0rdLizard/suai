#include <stdio.h>

int is_char(int ch)
{
   if (
       (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
       (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
      return 1;
   else
      return 0;
}

int main()
{
    int count = 0;
    char word[16] = {0};
    fgets(word, 16, stdin);
    for (int i = 0; i < 16; i++)
    {
        if (is_char(word[i]) == 1)
            count++;
    }
    printf("%d", count);
    return 0;
}