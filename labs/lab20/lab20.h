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

public:
    int root;
    graph(const string filename);
    friend std::ostream &operator<<(std::ostream &os, graph &gr);
    void dfs1(int cur, string &prefix);
    void dfs2(int cur, string &prefix);
};