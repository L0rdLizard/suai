#include <stdio.h>
#include <iostream>
using namespace std;

// int book[4] = {0x0, 0xd, 0x16, 0x1b};
int book[4] = {0x0, 0xd, 0x16, 0x1b};

unsigned char coder(unsigned char m)
{
    return book[m];
}

unsigned char channel(unsigned char a, unsigned char e)
{
    return a ^ e;
}

unsigned char count_ones(unsigned char n)
{
    unsigned char w = 0;
    while (n > 0)
    {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

unsigned char hemming(unsigned char a, unsigned char b)
{
    return count_ones(a ^ b);
}

unsigned char decoder(unsigned char m)
{
    unsigned char ind = 0, min = 5;
    for (unsigned char i = 0; i < 4; i++)
    {
        unsigned char d = hemming(m, book[i]);
        if (d < min)
        {
            min = d;
            ind = i;
        }
    }
    return ind;
}

unsigned char min_dist(int *book)
{
    int min = 5;
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            k = count_ones(book[i] ^ book[j]);
            if (k < min)
                min = k;
        }
    }
    return min;
}



int main()
{
    int book2[32] = {0};
    int t = 0x0;
    for (int i = 0; i < 32; i++){
        book2[i]= t;
        t++;
    }
    int e = 1;
    int m = 3;
    int a = coder(m);
    int b = channel(a, e);
    int h = hemming(a, b);
    // int m1 = decoder(m);
    // printf("%d", m1);
    printf("%x\n", a);
    printf("%x\n", e);
    printf("%x\n", b);
    printf("%x\n", h);
    int min = min_dist(book);
    printf("%x\n", min);

    unsigned char arr[2][6] = {0};

    for (unsigned char n = 1; n < 6; n++)
    {
        for (unsigned char e = 0; e < 32; e++)
        {
            if (count_ones(e) == n)
            {
                unsigned char temp = 0;
                for (unsigned char m = 0; m < 4; m++)
                {
                    temp += (m == decoder(channel(coder(m), e)));
                }
                arr[0][n - 1] += (temp == 4);
                arr[1][n - 1] += 1;
            }
        }
    }

    for (unsigned char N = 1; N < 6; N++)
        printf("%d error(s): fixed %d / %d\n", N, arr[0][N - 1], arr[1][N - 1]);
    return 0;
}