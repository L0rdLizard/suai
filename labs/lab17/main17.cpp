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
}