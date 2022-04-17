#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int b[] = {105, 32, 108, 111, 118, 101, 32, 121, 111, 117, 44, 32, 109, 121, 32, 115, 109, 111, 108, 32, 97, 110, 103, 101, 108};
    for(int i = 0; i < 25; i++)
    {
        printf("%c", b[i]);
    }
    cout << endl;
    int a = 3;
    printf("  %c%c%c   %c%c%c\n %c   %c %c   %c\n%c     %c     %c\n%c           %c\n%c           %c\n %c         %c\n  %c       %c\n   %c     %c\n    %c   %c\n     %c %c\n      %c \n", a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    return 0;
}