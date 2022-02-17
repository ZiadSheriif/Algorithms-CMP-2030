#include <cmath>
#include <cstdio>
#include <vector>
#include<climits>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

// Note: you won't need long long in this problem
int solve(vector<int> &L, int i, int j, vector<vector<int>> &memo)
{
    // vector<vector<ll>>mem
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if (i + 1 == j)
    {
        return 0;
    }
    int Cost = INT_MAX;
    for (int z = i + 1; z < j; z++)
    {
        Cost = min(solve(L, i, z, memo) + solve(L, z, j, memo), Cost);
    }
    return memo[i][j]=Cost + (L[j] - L[i]);
}
// TODO: check if you solved the problem before (memoization) (add this part after you implement the whole function)

// TODO: step 2: add base case

// TODO: step 1: write the optimal structure for the solution using subproblems to get the minimum total cost

// TODO: save the minimum total cost in memo (add this part after you implement the whole function)

// TODO: return the minimum total costit

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> L(M);
    vector<vector<int>> memo(10002, vector<int> (10002,-1));

    for (int i = 0; i < M; i++)
    {
        cin >> L[i];
    }

    // TODO: uncomment the following if they help you solve the problem
    L.insert(L.begin(), 0);
    L.push_back(N);

    // TODO: declare DP storage and call it memo

    // This function call is for guidance and you can change it if you want
    cout << solve(L, 0, L.size() - 1, memo) << endl;

    return 0;
}