#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Seats(int n, vector<string> S, int &count, int index, bool &test, vector<bool> &isVisited, vector<string> &curr)
{
    if (index == n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (curr[i][curr[i].size() - 1] == curr[i + 1][0])
            {
                test = false;
                break;
            }
        }
        if (test)
            count++;
        test = true;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!isVisited[i])
            {
                curr.push_back(S[i]);
                isVisited[i] = true;
                Seats(n, S, count, index + 1, test, isVisited, curr);
                isVisited[i] = false;
                curr.pop_back();
            }
        }
    }
}

int main()
{
    bool tt = true;
    int c = INT_MAX, n = 5, X = 0;
    cin >> n;
    vector<string> S(n);
    vector<string> Stemp;
    vector<bool> t(n, false);
    for (string &SS : S)
        cin >> SS;
    Seats(n, S, X, 0, tt, t, Stemp);
    cout << X;
}
