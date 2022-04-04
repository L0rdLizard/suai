#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 1, w = 0;
    do
    {
        scanf("%d", &x);
        int z = x;
        while (z > 0)
        {
            w = w + (z & 1);
            z = z >> 1;
        }
        printf("%d\n", w);
        w = 0;
    } while (x != 0);
    return 0;
}