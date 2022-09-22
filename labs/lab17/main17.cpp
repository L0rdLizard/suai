#include <iostream>
#include "lab17.h"

using namespace std;

int main(){
    vector<int> v(5, 1);
    v.push_back(2);

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    vector<point> v2(5, {1, 2, 3});
    v2.push_back({4, 5, 6});
    v2.insert(8, {7, 8, 9});

    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
}