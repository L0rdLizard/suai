//Создайте класс DataAndTime с конструктором, использующим текущее время, возвращаемое функцией time() (из time.h) и дату, полученную функцией gmtime().

//класс база данных дня рождения
#include "lab12.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    DataAndTime t;
    // time_t rawtime;
    // struct tm *timeinfo;
    // time(&rawtime);
    // timeinfo = localtime(&rawtime);
    // cout << asctime(timeinfo);
    cout << t.getgmTime();
    return 0;
}