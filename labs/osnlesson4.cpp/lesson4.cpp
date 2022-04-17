#include <stdio.h>

int book[4] = {0x0, 0xd, 0x16, 0x1b};

int coder(int m)
{
    return book[m];
}

int channel(int a, int e)
{
    return (a ^ e);
}

int count_ones(int n)
{
    unsigned char w = 0;
    while (n > 0)
    {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

int hemming(int a, int b)
{
    return count_ones(a ^ b);
    // int w = 0;
    // while (e > 0)
    // {
    //     w = w + (e & 1);
    //     e = e >> 1;
    // }
    // return w;
}

int decoder(int m)
{
    for (int i = 0; i < 4; i++)
    {
        int ind = 0, min = 5;
        int d = hemming(m, book[i]);
        if (d < min)
        {
            min = d;
            ind = i;
        }
    }
}

int main()
{
    int e = 0xb;
    int m = 3;
    int a = coder(m);
    int b = channel(a, e);
    int h = hemming(a, b);
    printf("%x\n", a);
    printf("%x\n", e);
    printf("%x\n", b);
    printf("%x\n", h);
    return 0;
}