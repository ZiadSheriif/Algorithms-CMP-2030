#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include<vector>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>vec(n, vector<ll>(m));
    vector<vector<ll>>maxPath(n,vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i ==0 &&j==0 )
            {
                maxPath[i][j] = vec[i][j];
            }
            else if (i == 0)
            {
                maxPath[i][j] = maxPath[i][j - 1] + vec[i][j];
            }
            else if (j == 0)
            {
                maxPath[i][j] = maxPath[i - 1][j] + vec[i][j];
            }
            else
            maxPath[i][j] = max(max(maxPath[i-1][j-1], maxPath[i - 1][j]), maxPath[i][j - 1]) + vec[i][j];//current position,right,bottom
            //cout << maxPath[i][j] << "-->";
        }
        //cout << endl;
    }
    
    cout << maxPath[n-1][m-1];
