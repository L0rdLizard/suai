#include "lab20.h"
#include <iostream>

using namespace std;
// //Ориентированный граф задан и хранится списком смежности. 
// //В файле задается вершина, с которой начинается обход. 
// //Выписать прямые (ребра дерева обхода dfs), обратные ребра и поперечные ребра (не связывают предков и потомков).
 
int main()
{
    graph g("text.txt");
    // cout << g << endl;
    string prefix = "";
    g.dfs1(g.root, prefix);
    cout << g << endl;
    return 0;
}