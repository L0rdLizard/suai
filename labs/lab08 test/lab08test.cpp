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

double F(double x)
{
    return x * x - 9 * x + 14;
}

double FindRoot(double (*f)(double), double a, double b, double eps)
{
    double c;
    while ((b - a) / 2 > eps)
    {
        c = (a + b) / 2;
        if ((f(a) * f(c)) > 0)
            a = c;
        else
            b = c;
    }
    return c;
}

int main()
{
    // node *top_polinom, *end_polinom;
    // int n;
    // cout << "enter n= ";
    // cin >> n;
    // node **mass = (node **)malloc(sizeof(node *) * n);
    // create_polinom(top_polinom, end_polinom, n);

    double a, b, eps, x;
    cout << "interval: ";
    cin >> a;
    cin >> b;


    if (F(a) * F(b) > 0)
    {
        cout << "Wrong interval!\n";
        return 0;
    }
    cout << "error: ";
    cin >> eps;

    x = FindRoot(F, a, b, eps);
    cout << "x = " << x << endl;
    return 0;



    return 0;
}
