#include "notebook.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
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

void some_test()
{
    notebook n;
    n.add("John", 123456789);
    n.add("Jane", 2345678901);
    n.add("Mary", 987654321);

    cout << n.find(123456789) << endl;
    cout << n.find("Mary") << endl;

    cout << "----------------" << endl;

    n.erase("John");
    cout << n.find(123456789) << endl;

    cout << "----------------" << endl;

    cout << n << endl;

    n.save("phonebook.txt");
    // n.load("phonebook.txt");
}

void some_test2(){
    notebook n;
    n.add("Sergey", 123456789);
    n.add("Max", 2345678901);
    n.add("Denis", 987654321);
    cout << n;
    cout << "----------------" << endl;
    cout << n.find(123456789) << endl;
    n.erase("Sergey");
    cout << "----------------" << endl;
    cout << n.find("Max") << endl;
    n.erase("Max");
    cout << "----------------" << endl;
    cout << n.find("Denis") << endl;
    cout << n;
}

void test_save_file()
{
    notebook n;

    n.add("John", 123456789);
    n.add("Mary", 987654321);

    n.save("phonebook.txt");
    cout << n;
}

void test_load_file()
{
    notebook n1;

    n1.load("phonebook.txt");
    cout << n1;
    cout << "----------------" << endl;
    n1.add("Jack", 3456789012);
    n1.add("Max", 2345678901);

    cout << n1;
}

void test_yaml()
{
    // vector<int> squares;
    // squares.push_back(1);
    // squares.push_back(4);
    // squares.push_back(9);
    // // squares.push_back(16);

    // ofstream outfile;
    // outfile.open("outfile.yaml");

    // if (outfile.is_open() == 1)
    // {
    //     cout << "Happy New Year" << endl;
    // }
    // else
    // {
    //     cout << "Novogo goda ne budet" << endl;
    // }

    // std::map<std::string, int> ages;
    // ages["Daniel"] = 26;
    // ages["Jesse"] = 24;

    // YAML::Emitter out;
    // out << YAML::BeginSeq;
    // out << YAML::Flow << ages;
    // out << YAML::EndSeq;
    // outfile << out.c_str();

    YAML::Node node;                        // starts out as null
    node["key"] = "value";                  // it now is a map node
    node["seq"].push_back("first element"); // node["seq"] automatically becomes a sequence
    node["seq"].push_back("second element");
}

int main()
{
    // some_test();
    // test_save_file();
    // test_load_file();
    // notebook n;
    // n.load("phonebook.txt");
    // cout << n;
    // test_yaml();

    // notebook n;
    // some_test();
    // test_load_file();
    some_test2();
    // notebook n2;

    // n.add("John", 123456789);
    // n.add("Mary", 987654321);
    // n.saveyaml("outfile.yaml");

    // n2.loadyaml("outfile.yaml");
    // cout << n2 << endl;
    return 0;
}