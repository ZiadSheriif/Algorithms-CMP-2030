#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include "climits"
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <list>
using namespace std;
typedef long long ll;
int main()
{
    int d, n, m, val, count = 0;
    cin >> n >> d >> m;
    unordered_map<int, vector<int>> Map;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        Map[val].push_back(i);
    }
    for (auto it = Map.begin(); it != Map.end(); it++) // 1 1 3 3 5
    {
        int tempp = it->first + d; //3
        for (int aa = 0; aa < it->second.size(); aa++)
        {
            for (auto j = Map.begin(); j != Map.end(); j++)
            {
                if (j->first == tempp) //3
                {
                    for (int i = 0; i < j->second.size(); i++)
                    {
                        if (j->second[i] > it->second[aa]) // 2 > 0
                        {
                            if (m == 3)
                            {
                                int temp2 = j->first + d; //5
                                for (auto z = Map.begin(); z != Map.end(); z++)
                                {
                                    if (z->first == temp2)
                                    {
                                        for (int zz = 0; zz < z->second.size(); zz++)
                                        {
                                            if (j->second[i] < z->second[zz])
                                                count++;
                                        }
                                    }
                                }
                            }
                            else
                                count++;
                        }
                    }
                }
            }
        }
    }
    cout << count;
    // for (auto i = Map.begin(); i != Map.end(); i++)
    // {
    //     cout << i->first << "--> ";
    //     for (int j = 0; j < i->second.size(); j++)
    //         cout << i->second[j] << " ";
    //     cout << endl;
    // }
    // cout << Map1.size();
}
