#ifndef LAB012_H_
#define LAB012_H_
#include <time.h>
#include <string.h>

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
        void set_name(std::string b_name)
        {
            name = b_name;
        }

        std::string get_name()
        {
            return name;
        }

        void set_last_name(std::string b_last_name)
        {
            last_name = b_last_name;
        }

        void set_age(int *b_age)
        {
            for (int i = 0; i < 3; ++i) {
                age[i] = b_age[i];
            }
        }

    private:
        int age;

        int date[3];

        std::string name;

        std::string last_name;
};

#endif