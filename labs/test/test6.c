#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = 0;
    printf("vvedite dlinu\n");
    scanf_s("%d\n", &n);
    char *mass = (char *)malloc((n+1) * sizeof(char));
    for (int i = 0; i < n; i++){
        scanf_s("%c", &mass[i]);
    }
    mass[n] = 0;
    printf("%s", mass);
    free(mass);
    return 0;
}