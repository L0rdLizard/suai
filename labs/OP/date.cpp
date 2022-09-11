#include <iostream>
#include <ostream>
using namespace std;

class date
{
private:
    int p_d;
    int p_m;
    int p_y;

public:
    date(int d, int m, int y)
    {
        p_d = d;
        p_m = m;
        p_y = y;
    }
    friend ostream &operator<<(ostream &os, const date& n)
    {
        os << n.p_d << "." << n.p_m << "." << n.p_y;
        return os;
    }
};

int main()
{
    date bd(14, 5, 2003);
    cout << bd;
    return 0;
}