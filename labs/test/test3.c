#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    char s1[] = "3 4 7";
    sscanf(s1, "%d %d %d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    char s2[256];
    sprintf(s2, "%d + %d = %d", a, b, c);
    return 0;
}