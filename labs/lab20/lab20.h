#pragma once
#include <map>
#include <vector>
#include <ostream>
#include <string>
using namespace std;

struct gnode
{
    vector<int> data;
    bool visited;
};

class graph
{
private:
    std::map<int, gnode> nodes;
    int root;

public:
    graph(const string filename);
    friend std::ostream& operator<<(std::ostream& os, graph& gr);
};