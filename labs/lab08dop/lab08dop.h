#ifndef LAB08_H_
#define LAB08_H_

struct node
{
    // x * x - 9 * x + 14
    int koef;  // 1, -9, 14
    int power; // 2, 1, 0
    node *next;
};

void create_polinom(node *&top, node *&end, int n);

void addToPoly(node *&top, node *&end, int power, double koef, int counter_nnode);

void del(node *&top1, node *&end1, node *&top2, node *&top3, node *&end3);

void printf_poly(node *&top3);

double F2(node *&top, double x);

double FindRoot(double (*f)(node*&, double), double a, double b, double eps, node *&top);
#endif