#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <numeric>
#include <sstream>
#include <chrono>
#include <string>
#include <vector>
using namespace std;
using namespace std::chrono;
int LinearProbling(vector<string> &temp, int exist)
{
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[(exist + i) % 24000] == "" || temp[(exist + i) % 24000] == "-1") //empty or deleted ,,SO insert in It :)
            return (exist + i) % 24000;
    }
    return -1;
    //Recursion takes along time ,,which there is no constant time
    // if (temp[exist % 24000] == "")
    //     return;
    // else
    // {
    //     exist++;
    //     LinearProbling(temp, exist);
    // }
}
int getKey(string s)
{
    if (s.size() == 1)
        return 39 * (int)s[0];
    else if (s.size() == 2)
        return 39 * (int)s[0] + 392 * (int)s[1];
    else if (s.size() == 3)
        return 39 * (int)s[0] + 392 * (int)s[1] + 393 * (int)s[2];
    else
        return 39 * (int)s[0] + 392 * (int)s[1] + 393 * (int)s[2] + 394 * (int)s[3];
}
bool Search(vector<string> &H, string target, int &probes, int K)
{
    for (int i = 0; i < H.size(); i++)
    {
        if (H[(K + i) % 24000] == "") //Target Not Found
        {
            probes = i;
            return false;
        }
        else if (H[(K + i) % 24000] == target)
        {
            probes = i;
            return true;
        }
    }
}
void Delete(vector<string> &H, string target, vector<int> &Vecprobes)
{
    int index = getKey(target);
    int probes = 0;
    //string S = H[index];
    if (Search(H, target, probes, index))
    {
        H[(index + probes) % 24000] = "-1";
        Vecprobes.push_back(probes);
    }
}
void HashingLP(vector<string> &H, vector<string> AA, int start, int end)
{
    int key;
    for (int i = start; i < end; i++)
    {
        key = getKey(AA[i]);
        H[LinearProbling(H, key)] = AA[i];
    }
    // if (AA[i].size() == 1)
    // {
    //     h1 = 39 * (int)AA[i][0];
    //     LinearProbling(H, h1);
    //     H[h1 % 24000] = AA[i][0];
    // }
    // else if (AA[i].size() == 2)
    // {
    //     h2 = 39 * (int)AA[i][0] + 392 * (int)AA[i][1];
    //     LinearProbling(H, h2);
    //     H[h2 % 24000] = AA[i];
    // }
    // else if (AA[i].size() == 3)
    // {
    //     h3 = 39 * (int)AA[i][0] + 392 * (int)AA[i][1] + 393 * (int)AA[i][2];
    //     LinearProbling(H, h3);
    //     H[h3 % 24000] = AA[i];
    // }
    // else
    // {
    //     hs = 39 * (int)AA[i][0] + 392 * (int)AA[i][1] + 393 * (int)AA[i][2] + 394 * (int)AA[i][3];
    //     LinearProbling(H, hs);
    //     H[hs % 24000] = AA[i];
    // }
}
void Print(vector<int> &avg)
{
    for (int i = 0; i < avg.size(); i++)
        cout << i + 1 << "-->(500): " << avg[i] << endl;
    long long sum = 0;
    // for (int i = 0; i < avg.size(); i++)
    //     sum += avg[i];
    // double average = sum * 1.0 / avg.size();
    cout << "Average Time: " << accumulate(avg.begin(), avg.end(), 0.0) / avg.size() << endl;
}
void Reading(vector<string> &A)
{
    ifstream read20k("words20k.txt");
    string s = "";
    if (!read20k)
        cout << "File is Empty" << endl;
    while (read20k >> s)
        A.push_back(s);
    read20k.close();
    // for (int i = 0; i < A.size(); i++)
    //     cout << A[i] << " ";
    // for (int i = 0; i < H.size(); i++)
    //     cout << H[i] << " ";
}

int main()
{
    vector<string> A;
    Reading(A);
    vector<string> H(24000, "");
    vector<int> avg;
    vector<int> No_probes;
    //vector<bool> deleted(24000, 0);
    int st, end;
    for (int i = 0; i < 40; i++)
    {
        st = i * 500, end = i * 500 + 500;
        auto start = high_resolution_clock::now();
        HashingLP(H, A, st, end);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        avg.push_back(duration.count());
    }
    Print(avg);
    for (int i = 14000; i < 15000; i++)
    {
        Delete(H, A[i], No_probes);
    }
    cout << "Minimum Number of Probes: " << *min_element(No_probes.begin(), No_probes.end()) << endl;
    cout << "Maximum Number of Probes: " << *max_element(No_probes.begin(), No_probes.end()) << endl;
    cout << "Average Number of Probes: " << accumulate(No_probes.begin(), No_probes.end(), 0.0) / No_probes.size() << endl;
}
