#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    int maxnum = 0;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        mp[str]++;
        maxnum = max(maxnum, mp[str]);
    }
    for (auto &&i : mp)
    {
        if (i.second == maxnum)
        {
            cout << i.first << "\n";
        }
    }
}