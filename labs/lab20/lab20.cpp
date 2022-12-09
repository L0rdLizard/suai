#include "lab20.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;

graph::graph(const string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        bool first_str = true;
        while (getline(file, line))
        {
            // cout << line << endl;
            if (first_str)
            {
                first_str = false;
                root = stoi(line);
                continue;
            }
            stringstream streamData(line);
            string val;

            const char separator = ',';
            bool first = true;
            int start_int = 0;
            while (getline(streamData, val, separator))
            {
                // cout << val << endl;
                if (first)
                {
                    first = false;
                    start_int = stoi(val);
                    nodes[start_int];
                    continue;
                }
                nodes[start_int].data.push_back(stod(val));
            }
        }
        file.close();
    }
}

ostream &operator<<(ostream &os, graph &gr)
{

    map<int, gnode>::iterator it = gr.nodes.begin();
    cout << "Root: " << gr.root << "\n";
    for (int i = 0; it != gr.nodes.end(); it++, i++)
    {
        cout << i << ") Key " << it->first << ", value "
             << "{ ";
        for (size_t t = 0; t < it->second.data.size(); t++)
            cout << it->second.data[t] << ", ";
        cout << "}\n";
    }
    return os;
}

void graph::dfs1(int cur, string &prefix)
{
    nodes[cur].visited = true;
    cout << prefix << " -> " << cur << "\n";
    for (int i = 0; i < nodes[cur].data.size(); i++)
    {
        if (nodes[nodes[cur].data[i]].visited == false)
        {
            string new_prefix = prefix + " -> " + to_string(cur);
            dfs1(nodes[cur].data[i], new_prefix);
        }
    }
}

void graph::dfs2(int cur, string &prefix)
{
    nodes[cur].visited = true;
    cout << prefix << " -> " << cur << "\n";
    for (int i = 0; i < nodes[cur].data.size(); i++)
    {
        if (nodes[nodes[cur].data[i]].visited == false)
        {
            string new_prefix = prefix + " -> " + to_string(cur);
            dfs2(nodes[cur].data[i], new_prefix);
        }
    }
}