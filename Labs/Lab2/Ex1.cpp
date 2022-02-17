#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

bool isValid(int i, int j, int k, int n)
{
    return i >= 0 && j >= 0 && k >= 0 && i < n && j < n && k < n;
}
void Boss_Lair(vector<vector<vector<int>>> Matrix, int n, int i, int j, int k, vector<vector<vector<bool>>> isVisited, int &MinGold, int currgold)
{
    if (!isValid(i, j, k, n) || isVisited[i][j][k])
        return;
    currgold += Matrix[i][j][k];
    if (i == n - 1 && j == n - 1 && k == n - 1)
        MinGold = min(MinGold, currgold);
    isVisited[i][j][k] = true;
    Boss_Lair(Matrix, n, i + 1, j, k, isVisited, MinGold, currgold);
    Boss_Lair(Matrix, n, i, j + 1, k, isVisited, MinGold, currgold);
    Boss_Lair(Matrix, n, i, j, k + 1, isVisited, MinGold, currgold);
    isVisited[i][j][k] = false;
}

int main()
{
    bool t = false;
    int c = INT_MAX, n = 5, X = 0;
    cin >> n;
    vector<vector<vector<int>>> mat(n, vector<vector<int>>(n, vector<int>(n)));
    vector<vector<vector<bool>>> isV(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> mat[i][j][k];
            }
        }
    }
    Boss_Lair(mat, n, 0, 0, 0, isV, c, X);
    cout << c;
}