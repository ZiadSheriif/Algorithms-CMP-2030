#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;
class BST
{
private:
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
    Node *root = nullptr;
    void addHelper(Node *temp, int val)
    {
        if (temp->data < val)
        {
            if (!temp->right)
                temp->right = new Node(val);
            else
            {
                addHelper(temp->right, val);
            }
        }
        else
        {
            if (!temp->left)
                temp->left = new Node(val);
            else
            {
                addHelper(temp->left, val);
            }
        }
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
        }
        else
            addHelper(root, val);
    }
    Node *getRoot()
    {
        return root;
    }
    void TreeBreadthFirst()
    {
        queue<Node *> q;
        q.push(this->root);
        while (q.empty() == false)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    void inOrder(Node *n)
    {

        if (!n)
            return;
        inOrder(n->left);
        cout << n->data << " ";
        inOrder(n->right);
    }
    bool search(Node *root, int key, int &s)
    {
        if (!root)
            return false;
        if (root->data == key)
        {
            s++;
            return true;
        }
        if (root->data < key)
        {
            s++;
            return search(root->right, key, s);
        }
        else
        {
            s++;
            return search(root->left, key, s);
        }
    }
};
// bool found(unordered_map<int, BST> &vec, int k, int id, int &sum)
// {
//     for (auto &i : vec)
//     {
//         if (i.first == k)
//         {
//             sum++;
//             if (i.second.search(i.second.getRoot(), id, sum))
//                 return true;
//             return false;
//         }
//         else
//             sum++;
//     }
//     return false;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int, BST> listt;
    int n, q, key, id;
    cin >> n >> q;
    BST *dep = new BST();
    while (n--)
    {
        cin >> key >> id;
        int dummy = 0;
        if (!dep->search(dep->getRoot(), key, dummy))
            dep->insert(key);
        listt[key].insert(id);
    }
    // for (auto x : listt)
    // {
    //     cout << x.first << ":";
    //     x.second.inOrder(x.second.getRoot());
    //     cout << endl;
    // }
    //cout << endl;
    int Sum;
    while (q--)
    {
        cin >> key >> id;
        Sum = 0;
        if (dep->search(dep->getRoot(), key, Sum))
        {
            if (dep->search(listt[key].getRoot(), id, Sum))
                cout << Sum << " " << 1;
            else
                cout << Sum << " " << 0;
        }
        else
            cout << Sum << " " << 0;
        cout << endl;
    }
}

/*Node* temp2 = temp;
	   if (!temp2)
		   return false;
	   if (temp2->data == x)
		   return true;
	   else
	   {
		   if (x > temp->data)
		   {
			   found(temp->right, x);
		   }
		   else
			   found(temp2->left, x);
	   }*/