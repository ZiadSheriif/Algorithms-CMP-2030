#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> jumps(2, vector<ll>(n));
    vector<vector<ll>> dp(2, vector<ll>(n));
    if (n == 0)
    {
        cout << 0;
        exit(0);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> jumps[i][j];
        }
    }
    ll maxROw0 = LONG_LONG_MIN;
    ll maxRow1 = LONG_LONG_MIN;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = jumps[i][j]; // 9
                maxROw0 = jumps[i][j];
            }
            else if (i == 1 && j == 0) // first col ,, second row
            {
                dp[i][j] = jumps[i][j];
                maxRow1 = dp[i][j];
            }
            else if (i == 0) //first row
            {
                maxRow1 = max<ll>(dp[i + 1][j - 1], maxRow1);

                dp[i][j] = jumps[i][j] + maxRow1;
            }
            else if (i == 1) //second row
            {
                maxROw0 = max<ll>(dp[i - 1][j - 1], maxROw0);
                dp[i][j] = jumps[i][j] + maxROw0;
            }
        }
    }
    ll maxResult = LONG_LONG_MIN;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxResult = max<ll>(dp[i][j], maxResult);
        }
    }
    cout << maxResult;
    //cout << dp[1][n - 1];
}