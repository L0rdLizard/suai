#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    // x * x - 9 * x + 14
    double koef; // 1, -9, 14
    int power;   // 2, 1, 0
    node *next;
};

void create_polinom(node *&top, node *&end, int n)
{
    int i;
    node *p;
    top = NULL;
    end = NULL;
    int temp_n = n;
    for (i = 0; i < n; i++)
    {
        // static int temp_n = n;
        p = new node;
        cout << " enter koef" << n - temp_n + 1 << "=";
        cin >> p->koef;
        // cout << " enter power=";
        // cin >> p->power;
        p->power = (temp_n - 1);
        temp_n = temp_n - 1;
        cout << "\n";
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

void addToPoly(node *&top, node *&end, int power, double koef, int counter_nnode)
{
    // cout << "counter node: " << counter_nnode;
    node *p = new node;
    p->power = power;
    p->koef = koef;
    if (counter_nnode == 0)
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

// void zero_destroyer(node *&top1, node *&end1){
//     node *temp = top1;
//     while (temp != NULL){
//         if (temp->koef == 0){

//         }
//         temp = temp->next;
//     }
// }

void del(node *&top1, node *&end1, node *&top2, node *&top3, node *&end3)
{
    int counter = 0;
    while ((top1 != NULL) && (top1->power >= top2->power))
    {
        node *top_cur;
        node *end_cur;

        double temp_koef = top1->koef / top2->koef;
        int temp_power = top1->power - top2->power;

        addToPoly(top3, end3, temp_power, temp_koef, counter);
        counter++;

        node *cur_temp = top2;
        int counter2 = 0;
        while (cur_temp != NULL)
        {
            addToPoly(top_cur, end_cur, cur_temp->power + temp_power, cur_temp->koef * temp_koef, counter2);
            cur_temp = cur_temp->next;
            counter2++;
        }

        node *temp1 = top1;
        node *temp2 = top_cur;
        node *greshok_top;
        node *greshok_end;
        int counterg = 0;
        for (int i = 0; i <= counter2; i++)
        {
            if (temp2 != NULL)
            {
                // temp1->koef -= temp2->koef;
                if (temp1->koef - temp2->koef != 0)
                {
                    addToPoly(greshok_top, greshok_end, temp1->power, temp1->koef - temp2->koef, counterg);
                    greshok_end->next = NULL;
                    counterg++;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                addToPoly(greshok_top, greshok_end, temp1->power, temp1->koef, counterg);
                greshok_end->next = NULL;
                counterg++;
            }
        }
        top1 = greshok_top;
        end1 = greshok_end;
    }
}

void printf_poly(node *&top3)
{
    node *poly = top3;
    int first = 1;
    // cout << "Result: ";
    while (1)
    {
        if (poly == NULL)
            break;
        if (first == 1)
        {
            cout << poly->koef;
            first = 0;
        }
        else
            cout << (poly->koef >= 0 ? " +" : " ") << poly->koef;
        if (poly->power != 0)
            if (poly->power == 1)
                cout << "x";
            else
                cout << "(x^" << poly->power << ")";
        poly = poly->next;
    }
}

double F2(node *&top, double x)
{
    double result = 0;
    node * cur = top;
    while (1){
        if (cur == NULL) break;
        result += cur->koef * pow(x, cur->power);
        cur = cur->next;
    }
    // cout << result << "\n";
    return result;
}

double FindRoot(double (*f)(node*&, double), double a, double b, double eps, node *&top)
{
    double c;
    while ((b - a) / 2 > eps)
    {
        c = (a + b) / 2;
        if ((f(top, a) * f(top, c)) > 0)
            a = c;
        else
            b = c;
    }
    return c;
}