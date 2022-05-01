#include <stdio.h>
#include <time.h>
#include <stddef.h>
/* вывод   локального времени и времени по Гринвичу */
int main(void)
{
struct tm *local, *gm;
time_t t;
t = time(NULL);
local = localtime(&t);
printf ("Local time and date: %s", asctime(local));
gm = gmtime(&t);
printf ("Greenwich mean time and date: %s", asctime(gm));
return 0;
}