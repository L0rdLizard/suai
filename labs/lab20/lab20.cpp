#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
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
    graph(const string filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string line;
            bool first_str = true;
            while (getline(file, line))
            {
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
};