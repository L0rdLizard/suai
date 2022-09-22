#include "notebook.h"
#include <iostream>
#include <string>
using namespace std;

void do_read()
{
    notebook n;
    n.load("phonebook.txt");
    cout << n;
}

void do_write()
{
    notebook n;
    n.add("John", 1234567890);
    n.add("Jane", 2345678901);
    n.add("Jack", 3456789012);
    n.save("phonebook.txt");
}

void some_test(){
        notebook n;
    n.add("John", 123456789);
    n.add("Mary", 987654321);

    cout << n.find(123456789) << endl;
    cout << n.find("Mary") << endl;

    cout << "----------------" << endl;

    n.erase("John");
    cout << n.find(123456789) << endl;

    cout << n << endl;

    n.save("phonebook.txt");
    // n.load("phonebook.txt");
}

void test_save_file(){
    notebook n;

    n.add("John", 123456789);
    n.add("Mary", 987654321);

    n.save("phonebook.txt");
    cout << n;
}

void test_load_file(){
    notebook n1;

    n1.load("phonebook.txt");
    cout << n1;
}

int main(){
    // some_test();
    // test_save_file();
    // test_load_file();
    notebook n;
    n.load("phonebook.txt");
    cout << n;
    return 0;
}