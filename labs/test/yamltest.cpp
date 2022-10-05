#include "yaml-cpp/yaml.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("outfile.yaml");

    if (outfile.is_open() == 1)
    {
        cout << "Happy New Year" << endl;
    }
    else
    {
        cout << "Novogo goda ne budet" << endl;
    }

    std::map<std::string, int> ages;
    ages["Daniel"] = 26;
    ages["Jesse"] = 24;

    YAML::Emitter out;
    out << YAML::BeginSeq;
    out << YAML::Flow << ages;
    out << YAML::EndSeq;
    outfile << out.c_str();
    return 0;
}