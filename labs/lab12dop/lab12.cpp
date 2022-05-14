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



void Birthday::set_name(std::string b_name)
{
    name = b_name;
}

std::string Birthday::get_name()
{
    return name;
}

void Birthday::set_last_name(std::string b_last_name)
{
    last_name = b_last_name;
}

void Birthday::set_age(int *b_age)
{
    for (int i = 0; i < 3; ++i)
    {
        age[i] = b_age[i];
    }
}
