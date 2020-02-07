#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    int sumtime = 0;
    cin >> n;
    vector<pair<string, int>> songlist(n);
    for (auto &&i : songlist)
    {
        cin >> i.first >> i.second;
        sumtime += i.second;
    }
    string x;
    cin >> x;
    int ans = sumtime;
    for (auto &&i : songlist)
    {
        ans -= i.second;
        if (i.first == x)
        {
            cout << ans << "\n";
            return 0;
        }
    }
}