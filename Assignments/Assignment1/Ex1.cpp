#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>
using namespace std;
void Strings_difference(int n, int h, string S, int index)
{
    if (index == n)
    {
        int C = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '1')
                C++;
        if (C == h)
            cout << S << endl;
        return;
    }
    else
    {
        Strings_difference(n, h, S + '0', index + 1);
        Strings_difference(n, h, S + '1', index + 1);
    }
}

int main()
{
    int c = 0, mm;
    int n, k;
    string S = "";
    cin >> n >> k;
    Strings_difference(n, k, S, 0);
}