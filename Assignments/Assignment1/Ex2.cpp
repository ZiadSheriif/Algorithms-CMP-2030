#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
void Arithmetic_expression_1(vector<int> &vec, bool &test, int currVal, int index)
{
    if (index == 6)
    {
        if (currVal == 27)
            test = true;
        return;
    }
    else
    {
        Arithmetic_expression_1(vec, test, currVal + vec[index], index + 1);
        Arithmetic_expression_1(vec, test, currVal - vec[index], index + 1);
        Arithmetic_expression_1(vec, test, currVal * vec[index], index + 1);
    }
}
int main()
{
    bool t = false;
    int c = 0, n = 5, k;
    vector<int> arr;
    while (n--)
    {
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 120; i++)
    {
        Arithmetic_expression_1(arr, t, arr[0], 1);
        next_permutation(arr.begin(), arr.end());
    }
    if (t)
        cout << "Possible";
    else
        cout << "Impossible";
}