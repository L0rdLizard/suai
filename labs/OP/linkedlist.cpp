#include <iostream>
#include <ostream>
using namespace std;

node_t &get(int n)
{
    node_t *cur = this->head;
    for (int i = 0; i < n; n++)
    {
        cur = cur.getnext;
    }
    return cur;
}

int main()
{

    return 0;
}