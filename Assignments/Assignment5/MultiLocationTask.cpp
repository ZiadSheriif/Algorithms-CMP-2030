#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
typedef long long ll;

void DFSGraph(int v, vector<bool> &visited, stack<int> &Stack, vector<int> *graph)
{
    visited[v] = true;
    for (auto it = graph[v].begin(); it != graph[v].end(); it++)
        if (!visited[*it])
            DFSGraph(*it, visited, Stack, graph);
    Stack.push(v);
}
void topSort(vector<int> *Graph, stack<int> &s, vector<bool> &visited)
{
    for (int i = 0; i < visited.size(); i++)
        if (!visited[i])
            DFSGraph(i, visited, s, Graph);
}
int main()
{
    int n, v, u;
    cin >> n;
    vector<int> Graph[n];
    stack<int> S;
    vector<bool> isVisited(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v >> u;
        if (v != -1)
            Graph[v].push_back(i);
        if (u != -1)
            Graph[u].push_back(i);
    }
    topSort(Graph, S, isVisited);
    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Root: " << i << "-->";
    //     for (int j = 0; j < Graph[i].size(); j++)
    //     {
    //         cout << Graph[i][j] << ",";
    //     }
    // }
}
