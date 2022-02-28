#include <iostream>
using namespace std;

struct node
{
    int koef;
    int power;
    node *next;
};

bool empty_polinom(node *top)
{
    return top == NULL;
}

void create_polinom(node *&top, node *&end, int n)
{
    int i;
    node *p;
    top = NULL;
    end = NULL;
    for (i = 0; i < n; i++)
    {
        p = new node;
        cout << " enter koef=";
        cin >> p->koef;
        cout << " enter power=";
        cin >> p->power;
        if (i == 0)
        {
            p->next = top;
            top = p;
            end = p;
        }
        else
        {
            end->next = p;
            p->next = NULL;
            end = p;
        }
    }
}