#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 1, w = 0;
    scanf_s("%d", &x);
    while (x > 0)
    {
        w = w + (x & 1);
        x = x >> 1;
    }
    printf("%d", w);

    return 0;
}