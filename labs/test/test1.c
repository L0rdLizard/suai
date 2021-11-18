#include <stdio.h>
void hi(int **d){
    d[0] = 2;
    return 0;
}
int main(int argc, char const *argv[])
{
    int c[] = {5, 4, 3, 2};
    hi(&c);
    printf("%d %d %d %d", c[0],c[1],c[2],c[3]);
    return 0;
}
