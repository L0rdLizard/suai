#include <iostream>
#include "lab17.h"

using namespace std;

int main()
{
    // vector_t<int> v(5, 2);
    // vector_t<point> v(5, {1, 2, 3});
    // v.saveyaml("test.yaml");

    vector_t<int> v2(0, 0);
    v2.loadyaml("test.yaml");
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }

    // v.push_back(2);

    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // vector_t<point> v2(5, {1, 2, 3});
    // v2.push_back({4, 5, 6});
    // v2.insert(8, {7, 8, 9});

    // for (size_t i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << endl;
    // }
}