#include "lab18.hpp"
#include <iostream>

//Реализовать multiset.
//   void insert(int value)
//  int find(int value) //возвращает количество 
// void erase(int value) //удаляет один экземпляр записи
//  operator<< для вывода на экран
// вычитание множеств


using namespace std;

int main() {
    multiset_p multiset;
    multiset_p multiset2;
    multiset.insert(1);
    multiset.insert(1);
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(3);
    multiset.insert(4);
    cout << multiset.find(1) << endl;
    cout << multiset << endl;
    
    while (multiset.find(1) > 1) {
        multiset.erase(1);
    }

    multiset.erase(1);
    multiset.erase(1);
    multiset.erase(5);

    cout << multiset << endl;

    multiset.insert(3);

    cout << multiset << endl;
    cout << multiset.find(3) << endl;

    return 0;
}
