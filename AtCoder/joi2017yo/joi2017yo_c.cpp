#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, d;
vector<string> mp;

int cnt(int x, int y)
{
    int res = 0;
    if (y + d <= m)
    {
        res += mp[x].substr(y, d) == string(d, '.');
    }
    if (n < x + d)
        return res;
    for (int i = x; i < x + d; i++)
    {
        if (mp[i][y] != '.')
        {
            return res;
        }
    }
    res++;
    return res;
}

int main()
{
    cin >> n >> m >> d;
    mp.resize(n);
    for (auto &&i : mp)
    {
        cin >> i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += cnt(i, j);
        }
    }
    cout << ans << "\n";
}