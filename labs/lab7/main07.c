//Написать функцию для перевода переменной типа long в символьную строку в двоичном представлении ( ltoab( long num, char s[]) ) и тестирующую программу к ней.

#include "lab07.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while (1)
    {
        char p[32] = {0};
        long data;
        int d = 0;
        printf("enter the number and system definition\n");
        scanf("%ld", &data);
        if (data == -1) exit(1);
        scanf("%d", &d);
        if (d == -1) exit(1);
        ltoab(data, p, d);
        printf("%s\n", p, d);
    }
    return 0;
}