#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> edge;
vector<int> dp;

int dfs(int p)
{
    if (~dp[p])
        return dp[p];
    int res = 0;
    for (auto &&i : edge[p])
    {
        res = max(1 + dfs(i), res);
    }
    return dp[p] = res;
}

int main()
{
    cin >> n >> m;
    edge.resize(n);
    dp.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (~dp[i])
            continue;
        ans = max(ans, dfs(i));
    }
    cout << ans << "\n";
}