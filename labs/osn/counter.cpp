#include <stdio.h>
int counter(int data)
{
    int w = 0, z = 0;
    z = data;
    while (z > 0)
        {
            w = w + (z & 1);
            z = z >> 1;
        }
    return w;   
}