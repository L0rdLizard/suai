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



void Birthday::set_name(string b_name)
{
    name = b_name;
}

std::string Birthday::get_name()
{
    return name;
}

void Birthday::set_last_name(string b_last_name)
{
    last_name = b_last_name;
}

void Birthday::set_age(int b_age)
{
        age = b_age;
}

// class Birthday{
//     public:
//     Birthday(int cday,int cmonth,int cyear)
//     { month = cmonth;  day = cday;   year = cyear; }
//     void printDate(){ cout<<month <<"/" <<day <<"/" <<year <<endl; }
//     private: int month,day,year;
// };
