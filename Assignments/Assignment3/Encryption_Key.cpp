#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include "climits"
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->data = value;
        right = nullptr;
        left = nullptr;
    }
};
void inOrder(Node *n)
{

    if (!n)
        return;
    inOrder(n->left);
    cout << n->data << " ";
    inOrder(n->right);
}
int DFS(Node *root)
{
    int h = 0;
    if (root != NULL)
    {
        int lHeight = DFS(root->left);
        int rHeight = DFS(root->right);
        int maxHeight = max(lHeight, rHeight);
        h = maxHeight + 1;
    }
    return h;
}
int SumOfKLevel(Node *root, int L)
{
    if (!root)
        return 0;
    queue<Node *> Q;
    Q.push(root);
    int level = 0;
    int sum = 0;
    int flag = 0;
    while (!Q.empty())
    {
        int size = Q.size();
        while (size--)
        {
            Node *ptr = Q.front();
            Q.pop();
            if (level == L)
            {
                flag = 1;
                sum += ptr->data;
            }
            else
            {
                if (ptr->left)
                    Q.push(ptr->left);
                if (ptr->right)
                    Q.push(ptr->right);
            }
        }
        level++;
        if (flag == 1)
            break;
    }
    return sum;
}
int MinOfLevel(Node *root, int L)
{
    if (!root)
        return 0;
    queue<Node *> Q;
    Q.push(root);
    int level = 0;
    int Min = INT_MAX;
    int flag = 0;
    while (!Q.empty())
    {
        int size = Q.size();
        while (size--)
        {
            Node *ptr = Q.front();
            Q.pop();
            if (level == L)
            {
                flag = 1;
                if (Min > ptr->data)
                    Min = ptr->data;
            }
            else
            {
                if (ptr->left)
                    Q.push(ptr->left);
                if (ptr->right)
                    Q.push(ptr->right);
            }
        }
        level++;
        if (flag == 1)
            break;
    }
    return Min;
}
int main()
{
    int n, val, E, parent, child;
    char s;
    cin >> n;
    vector<Node *> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        Node *newNode = new Node(val);
        temp[i] = newNode;
    }
    cin >> E;
    vector<bool> check(n, 0);
    for (int i = 0; i < E; i++)
    {
        cin >> s >> parent >> child;
        if (s == 'L')
            temp[parent]->left = temp[child];
        else
            temp[parent]->right = temp[child];
        check[child] = 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (check[i] == false)
    //     {
    //         temp[0] = temp[i];
    //         break;
    //     }
    // }
    //    for(int i=0;i<temp.size();i++)
    //        cout<<temp[i]->data<<" ";
    //cout<<endl;
    int height = DFS(temp[0]);
    int L = temp[0]->data % height;
    int K = MinOfLevel(temp[0], L) % height;
    if (K == 0)
        K = 1;
    string result = "";
    for (int i = 0; i < height; i += K)
        result += to_string(SumOfKLevel(temp[0], i));
    cout << result;
}