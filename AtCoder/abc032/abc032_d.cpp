#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
int n, w;
vector<pair<int, long long>> lug;

map<tuple<int, unsigned long long>, unsigned long long> dp;

vector<vector<long long>> dp2;

unsigned long long dfs(int now, unsigned long long weight)
{
    if (now == n)
        return 0;
    auto status = make_tuple(now, weight);
    if (dp.count(status))
        return dp[status];
    unsigned long long res = dfs(now + 1, weight);
    if (weight >= lug[now].second)
    {
        res = max(res, lug[now].first + dfs(now + 1, weight - lug[now].second));
    }
    return dp[status] = res;
}

unsigned long long dfs2(int now, int weight)
{
    if (now == n)
        return 0;
    if (w < weight)
        return -INF;
    if (dp2[now][weight] != -1)
        return dp2[now][weight];
    unsigned long long res = dfs2(now + 1, weight);
    if (weight + lug[now].second <= w)
    {
        res = max(res, lug[now].first + dfs2(now + 1, weight + lug[now].second));
    }
    return dp2[now][weight] = res;
}

void solve()
{
    cin >> n >> w;
    int m = w;
    bool flag = true, flag2 = true;
    lug.resize(n);
    for (auto &&i : lug)
    {
        cin >> i.first >> i.second;
        if (1000 < i.first)
            flag2 = false;
    }
    if (n <= 30)
    {
        cout << dfs(0, w) << "\n";
    }
    else if (!flag2)
    {
        dp2.resize(n, vector<long long>(n * 1000, -1));
        cout << dfs2(0, 0) << "\n";
    }
    else
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(n * 1000 + 1));
        for (int i = 1; i <= n * 1000; i++)
        {
            dp[0][i] = INF;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n * 1000; j++)
            {
                if (j >= lug[i - 1].first)
                {
                    dp[i][j] = min(dp[i - 1][j], lug[i - 1].second + dp[i - 1][j - lug[i - 1].first]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (dp[i][j] <= w)
                {
                    ans = max(ans, j);
                }
            }
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}