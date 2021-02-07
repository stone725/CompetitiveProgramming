#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, long long> mp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        sort(begin(str), end(str));
        mp[str]++;
    }
    long long ans = 0;
    for (auto &&i : mp)
    {
        ans += i.second * (i.second - 1) / 2;
    }
    cout << ans << "\n";
}