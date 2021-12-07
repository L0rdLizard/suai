#include <stdio.h>
void aboba(int (*words)[2]){
    words[0][0]=5;
}

int main(int argc, char *argv[])
{
    int N = 5;
     
    int (*words)[2] = (int (*)[2])malloc( N * 2 * sizeof( int ) );

    for (size_t i = 0; i < N; i++)
    {
        words[i][0]=-1;
        words[i][1]=-1;
    }
    words = (int(*)[2])realloc(words, N * 2 * sizeof(int));
    
    for (size_t i = 0; i < N; i++)
    {
        printf("%d %d\n", words[i][0],words[i][1]);
    }
    aboba(words);
    printf("%d", words[0][0]);

    // int *mass = (int *)malloc( 10 * sizeof( int ) );
    // mass[0]=124;
    // aboba(mass);
    // printf("%d\n",mass[0]);
    return 0;
}