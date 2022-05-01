#ifndef LAB012_H_
#define LAB012_H_
#include <time.h>

class DataAndTime
{
private:
    // struct tm *local, *gm;
    struct tm *ptm;
    time_t rawtime;
    char *ptm_char;

public:
    DataAndTime();
    time_t getLocalTime();
    char *getgmTime();
};

#endif