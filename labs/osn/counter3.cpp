#include <stdio.h>
char arr[16] = {
  0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
};

char count_ones(int data)
{
    int z = data;
    char w = 0;
    while (z > 0)
    {  
        w += arr[z & 15]; 
        z = z >> 4;
    }
    return w;
}
int main()
{
    int mass[5] = {0};
    
    for (int i = 0; i < 16; i++)
    {
        mass[count_ones(i)]++;
    }
    for (int i = 0; i <= 4; i++)
    {
        printf("%d ", mass[i]);
    }
    return 0;
}