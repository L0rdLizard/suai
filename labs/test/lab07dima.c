#include <stdio.h>
#include <stdlib.h>

void ltoab(long data, char s[]){
ltoa(data, s, 2);
}

int main(int argc, char *argv[])
{
char p[32] = {0};
long data = 13;
ltoab(data, p);
printf("%s\n", p);
return 0;
}