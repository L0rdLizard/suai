#ifndef LAB012_H_
#define LAB012_H_
#include <time.h>
#include <string.h>
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
    DataAndTime();
    time_t getLocalTime();
    char *getgmTime();
};

class Birthday {
    public:

        void set_name(string b_name)
        {
            name = b_name;
        }

        string get_name()
        {
            return name;
        }

        void set_last_name(string b_last_name)
        {
            last_name = b_last_name;
        }

        void set_age(int b_age)
        {
 
                age = b_age;

        }

    private:
        int age;

        int date[3];

        string name;

        string last_name;
};

#endif