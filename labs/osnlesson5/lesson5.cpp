#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
#define N 5
#define D 3

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

int main()
{
    int m = 0;
    int size = pow(2, N);
    int mark[size] = {0};
    int codebook[size] = {0};
    //шаг 1. Выбераем первое кодовое слово
    codebook[0] = 0;
    // отметим взятое слово в массиве пометок
    mark[0] = 2;
    m++;
    // шаг 2. отметим все слова в кандидатах на расстоянии меньше d от выбранного
    for (int i = 0; i < size; i++)
    {
        if (mark[i] == 0 && count_ones(i ^ codebook[0]) < D)
        {
            mark[i] = 1;
        }
        cout << " " << mark[i];
    }

    return 0;
}