#include "lab07.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    char p[32] = {0};
    ltoab(121, p);
    printf("%s",p);
    return 0;
}