#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    char str[256] = "Hello";
    cout << str << endl;
    int a = 0, b = 0;
    while(1) {
        int count = 0;
        if (str[b] == 0) break;
        b++; 
    }
    a = strlen(str);
    cout << a << endl;
    cout << b << endl;

    
    return 0;
}