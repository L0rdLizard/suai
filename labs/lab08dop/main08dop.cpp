// Ввести степень и коэффициенты полинома. Ввести границы интервала a, b и точность eps. Найти корень полинома на интервале [a, b] методом деления отрезка пополам (считать, что p(a) * p(b) < 0).

#include "lab08dop.h"
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

    int n3;
    cout << "enter n3 = ";
    cin >> n3;
    cout << "\n";
    create_polinom(top_polinom3, end_polinom3, n3);
    // top_polinom3->koef = 1;
    // top_polinom3->power = 1;
    // top_polinom3->next = NULL;
    // end_polinom3->koef = 1;
    // end_polinom3->power = 1;
    // end_polinom3->next = NULL;

    del(top_polinom1, end_polinom1, top_polinom2, top_polinom3, end_polinom3);
    cout << "result = ";
    printf_poly(top_polinom3);
    cout << " ostatok = ";
    printf_poly(top_polinom1);
    return 0;
}