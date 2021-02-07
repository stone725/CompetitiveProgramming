#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
vector<int> h;
long long dp[301][301][301];

long long dfs(int now, int cnt, short p)
{
    if (n < now)
    {
        return 0;
    }
    if (~dp[now][cnt][p])
        return dp[now][cnt][p];
    dp[now][cnt][p] = dfs(now + 1, cnt, now) + max(0, h[now] - h[p]);
    if (cnt < k)
    {
        dp[now][cnt][p] = min(dp[now][cnt][p], dfs(now + 1, cnt + 1, p));
    }
    return dp[now][cnt][p];
}

int main()
{
    cin >> n >> k;
    h.resize(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(1, 0, 0) << "\n";
}