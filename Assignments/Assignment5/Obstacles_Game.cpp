#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;
ll count = 0;
// int main()
// {
//     ll r, c;
//     cin >> r >> c;
//     vector<vector<ll>> maxPath(r, vector<ll>(c));
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             cin >> maxPath[i][j];
//         }
//     }

//     for (int i = 0; i < r; i++)
//     {
//         if (maxPath[i][0] == 0)
//             maxPath[i][0] = 1;
//         else
//             break;
//     }
//     for (int j = 1; j < c; j++)
//     {
//         if (maxPath[0][j] == 0)
//             maxPath[0][j] = 1;
//         else
//             break;
//     }

//     for (int i = 1; i < r; i++)
//     {
//         for (int j = 1; j < c; j++)
//         {
//             if (maxPath[i][j] == -1)
//                 continue;

//             if (maxPath[i - 1][j] > 0)
//                 maxPath[i][j] = (maxPath[i][j] + maxPath[i - 1][j]);

//             if (maxPath[i][j - 1] > 0)
//                 maxPath[i][j] = (maxPath[i][j] + maxPath[i][j - 1]);
//         }
//     }
//     cout << maxPath[r - 1][c - 1];
//     // ll maxRe = LLONG_MIN;
//     // for (int i = 0; i < r; i++)
//     // {
//     //     for (int j = 0; j < c; j++)
//     //     {
//     //         maxRe = max(maxRe, maxPath[i][j]);
//     //     }
//     // }
//     // cout << maxRe;
//     // cout << endl;
//     // for (int i = 0; i < r; i++)
//     // {
//     //     for (int j = 0; j < c; j++)
//     //     {
//     //         cout << maxPath[i][j] << "-->";
//     //     }
//     //     cout << endl;
//     // }
//}
#include <bits/stdc++.h>
using namespace std;

//function for adding edge
void add(int v, int w, vector<int> graph[])
{
    graph[v].push_back(w);
}

//bfs traversal fot getting topological sorted order
void bfs(vector<int> graph[], int i, vector<bool> &vis, stack<int> &s)
{
    vis[i] = true;
    for (auto v : graph[i])
    {
        if (!vis[v])
            bfs(graph, v, vis, s);
    }
    s.push(i);
}

//get the topological sort and build the array
vector<int> topologicalSort(vector<int> graph[], int V)
{
    stack<int> s;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            bfs(graph, i, vis, s);
    }
    vector<int> temp(V);
    int i = 0;
    while (!s.empty())
    {
        temp[i++] = s.top();
        s.pop();
    }
    return temp;
}

void getMaximumEdges(vector<int> graph[], int V)
{
    vector<int> temp = topologicalSort(graph, V);
    vector<bool> vis(V, false);
    for (int i = 0; i < temp.size(); i++) //traversing the topological sorted array
    {
        int t = temp[i];
        for (auto j = graph[t].begin(); j != graph[t].end(); j++)
            vis[*j] = true;
        for (int j = i + 1; j < temp.size(); j++) //see the rest array for finding edges
        {
            if (!vis[temp[j]]) //if the element is not adjacent then add edge
                cout << t << "->" << temp[j] << " ";

            vis[temp[j]] = false;
        }
        cout << endl;
    }
}

int main()
{
    //build the graph
    int V = 6;
    vector<int> graph[V];
    add(0, 1, graph);
    add(0, 3, graph);
    add(1, 2, graph);
    add(3, 2, graph);
    add(2, 5, graph);
    add(3, 4, graph);
    add(4, 5, graph);

    getMaximumEdges(graph, V);

    return 0;
}
