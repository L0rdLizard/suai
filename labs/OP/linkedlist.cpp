#include <iostream>
#include <ostream>
using namespace std;

class node_t
{
private:
    int val;
    node_t *next = NULL;

public:
    node_t(int val)
    {
        this->val = val;
    }
    node_t *getnext()
    {
        return this->next;
    }
};

node_t& get(int n)
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