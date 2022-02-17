#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include "climits"
#include <map>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;
struct Node
{
    long long data;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->data = value;
        right = nullptr;
        left = nullptr;
    }
};
int SumOfNodes(Node *n, int sum)
{
    if (!n)
        return 0;
    SumOfNodes(n->left, sum);
    sum += n->data;
    SumOfNodes(n->right, sum);
    return sum;
}
long long getSum(Node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + getSum(root->left) + getSum(root->right));
}
int main()
{
    long long n, val, E, parent, child, R;
    char s;
    cin >> n >> R;
    vector<Node *> temp(n);
    vector<bool> check(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        Node *newNode = new Node(val);
        temp[i] = newNode;
    }
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> s >> parent >> child;
        if (s == 'L')
            temp[parent]->left = temp[child];
        else
            temp[parent]->right = temp[child];
        check[child] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            temp[0] = temp[i];
            break;
        }
    }
    long long count = 0, absolute = 0, Sum = 0;
    //cout<<inOrder(temp[0]->right,Sum);
    for (int i = 0; i < n; i++)
    {
        //absolute = abs(SumOfNodes(temp[i]->left, Sum) - SumOfNodes(temp[i]->right, Sum));
        absolute = abs(getSum(temp[i]->left) - getSum(temp[i]->right));
        if (absolute <= R)
            count++;
    }
    cout << count;
}