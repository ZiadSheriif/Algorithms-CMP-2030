#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
// This code is used for guidance (you can change it if you want).
struct Node
{
  int index;
  int rating;
  Node *parent; // this is optional
  vector<Node *> children;
};
map<Node *, ll> myMap;
ll maximumSum(Node *root)
{
  if (!root)
  {
    return 0;
  }
  if (myMap.find(root) != myMap.end())
  {
    return myMap[root];
  }
  ll tempChild = 0, tempPartentGch = 0;
  for (int i = 0; i < root->children.size(); i++)
  {

    tempChild += maximumSum(root->children[i]); // 2 3 6
    for (int j = 0; j < root->children[i]->children.size(); j++)
    {
      tempPartentGch += maximumSum(root->children[i]->children[j]); // 2 3 6                                                         //4 15 5 10
    }
  }
  tempPartentGch += root->rating;
  tempChild = max(tempPartentGch, tempChild);
  return myMap[root] = tempChild;
}

int main()
{

  // Number of nodes in the tree
  int N;
  cin >> N;

  vector<Node *> nodes(N);
  for (int i = 0; i < N; i++)
  {
    nodes[i] = new Node;
    nodes[i]->index = i;
    cin >> nodes[i]->rating;
  }

  // Iterating over all edges
  int parent, child;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> parent >> child;
    nodes[child]->parent = nodes[parent];
    nodes[parent]->children.push_back(nodes[child]);
  }
  // TODO: Create a vector called 'memo' used for memoization (What is the dimensions of that vector?)
  // then uncomment the following line.
  cout << maximumSum(nodes[0]);

  return 0;
}