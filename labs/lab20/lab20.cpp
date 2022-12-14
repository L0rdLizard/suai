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
                // nodes[stod(val)].parent.push_back(start_int);
                // nodes[stod(val)].have_parent = true;
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

// void graph::dfs1(int cur)
// {
//     nodes[cur].visited = true;
//     for (int i = 0; i < nodes[cur].data.size(); i++)
//     {
//         if (nodes[nodes[cur].data[i]].visited == false)
//         {
//             cout << cur << " -> " << nodes[cur].data[i] << "\n";
//             dfs1(nodes[cur].data[i]);
//         }

//     }
// }

// void graph::dfs2(int cur)
// {
//     nodes[cur].visited = true;
//     for (int i = 0; i < nodes[cur].data.size(); i++)
//     {
//         if (nodes[nodes[cur].data[i]].data.size() != 0)
//         {
//             for (int j = 0; j < nodes[nodes[cur].data[i]].data.size(); j++)
//             {
//                 if (nodes[nodes[nodes[cur].data[i]].data[j]].visited2 == false)
//                 {
//                     cout << nodes[nodes[cur].data[i]].data[j] << " -> " << cur << "\n";
//                     int temp_cur = cur;
//                     while (nodes[temp_cur].have_parent == true)
//                     {
//                         for (int k = 0; k < nodes[temp_cur].parent.size(); k++)
//                         {
//                             cout << nodes[nodes[cur].data[i]].data[j] << " -> " << nodes[temp_cur].parent[k] << "\n";
//                         }
//                         temp_cur = nodes[temp_cur].parent[0];
//                     }
//                 }
//             }
//         }
//         dfs2(nodes[cur].data[i]);
//     }
// }

// void graph::dfs4(int cur, vector<int> &history, vector<vector<int>> &pairs)
// {
//     nodes[cur].visited4 = true;

//     if (history.size() > 1)
//     {
//         for (int j = 0; j < history.size() - 1; j++)
//         {
//             vector<int> pair;
//             pair.push_back(history[j]);
//             pair.push_back(cur);
//             pairs.push_back(pair);
//             // cout << history[j] << " -> " << cur << "\n";
//         }
//     }

//     for (int i = 0; i < nodes[cur].data.size(); i++)
//     {
//         if (nodes[nodes[cur].data[i]].visited4 == false)
//         {
//             cout << cur << " -> " << nodes[cur].data[i] << "\n";
//             // cout << history.size() << endl;

//             vector<int> temp_history = history;
//             temp_history.push_back(cur);
//             dfs4(nodes[cur].data[i], temp_history, pairs);
//         }
//     }

//     // for (int i = 0; i < nodes[cur].data.size(); i++)
//     // {

//     // }
//     return;
// }

// void graph::dfs5(int cur, vector<int> &history, vector<int> &dots)
// {
//     dots.push_back(cur);
//     for (int i = 0; i < nodes[cur].data.size(); i++)
//     {
//         cout << cur << " -> " << nodes[cur].data[i] << "\n";

//         if (nodes[cur].data.size() != 0)
//         {
//             history.push_back(cur);
//         }

//         for

        
//         dfs5(nodes[cur].data[i], history, dots);

//         // cout "love you" << end;
//         // хихи)
//     }

//     // for (int i = 0; i < nodes[cur].data.size(); i++)
//     // {

//     // }
//     return;
// }

