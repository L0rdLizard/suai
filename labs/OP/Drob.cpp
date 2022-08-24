#include <iostream>
using namespace std;

int main(){
    class drob
    {
    private:
        int p_a;
        int p_b;
    public:
        drob (int a, int b) {
            p_a = a;
            p_b = b;
        };
        friend ostream& operator<<(ostream& os, const drob& d);
        // drob& operator<<(ostream& os, const drob& d);
    };

    // drob& drob::operator<<(ostream& os, const drob& d)
    // {
    //     os<<d.p_a<<"/"<<d.p_b;
    //     return os;
    // }
    return 0;
}