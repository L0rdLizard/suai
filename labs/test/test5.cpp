#include <stdio.h>
int main()
{
    int x, i = 1, otvet = 0;
    scanf("%d", &x);
    while (x > 0)
    {
        otvet += x % 2 * i;
        i *= 10;
        x /= 2;
    }
    printf("%d", otvet);
    return 0;
}