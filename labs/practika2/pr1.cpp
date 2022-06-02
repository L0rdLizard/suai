#include <iostream>
#include <string>
using namespace std;
static unsigned char A[] = {0x00, 0x0d, 0x16, 0x1b};

unsigned char coder(unsigned char m) { return A[m]; }
unsigned char channel(unsigned char a, unsigned char e) { return a ^ e; }
unsigned char count_ones(unsigned char n)
{
    unsigned char w = 0;
    while (n > 0)
    {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}
unsigned char hemming(unsigned char a, unsigned char b)
{
    return count_ones(a ^ b);
}
unsigned char decoder(unsigned char m)
{
    unsigned char ind = 0, min = 5;
    for (unsigned char i = 0; i < 4; i++)
    {
        unsigned char d = hemming(m, A[i]);
        if (d < min)
        {
            min = d;
            ind = i;
        }
    }
    return ind;
}
string bin(unsigned char n)
{
    string bin_code;
    for (unsigned char i = 0; i < 5; i++)
        bin_code += to_string((n >> (4 - i)) & 1);
    return bin_code;
}
int main()
{
    unsigned long long m, e, w, c, d;
    cin >> m >> e;
    w = coder(m);
    c = channel(w, e);
    d = decoder(c);
    cout << "m:	" << bin(m) << endl;
    cout << "w:	" << bin(w) << endl;
    cout << "e:	" << bin(e) << endl;
    cout << "c:	" << bin(c) << endl;
    cout << "d:	" << bin(d) << endl;
    // cout << "test	" << m << endl;
    // cout << "test	" << A[m] << endl;
    // printf("%d", A[m]);
}
