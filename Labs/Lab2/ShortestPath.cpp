#define _CRT_SECURE_NO_WARNINGS

#include "Libs.h"
using namespace std;

void shortestPath(vector<vector<int>> mat,
	vector<vector<bool>> isused, int n, int i, int j, int cost,
	int& min, vector<int>& curr, vector<int>& minP)
{
	// Use the cell
	isused[i][j] = true;
	cost += mat[i][j];
	curr.push_back(mat[i][j]);

	if (i == n - 1 && j == n - 1)
	{
		if (cost < min)
		{
			min = cost;
			minP = curr;
		}
	}
	else
	{
		if (i + 1 < n && !isused[i + 1][j])
			shortestPath(mat, isused, n, i + 1, j, cost, min, curr, minP);
		if (j + 1 < n && !isused[i][j + 1])
			shortestPath(mat, isused, n, i, j + 1, cost, min, curr, minP);
		if (i - 1 >= 0 && !isused[i - 1][j])
			shortestPath(mat, isused, n, i - 1, j, cost, min, curr, minP);
		if (j - 1 >= 0 && !isused[i][j - 1])
			shortestPath(mat, isused, n, i, j - 1, cost, min, curr, minP);
	}
	// undo
	isused[i][j] = false;
	//cost -= mat[i][j];
	curr.pop_back();
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	vector<vector<bool>> isused(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			isused[i][j] = false;
	vector<int> curr;
	vector<int> Min;
	int m = INT_MAX;
	shortestPath(mat, isused, n, 0, 0, 0, m, curr, Min);
	for (auto it = Min.begin(); it != Min.end(); it++)
		cout << *it << " ";
}