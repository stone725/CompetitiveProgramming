#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

static const long long INF = 1ll << 60;

int n;
vector<int> a;
long long dp[100001][2];

long long dfs(int now, bool neg)
{
    if (now == n)
        return neg ? INF : 0;
    if (~dp[now][neg])
        return dp[now][neg];
    return dp[now][neg] = min(abs(-1 - a[now]) + dfs(now + 1, !neg), abs(1 - a[now]) + dfs(now + 1, neg));
}

int main()
{
    cin >> n;
    a.resize(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, false) << "\n";
}