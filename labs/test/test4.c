#include <stdio.h>

int main(int argc, char *argv[])
{
    char *str = "Hello" ;
    char *stri = str;
    stri += 1;
    // str = &stri;
    printf("%c\n", *stri);
    // printf("%s", *str);
    return 0;
}