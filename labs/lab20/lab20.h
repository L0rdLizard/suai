#pragma once
#include <map>
#include <vector>
#include <ostream>
#include <string>
using namespace std;

struct gnode
{
    vector<int> data;
    vector<int> parent;
    bool have_parent;
    bool visited;
    bool visited2;
    bool visited3;
};

class graph
{
private:
    std::map<int, gnode> nodes;

public:
    int root;
    graph(const string filename);
    friend std::ostream &operator<<(std::ostream &os, graph &gr);
    void dfs1(int cur);
    void dfs2(int cur);
    void dfs3(int cur);
};