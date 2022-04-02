// Ввести степень и коэффициенты полинома. Ввести границы интервала a, b и точность eps. Найти корень полинома на интервале [a, b] методом деления отрезка пополам (считать, что p(a) * p(b) < 0).

#include "lab08.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    node *top_polinom, *end_polinom;
    int n;
    cout << "enter n = ";
    cin >> n;
    cout << "\n";
    // node **mass = (node **)malloc(sizeof(node *) * n);
    create_polinom(top_polinom, end_polinom, n);

    double a, b, eps, x;
    cout << "interval: ";
    cin >> a;
    cin >> b;
    // cout << F2(top_polinom, a) * F2(top_polinom, b) << "\n";
    if (F2(top_polinom, a) * F2(top_polinom, b) > 0)
    {
        cout << "Wrong data or interval!\n";
        return 0;
    }
    cout << "eps: ";
    cin >> eps;

    x = FindRoot(F2, a, b, eps, top_polinom);
    cout << "x = " << x << endl;

    return 0;
}