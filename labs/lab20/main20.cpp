#include "lab20.h"
#include <iostream>

using namespace std;
// //Ориентированный граф задан и хранится списком смежности. 
// //В файле задается вершина, с которой начинается обход. 
// //Выписать прямые (ребра дерева обхода dfs), обратные ребра и поперечные ребра (не связывают предков и потомков).
 
int main()
{
    vector<int> history;
    vector<vector<int>> pairs_back; 
    graph g("text2.txt");
    // cout << g << endl;
    // g.dfs1(g.root);

    cout << endl;
    g.dfs2(g.root);

    // cout << endl;
    // g.dfs4(g.root, history, pairs_back);

    // cout << g << endl;

    // cout << "Back edges: " << endl;
    // for (int i = 0; i < pairs_back.size(); i++)
    // {
    //     cout << pairs_back[i][0] << " -> " << pairs_back[i][1] << endl;
    // }
    return 0;
}