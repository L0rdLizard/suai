#include "lab12.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

DataAndTime::DataAndTime()
{
    // time( &rawtime );
    rawtime = time(NULL);
    ptm = gmtime(&rawtime);
    ptm_char = asctime(ptm);
};

time_t DataAndTime::getLocalTime()
{
    return rawtime;
};

char *DataAndTime::getgmTime()
{
    return ptm_char;
};
