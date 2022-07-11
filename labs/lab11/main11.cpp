//Написать функцию char * strtok(char *, const char *), работающую так же, как библиотечная  функция и тестирующую программу к ней.
#include <stdio.h>
#include <string.h>
 
int main()
{
  char str[] = "Hello, my name is Max";
  printf("Split \"%s\" on lexem.", str);
  char *pch = strtok(str, " ,."); //во втором параметре указаны разделители (пробел, запятая, точка)
  printf("\nLex:");
  while (pch != NULL) //пока есть лексемы
  {
      printf("\n%s", pch);
      pch = strtok(NULL, " ,.");
  }
  return 0;
}