#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
bool check(vector<string> S)
{
    sort(S[0].begin(), S[0].end());
    string temp = S[0];
    for (int i = 1; i < S.size(); i++)
    {
        sort(S[i].begin(), S[i].end());
        if (S[i] != temp)
            return false;
    }
    return true;
}

void Shift(string &s)
{
    char temp = s[0];
    for (int i = 0; i < s.size() - 1; i++)
        s[i] = s[i + 1];
    s[s.size() - 1] = temp;
}
void String_re_arrangement(vector<string> S, int index, int &count, int n, int &Min, vector<string> Stemp, int i)
{
    if (index == n)
    {
        return;
    }
    else
    {
        while (i < n)
        {
            if (S[index] == S[i])
            {
                S[i] = Stemp[i];
                i++;
            }
            else
            {
                Shift(S[i]);
                count++;
            }
        }
        if (count < Min)
            Min = count;
        count = 0;
        String_re_arrangement(S, index + 1, count, n, Min, Stemp, 0);
    }
}

int main()
{
    bool t = false;
    int c = 0, n = 5, X = INT_MAX;
    cin >> n;
    vector<string> SS(n);
    vector<string> SStemp(n);
    for (string &k : SS)
        cin >> k;
    if (!check(SS))
    {
        cout << -1;
        exit(0);
    }
    SStemp = SS;
    String_re_arrangement(SS, 0, c, n, X, SStemp, 0);
    cout << X;
}