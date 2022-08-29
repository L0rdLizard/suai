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

class list_t
{
private:
    node_t* head;
    size_t size;
public:

    list_t()
    {
        head = NULL;
        size = 0;
    }

    list_t(list_t &l)
    {

    }
};

// node_t& get(int n)
// {
//     node_t *cur = this->head;
//     for (int i = 0; i < n; n++)
//     {
//         cur = cur.getnext;
//     }
//     return cur;
// }

int main()
{

    return 0;
}