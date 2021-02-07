#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

static const long long INF = 1ll << 50;
int n, m;
map<pair<int, int>, long long> dp;
vector<int> money;
vector<int> key;

long long dfs(int now, int bit)
{
    if (bit == ((1 << n) - 1))
    {
        return 0;
    }
    if (now == m)
    {
        return INF;
    }
    auto status = make_pair(now, bit);
    if (dp.count(status))
        return dp[status];
    return dp[status] = min(dfs(now + 1, bit | key[now]) + money[now], dfs(now + 1, bit));
}

int main()
{
    cin >> n >> m;
    money.resize(m);
    key.resize(m);
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> money[i] >> b;
        for (int j = 0; j < b; j++)
        {
            int c;
            cin >> c;
            key[i] += (1 << (c - 1));
        }
    }
    long long ans = dfs(0, 0);
    if (INF == ans)
    {
        ans = -1;
    }
    cout << ans << "\n";
}