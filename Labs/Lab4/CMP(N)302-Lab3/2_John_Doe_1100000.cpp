#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// Helper function
void preprocess(string &str)
{
    // Removing punctuation
    for (int i = 0, len = str.size(); i < len; i++)
    {
        // Check whether parsing character is punctuation or not
        if (ispunct(str[i]))
        {
            str.erase(i--, 1);
            len = str.size();
        }
    }

    // Converting to lower case
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Helper function
vector<string> readFile()
{
    ifstream f("two-cities.txt"); //taking file as inputstream

    string file;

    if (f)
    {
        ostringstream ss;
        ss << f.rdbuf(); // reading data
        file = ss.str();

        // Removes punctuation and converts to lower case
        preprocess(file);

        // Split into tokens on space
        istringstream iss(file);
        vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};

        return tokens;
    }

    vector<string> empty;
    return empty;
}
// TODO: IMPLEMENT THIS FUNCTION
string findSecret(vector<string> tokens)
{
    // Hint: you can use std::unordered_map and std::sort
    unordered_map<string, int> MyMap;
    vector<int> FreqWords = {11, 23, 22, 43, 3, 47};
    vector<pair<int, string>> temp;
    string result = "";
    for (int i = 0; i < tokens.size(); i++)
    {
        if (MyMap.find(tokens[i]) != MyMap.end()) //founded
            MyMap[tokens[i]]++;
        else
            MyMap[tokens[i]] = 1;
    }
    for (auto j = MyMap.begin(); j != MyMap.end(); j++)
        temp.push_back({j->second, j->first});
    sort(temp.rbegin(), temp.rend());
    for (int i = 0; i < FreqWords.size(); i++)
    {
        result += temp[FreqWords[i] - 1].second;
        result += " ";
    }
    // for (auto it = MyMap.begin(); it != MyMap.end(); it++)
    //     cout << it->first << " " << it->second << endl;
    return result;
}

int main()
{
    vector<string> tokens = readFile();

    cout << findSecret(tokens) << endl;

    return 0;
}
