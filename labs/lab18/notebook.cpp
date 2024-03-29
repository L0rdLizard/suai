#include "notebook.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// notebook :: notebook()
// {

// }

// notebook :: ~notebook()
// {

// }

void notebook :: add(const std::string &name, unsigned long phone)
{
    phonebook[name] = phone;
}

void notebook :: erase(const std::string &name)
{
    phonebook.erase(name);
}

std::string notebook :: find(unsigned long phone)
{
    for (auto it = phonebook.begin(); it != phonebook.end(); it++)
    {
        if (it->second == phone)
        {
            return (it->first);
        }
    }
    return ("");
}

unsigned int notebook :: find(const std::string& name)
{
    return phonebook[name];
}

std::ostream& operator<<(std::ostream& os, const notebook& n)
{
    for (auto it = n.phonebook.begin(); it != n.phonebook.end(); it++)
    {
        os << it->first << " " << it->second << endl;
    }
    return os;
}

void notebook :: load(const std::string& filename)
{
    ifstream file(filename);
    string name;
    unsigned long phone;
    while (file >> name >> phone)
    {
        phonebook[name] = phone;
    }
}

void notebook :: save(const std::string& filename)
{
    ofstream file(filename);
    for (auto it = phonebook.begin(); it != phonebook.end(); it++)
    {
        file << it->first << " " << it->second << endl;
    }
}


void notebook :: saveyaml(const std::string& filename)
{
    ofstream outfile;
    outfile.open("outfile.yaml");

    YAML::Emitter out;
    out << YAML::BeginSeq;

    for (auto it = phonebook.begin(); it != phonebook.end(); it++)
    {
        out << YAML::BeginMap;
        out << YAML::Key << "Name" << YAML::Value << it->first;
        out << YAML::Key << "Phone" << YAML::Value << it->second;
        out << YAML::EndMap;
    }
    out << YAML::EndSeq;
    outfile << out.c_str();
}

void notebook :: loadyaml(const std::string& filename)
{
    ifstream infile;
    infile.open("outfile.yaml");

    YAML::Node doc = YAML::LoadFile("outfile.yaml");

    for (unsigned i = 0; i < doc.size(); i++)
    {
        string name = doc[i]["Name"].as<string>();
        unsigned long phone = doc[i]["Phone"].as<unsigned long>();
        phonebook[name] = phone;
    }
}