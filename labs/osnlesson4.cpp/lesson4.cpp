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

int hemming(int a, int b)
{
    int e = a ^ b;
    int w = 0;
    while (e > 0)
    {
        w = w + (e & 1);
        e = e >> 1;
    }
    return w;
}

int decoder(int w)
{
    for (int i = 0; i < 4; i++)
    {
        
    }
}

int main()
{
    int e = 0xb;
    int m = 3;
    int a = coder(m);
    int b = channel(a, e);
    int w = hemming(a, b);
    printf("%x\n", a);
    printf("%x\n", e);
    printf("%x\n", b);
    printf("%x\n", w);
    return 0;
}