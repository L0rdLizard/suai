// Ввести степень и коэффициенты полинома. Ввести границы интервала a, b и точность eps. Найти корень полинома на интервале [a, b] методом деления отрезка пополам (считать, что p(a) * p(b) < 0).

#include "lab08.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    node *top_polinom1, *end_polinom1;
    node *top_polinom2, *end_polinom2;
    node *top_polinom3, *end_polinom3;
    int n1;
    cout << "enter n1 = ";
    cin >> n1;
    cout << "\n";
    create_polinom(top_polinom1, end_polinom1, n1);

    int n2;
    cout << "enter n2 = ";
    cin >> n2;
    cout << "\n";
    create_polinom(top_polinom2, end_polinom2, n2);

    double a, b, eps, x;
    cout << "interval: ";
    cin >> a;
    cin >> b;
    if (F2(top_polinom1, a) * F2(top_polinom1, b) > 0)
    {
        cout << "Wrong data or interval!\n";
        return 0;
    }
    cout << "eps: ";
    cin >> eps;

    x = FindRoot(F2, a, b, eps, top_polinom1);
    cout << "x = " << x << endl;

    return 0;
}