#include <iostream>
#include <ostream>
using namespace std;

class drob
{
private:
    int p_a;
    int p_b;

public:
    drob(int a, int b)
    {
        p_a = a;
        p_b = b;
    };
    friend ostream &operator<<(ostream &os, const drob &d);
    // {
    //     os << d.p_a << "/" << d.p_b;
    //     return os;
    // }
    // drob& operator<<(ostream& os, const drob& d);
};

ostream &operator<<(ostream &os, const drob &d)
{
    os << d.p_a << "/" << d.p_b;
    return os;
}

int main()
{
    drob dr1(1, 5);
    cout << dr1 << endl << dr1 << endl;
    return 0;
}