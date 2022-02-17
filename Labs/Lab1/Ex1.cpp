#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void RecString(vector<string> &Str, int n, int m, int k, int &count, string seq, char *chars)
{
    if (seq.length() == n)
    {
        int c = 0;
        for (int i = 0; i < m; i++)
        {
            if (seq.find(Str[i]) != string::npos)
                c++;
        }
        if (c >= k)
            count++;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        RecString(Str, n, m, k, count, seq + chars[i], chars);
    }
}
int main()
{
    int N, M, K, C = 0;
    char chars[5] = {'A', 'B', 'C', 'D', 'E'};
    cin >> M >> N >> K;
    vector<string> S(M);
    string SEQ;
    for (int i = 0; i < M; i++)
        cin >> S[i];
    RecString(S, N, M, K, C, SEQ, chars);
    cout << C;
}
