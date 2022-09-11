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

    int getval()
    {
        return val;
    }
};

class list_t
{
private:
    node_t *head;
    size_t size;

public:
    list_t()
    {
        head = NULL;
        size = 0;
    }

    list_t(list_t &l)
    {
        size = l.size;
        node_t *f_cur = l.head;
        node_t *cur = NULL;
        if (f_cur != NULL)
        {
            cur = new node_t(f_cur->getval());
            head = cur;
            f_cur = f_cur->getnext();
        }
        while (f_cur != NULL)
        {
            cur = new node_t(f_cur->getval());
            f_cur = f_cur->getnext();
        }
    }


    list_t &list_t::operator=(list_t &l)
    {
        if (&l == this)
            return *this;
        this->~list_t();
        // тут тот же код что и в конструкторе копий
        return *this;
    }


    list_t::~list_t() // деструктор
    {
        node_t *cur = this->head;
        while (cur != NULL)
        {
            node_t *temp = cur;
            cur = cur->getnext();
            delete temp;
        }
        head = NULL;
        size = 0;
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