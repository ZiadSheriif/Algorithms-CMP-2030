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
int check(vector<vector<ll>> &vec, int i, int j, int c, int r)
{
    if (i >= r || j >= c || vec[i][j] == -1)
        return 0;
    if (i == r - 1 && j == c - 1)
        return 1;
    return 10;
}
ll solve(vector<vector<ll>> &Path, int r, int c, vector<vector<ll>> &memo, int i, int j)
{
    if (!check(Path, i, j, c, r))
        return 0;
    if (check(Path, i, j, c, r) == 1)
        return 1;

    if (memo[i][j] != -10)
        return memo[i][j];
    memo[i][j] = solve(Path, r, c, memo, i + 1, j) + solve(Path, r, c, memo, i, j + 1);
    return memo[i][j];
}
int main()
{
    ll r, c;
    cin >> r >> c;
    vector<vector<ll>> Path(r, vector<ll>(c));
    vector<vector<ll>> memo(r, vector<ll>(c, -10));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> Path[i][j];
        }
    }

    solve(Path, r, c, memo, 0, 0);
    //  for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << memo[i][j] << "-->";
    //     }
    //     cout << endl;
    // }
    cout << memo[0][0];
}