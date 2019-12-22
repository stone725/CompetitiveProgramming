#include <iostream>
#include <cstring>

using namespace std;

int dp[10][10][101];

int dfs(int now, int use, int sum)
{
    if (use == 0 && sum == 0)
    {
        return 1;
    }
    if (use == 0 || now == 10 || sum < now)
    {
        return 0;
    }
    if (~dp[now][use][sum])
        return dp[now][use][sum];
    return dp[now][use][sum] = dfs(now + 1, use, sum) + dfs(now + 1, use - 1, sum - now);
}

int main()
{
    int n, s;
    memset(dp, -1, sizeof dp);
    while (cin >> n >> s && n)
    {
        cout << dfs(0, n, s) << "\n";
    }
}