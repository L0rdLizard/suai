#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <stdexcept>
#include <vector>

using namespace std;

enum class EdgeType
{
    TREE,
    BACK,
    CROSS
};

class Graph
{
private:
    vector<vector<int>> adj; // список смежности
    vector<int> depth;       // глубина вершины
    vector<int> parent;      // родитель вершины
    int root;                // корень дерева обхода

    map<pair<int, int>, EdgeType> edges;

public:
    Graph(string filename)
    {
        ifstream fin(filename);
        if (!fin.is_open())
            throw runtime_error("File not found");
        fin >> root;
        // cout << root << endl;
        adj.resize(0);

        while (!fin.eof())
        {
            vector<int> row;
            int x;
            while (fin >> x)
            {
                if (x == -1)
                    break;
                row.push_back(x);
                if (fin.peek() == '\n')
                    break;
            }
            adj.push_back(row);
        }

        depth.resize(adj.size());
        parent.resize(adj.size());
    }

    void _getEdgesDFS(int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                depth[i] = depth[v] + 1;
                parent[i] = v;
                edges.insert({{v, i}, EdgeType::TREE});
                _getEdgesDFS(i, visited);
            }
            else
            {
                if (edges.find({v, i}) == edges.end())
                {
                    int a = v, b = i;
                    while (depth[b] > depth[a])
                        b = parent[b];
                    while (depth[a] > depth[b])
                        a = parent[a];
                    if (a == b)
                    {
                        edges.insert({{v, i}, EdgeType::BACK});
                    }
                    else
                    {
                        edges.insert({{v, i}, EdgeType::CROSS});
                    }
                }
            }
        }
    }

    void getEdgesDFS()
    {
        vector<bool> visited(adj.size(), false);
        depth[root] = 0;
        parent[root] = -1;
        _getEdgesDFS(root, visited);
    }

    void printEdges()
    {
        for (auto edge : edges)
        {
            int a = edge.first.first, b = edge.first.second;
            switch (edge.second)
            {
            case EdgeType::TREE:
                cout << a << " --> " << b << " tree" << endl;
                break;
            case EdgeType::BACK:
                cout << b << " <-- " << a << " back" << endl;
                break;
            case EdgeType::CROSS:
                cout << a << " <-> " << b << " cross" << endl;
                break;
            }
        }
    }

    void exportGraphviz(string filename)
    {
        ofstream fout(filename);
        if (!fout.is_open())
            throw runtime_error("File not found");
        fout << "digraph G {" << endl;
        for (auto edge : edges)
        {
            int a = edge.first.first, b = edge.first.second;
            switch (edge.second)
            {
            case EdgeType::TREE:
                fout << "  " << a << " -> " << b << " [color=black]" << endl;
                break;
            case EdgeType::BACK:
                fout << "  " << a << " -> " << b << " [color=blue]" << endl;
                break;
            case EdgeType::CROSS:
                fout << "  " << a << " -> " << b << " [color=red]" << endl;
                break;
            }
        }
        fout << "}";
    }
};

int main()
{
    Graph g("text2.txt");
    g.getEdgesDFS();
    g.printEdges();
    g.exportGraphviz("graph.gv");
    return 0;
}