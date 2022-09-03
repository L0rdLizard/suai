#include <iostream>
using namespace std;

int main()
{
    int mass[] = {15, 45, 55, 123, 3, 6, 33};
    // // mass[0] = 5;
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d\n", mass[i]);
    // }

    // if (mass[0] < mass[1])
    // {
    //     printf("pito\n");
    // }

    int a = 0;

    while (mass[a] != 33)
    {
        printf("%d = %d ne podhodit\n", a, mass[a]);
        a++;
    }
    printf("%d\n", a);
    return 0;
}