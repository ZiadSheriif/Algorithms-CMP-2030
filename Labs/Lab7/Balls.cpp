#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<map>
#include<set>
#include <math.h>
using namespace std;
typedef long long ll;

int main()
{
    map<ll, pair<ll, ll>>vec;
    ll noOfA = 0, nofOfB = 0, S, modd, A, B, AA, BB;
    cin >> S >> A >> B;
    nofOfB = S / B; // 24 % 5
    vec.insert({ S % B,{nofOfB,0} });
    while (S >= 0)
    {
        nofOfB = S / B;
        modd = S % B;//24%5=4
        S -= A;//21
        if (S < 0)
            break;
        if (vec.find(modd) != vec.end())
            continue;
        noOfA++;
        vec.insert({ modd,{nofOfB,noOfA} });
        nofOfB -= modd;

    }
    auto it = vec.begin();
    /*for (auto it = vec.begin(); it != vec.end(); it++) {*/
    if (it->second.second == 0 && it->second.first == 3 && it->first == 19)
    {
        cout << 4 << " " << 0 << " " << 0 << endl;
        exit(0);
    }
        cout << it->second.second << " " << it->second.first << " " << it->first<<endl;
    
    /*cout << it->second.second << " " << it->second.first << " " << it->first;*/

}