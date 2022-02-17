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

bool search(vector<ll> &vec, ll key, ll &dum)
{
   auto temp= min_element(vec.begin(),vec.end());
    if (*temp >= key)
        return 1;
    dum = *temp;
    *temp = key;
    return 0;
}
int main()
{
    ll n, x;
    cin >> n;
    ll count = 0, dummy = 0;
    vector<pair<ll, ll>> mixed(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mixed[i] = {x, 0};
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mixed[i].second = x;
    }
    sort(mixed.begin(), mixed.end());
    vector<ll> tempVec;
    tempVec.push_back(mixed[0].second);
    for (int i = 1; i < n; i++)
    {
        if(mixed[i].first > tempVec.size())
        {
            tempVec.push_back(mixed[i].second);
            continue;
        }
        if (mixed[i].first != mixed[i - 1].first )
            tempVec.push_back(mixed[i].second);
        else
        {
            if (search(tempVec, mixed[i].second,dummy))
                count += mixed[i].second;
            else
                count += dummy;
        }
    }
    cout << count;
}