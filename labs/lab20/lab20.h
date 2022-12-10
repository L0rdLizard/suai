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
    bool visited4;
};

class graph
{
private:
    std::map<int, gnode> nodes;

public:
    int root;
    graph(const string filename);
    friend std::ostream &operator<<(std::ostream &os, graph &gr);
    void dfs4(int cur, vector<int> &history, vector<vector<int>>& pairs);
    void dfs1(int cur);
    void dfs2(int cur);
    void dfs3(int cur);
};