#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int c[] = {105, 32, 108, 111, 118, 101, 32, 121, 111, 117, 44, 32, 109, 121, 32, 115, 109, 111, 108, 32, 97, 110, 103, 101, 108};
    for(int i = 0; i < 25; i++)
    {
        printf("%c", c[i]);
    }
    cout << endl;
    int a = 219;
    int b = 178;
    printf("  %c%c%c  %c%c%c  \n", b,b,b,b,b,b); //1
    printf(" %c%c%c%c%c%c%c%c%c%c \n", b,a,b,b,b,a,a,a,a,b);//2
    printf(" %c%c%c%c%c%c%c%c%c%c \n", a,a,a,a,b,b,b,b,b,b);//3
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", b,b,a,a,a,a,b,b,b,b,b);//4
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,b,b,a,a,b,b,a,a,a,b);//5
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,a,b,b,a,a,a,a,a);//6
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,a,b,b,b,a,a,a,a,a);//7
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,a,b,b,a,a,a,a,a,a);//8
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,b,a,a,a,a,a,a);//9
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a);//10
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a);//11
    printf("%c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a);//12
    printf("%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a);//13
    printf(" %c%c%c%c%c%c%c%c%c \n", a,a,b,a,a,a,a,a,a,a);//14
    printf("  %c%c%c%c%c    %c\n", a,a,a,a,a,a);//15
    printf("     %c    %c\n",a,a);
    printf("     %c    %c\n",a,a);
    printf("%c    %c   %c%c\n",a,a,a,a);
    printf(" %c   %c   %c%c\n",a,a,a,a);
    printf(" %c   %c  %c%c%c\n",a,a,a,a,a);
    printf(" %c%c  %c  %c%c%c\n",a,a,a,a,a,a);
    printf(" %c%c%c %c %c%c%c%c\n",a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a);
    printf("  %c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a);
    printf("  %c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a);
    printf("   %c%c%c%c%c%c\n",a,a,a,a,a,a);
    printf("    %c%c%c%c\n",a,a,a,a);
    printf("    %c%c%c%c\n",a,a,a,a);
    printf("     %c%c\n",a,a);
    printf("     %c\n",a);
    printf("     %c\n",a);


        printf("  %c%c%c  %c%c%c       %c%c%c  %c%c%c       %c%c%c  %c%c%c  \n", b,b,b,b,b,b, b,b,b,b,b,b, b,b,b,b,b,b); //1
    printf(" %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c \n", b,a,b,b,b,a,a,a,a,b, b,a,b,b,b,a,a,a,a,b, b,a,b,b,b,a,a,a,a,b);//2
    printf(" %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c \n", a,a,a,a,b,b,b,b,b,b, a,a,a,a,b,b,b,b,b,b, a,a,a,a,b,b,b,b,b,b);//3
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", b,b,a,a,a,a,b,b,b,b,b, b,b,a,a,a,a,b,b,b,b,b, b,b,a,a,a,a,b,b,b,b,b);//4
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,b,b,a,a,b,b,a,a,a,b, a,b,b,a,a,b,b,a,a,a,b, a,b,b,a,a,b,b,a,a,a,b);//5
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,a,b,b,a,a,a,a,a, a,a,b,a,b,b,a,a,a,a,a, a,a,b,a,b,b,a,a,a,a,a);//6
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,a,b,b,b,a,a,a,a,a, a,a,a,b,b,b,a,a,a,a,a, a,a,a,b,b,b,a,a,a,a,a);//7
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,a,b,b,a,a,a,a,a,a, a,a,a,b,b,a,a,a,a,a,a, a,a,a,b,b,a,a,a,a,a,a);//8
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,b,a,a,a,a,a,a, a,a,b,b,b,a,a,a,a,a,a, a,a,b,b,b,a,a,a,a,a,a);//9
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a);//10
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a);//11
    printf("%c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c \n", a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a,a);//12
    printf("%c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c%c  \n", a,a,b,b,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a, a,a,b,b,a,a,a,a,a,a);//13
    printf(" %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c \n", a,a,b,a,a,a,a,a,a, a,a,b,a,a,a,a,a,a, a,a,b,a,a,a,a,a,a);//14
    printf("  %c%c%c%c%c    %c     %c%c%c%c%c    %c     %c%c%c%c%c    %c\n", a,a,a,a,a,a, a,a,a,a,a,a, a,a,a,a,a,a);//15
    printf("     %c    %c         %c    %c         %c    %c\n",a,a,a,a, a,a);
    printf("     %c    %c         %c    %c         %c    %c\n",a,a,a,a, a,a);
    printf("%c    %c   %c%c    %c    %c   %c%c    %c    %c   %c%c\n",a,a,a,a,a,a,a,a, a,a,a,a);
    printf(" %c   %c   %c%c     %c   %c   %c%c     %c   %c   %c%c\n",a,a,a,a,a,a,a,a, a,a,a,a);
    printf(" %c   %c  %c%c%c     %c   %c  %c%c%c     %c   %c  %c%c%c\n",a,a,a,a,a,a,a,a,a,a, a,a,a,a,a);
    printf(" %c%c  %c  %c%c%c     %c%c  %c  %c%c%c     %c%c  %c  %c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a);
    printf(" %c%c%c %c %c%c%c%c     %c%c%c %c %c%c%c%c     %c%c%c %c %c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a,a,a);
    printf(" %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a,a);
    printf("  %c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a);
    printf("  %c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a,a,a);
    printf("   %c%c%c%c%c%c         %c%c%c%c%c%c         %c%c%c%c%c%c\n",a,a,a,a,a,a,a,a,a,a,a,a, a,a,a,a,a,a);
    printf("    %c%c%c%c          %c%c%c%c           %c%c%c%c\n",a,a,a,a,a,a,a,a, a,a,a,a);
    printf("    %c%c%c%c          %c%c%c%c           %c%c%c%c\n",a,a,a,a,a,a,a,a, a,a,a,a);
    printf("     %c%c            %c%c             %c%c\n",a,a,a,a, a,a);
    printf("     %c             %c              %c\n",a,a, a);
    printf("     %c             %c              %c\n",a,a, a);
    return 0;
}