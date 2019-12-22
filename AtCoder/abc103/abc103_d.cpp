#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto &&i : a)
    {
        cin >> i.first >> i.second;
    }
    sort(begin(a), end(a), comp);
    int ans = 0, p = 0;
    for (auto &&i : a)
    {
        if (p < i.first)
        {
            p = i.second - 1;
            ans++;
        }
    }
    cout << ans << "\n";
}