#include <iostream>
#include <map>
#include <tuple>

using namespace std;

int a, b, c;
map<tuple<int, int, int, int>, int> dp;

int dfs(int l, int m, int r, int now)
{
    if (l == a && m == b && r == c)
    {
        return 1;
    }
    auto status = make_tuple(l, m, r, now);
    if (dp.count(status))
    {
        return dp[status];
    }
    if (l == a)
    {
        if (m == b)
        {
            return dfs(l, m, r + 1, now + 1);
        }
        else
        {
            if (m > r && r < c)
            {
                return dp[status] = dfs(l, m + 1, r, now + 1) + dfs(l, m, r + 1, now + 1);
            }
            else
            {
                return dp[status] = dfs(l, m + 1, r, now + 1);
            }
        }
    }
    if (m == b)
    {
        if (r == c)
        {
            return dp[status] = dfs(l + 1, m, r, now + 1);
        }
        else
        {
            return dp[status] = dfs(l + 1, m, r, now + 1) + dfs(l, m, r + 1, now + 1);
        }
    }
    if (r == c)
    {
        if (l > m)
        {
            return dp[status] = dfs(l + 1, m, r, now + 1) + dfs(l, m + 1, r, now + 1);
        }
        else
        {
            return dp[status] = dfs(l + 1, m, r, now + 1);
        }
    }
    dp[status] = dfs(l + 1, m, r, now + 1);
    if (l > m)
    {
        dp[status] += dfs(l, m + 1, r, now + 1);
    }
    if (m > r)
    {
        dp[status] += dfs(l, m, r + 1, now + 1);
    }
    return dp[status];
}

int main()
{
    cin >> a >> b >> c;
    cout << dfs(0, 0, 0, 1) << "\n";
}