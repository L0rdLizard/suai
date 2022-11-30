#include <iostream>
#include <string>
#include "lab17.h"
using namespace std;

void test1()
{
    vector_t<int> v1(3, 0);
    v1.push_back(1);
    v1.push_back(2);
    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << endl;
    }
    cout << endl;
    v1.erase(1);
    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << endl;
    }
    cout << endl;
    v1.insert(1, 2);
    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << endl;
    }
}

void test2()
{
    vector_t<point> v2(3, point{1, 2, 3});
    v2.push_back(point{4, 5, 6});
    v2.push_back(point{7, 8, 9});
    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
    cout << endl;
    v2.erase(1);
    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
    cout << endl;
    v2.insert(1, point{10, 11, 12});
    for (size_t i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
}

void test3()
{
    vector_t<string> v(3, "hello");
    v.push_back("world");
    v.push_back("!");

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    v.erase(1);
    cout << "After erasing index 1:" << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    v.insert(1, "world");
    cout << "After inserting \"world\" at index 1:" << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void testyaml()
{
    // vector_t<int> v(5, 3);
    // // vector_t<point> v(5, {1, 2, 3});
    // v.saveyaml("test.yaml");

    // vector_t<int> v2(0, 0);
    // v2.loadyaml("test.yaml");
    // for (int i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << endl;
    // }

    // vector_t<point> v3(0, {0, 0, 0});
    // v3.loadyaml("test.yaml");
    // for (int i = 0; i < v3.size(); i++)
    // {
    //     cout << v3[i] << endl;
    // }

    // v.push_back(2);

    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }

    // // vector_t<point> v2(5, {1, 2, 3});
    // // v2.push_back({4, 5, 6});
    // // v2.insert(8, {7, 8, 9});

    // for (size_t i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << endl;
    // }

    // vector_t<int> v(5, 3);
    // v.saveyaml("test.yaml");
    // vector_t<int> v2(0, 0);
    // v2.loadyaml("test.yaml");
    // for (int i = 0; i < v2.size(); i++)
    // {
    //     cout << v2[i] << endl;
    // }
}

int main()
{
    test1();
    return 0;
}
