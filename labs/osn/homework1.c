#include <stdio.h>
#define count 8
int counter(int data)
{
    int x = 1, w = 0;
    x = data;
    while (x > 0)
    {
        w = w + (x & 1);
        x = x >> 1;
    }
    printf("%d\n", w);

    return w;
}

int main(int argc, char *argv[])
{
    int mass[count];
    for (int i = 0; i < count; i++)
    {
        mass[i] = counter(i);
    }
    printf("\n");
    // int input;
    // while (1)
    // {
    //     scanf_s("%d", &input);
    //     if (input <= -1)
    //         break;
    //     else if (input >= count)
    //         break;
    //     printf("result = %d\n", mass[input]);
    // }
    return 0;
}