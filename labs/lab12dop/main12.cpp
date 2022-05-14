//Создайте класс DataAndTime с конструктором, использующим текущее время, возвращаемое функцией time() (из time.h) и дату, полученную функцией gmtime().

//класс база данных дня рождения 
#include "lab12.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

int main(){
    DataAndTime t;
    cout << t.getgmTime();
    return 0;

    Birthday b;
    
}