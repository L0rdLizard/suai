//Написать функцию для перевода переменной типа long в символьную строку в двоичном представлении ( ltoab( long num, char s[]) ) и тестирующую программу к ней.

#include "lab07.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    char p[32] = {0};
    long data;
    int d = 0;
    scanf_s("%ld", &data);
    scanf_s("%d", &d);
    ltoab(data, p, d);
    printf("%s",p, d);
    return 0;
}