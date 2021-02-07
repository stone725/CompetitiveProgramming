#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<long long> dp[2];

long long dfs(bool neg, int now)
{
    if (now == n - 1)
        return neg ? a[now] : -a[now];
    if (dp[neg][now] != -(1ll << 60))
    {
        return dp[neg][now];
    }
    long long res;
    if (neg)
    {
        res = max(a[now] + dfs(true, now + 1), -a[now] + dfs(false, now + 1));
    }
    else
    {
        res = max(a[now] + dfs(false, now + 1), -a[now] + dfs(true, now + 1));
    }
    return dp[neg][now] = res;
}

int main()
{
    cin >> n;
    a.resize(n);
    dp[0].resize(n, -(1ll << 60));
    dp[1].resize(n, -(1ll << 60));
    for (auto &&i : a)
    {
        cin >> i;
    }
    cout << dfs(true, 0) << "\n";
}