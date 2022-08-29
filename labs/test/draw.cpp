#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a = 219;
    int b = 219;
    printf("  %c%c%c   %c%c%c\n", a, a, a, a, a, a);
    printf(" %c   %c %c   %c\n", a, a, a, a);
    printf("%c     %c     %c\n", a, a, a);
    printf("%c           %c\n", a, a);
    printf("%c           %c\n", a, a);
    printf(" %c         %c\n", a, a);
    printf("  %c       %c\n", a, a);
    printf("   %c     %c\n", a, a);
    printf("    %c   %c\n", a, a);
    printf("     %c %c\n", a, a);
    printf("      %c \n", a);
    printf("%c", b);
    return 0;
}