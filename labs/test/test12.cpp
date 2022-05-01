//Создайте класс DataAndTime с конструктором, использующим текущее время, возвращаемое функцией time() (из time.h) и дату, полученную функцией gmtime().

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

class DataAndTime
{
private:
    // struct tm *local, *gm;
    struct tm *ptm;
    time_t rawtime;
    char *ptm_char;

public:
    DataAndTime(){
        // time( &rawtime );
        rawtime = time (NULL);
        ptm = gmtime( &rawtime );
        ptm_char = asctime(ptm);
    }
    time_t getLocalTime(){
        return rawtime;
    }
    char *getgmTime(){
        // char *ptm_char = asctime(ptm);
        return ptm_char;
    }
};

int main(){
    DataAndTime t;
    // Я тибя люблю :з Моя буличка с корицей
    // тю
    // тю
    cout << t.getgmTime();
    return 0;
}