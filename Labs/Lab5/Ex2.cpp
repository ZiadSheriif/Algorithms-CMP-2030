#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include "climits"
#include <set>
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
long long getMedian(vector<long long> &sorted)
{
    sort(sorted.begin(), sorted.end());
    return (sorted[sorted.size() / 2]);
}
void FollowPath(Node *root, multiset<long long> Myset, ll &count, ll h)
{
    if (!root)
        return;
    Myset.insert(root->data);
    if (h % 2 != 0)
    {
        auto it = Myset.begin();
        advance(it, h / 2);
        if (*it == root->data)
            count++;
    }
    FollowPath(root->left, Myset, count, h + 1);
    FollowPath(root->right, Myset, count, h + 1);
}

int main()
{
    long long n, val, E, parent, child, R;
    char s;
    cin >> n;
    vector<Node *> temp(n);
    //vector<bool> check(n, 0);
    multiset<long long> Myset;
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
        //check[child] = 1;
    }
    long countt = 0;
    //cout<<inOrder(temp[0]->right,Sum);
    FollowPath(temp[0], Myset, countt, 1);
    cout << countt;
}