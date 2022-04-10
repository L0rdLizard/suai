#include <stdio.h>
char arr[16] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
};

int counter(int data)
{
    int w = 0, z = 0;
    z = data;
    while (z > 0)
        {
            w = w + arr[z & 15];
            z = z >> 4;
        }
    return w;   
}