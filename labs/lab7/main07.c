#include "lab07.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    char p[30] = {0};
    ltoab(27, p);
    printf("%s",p);
    return 0;
}