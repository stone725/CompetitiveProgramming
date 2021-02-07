#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;

int h, w;
vector<vector<int>> a;
vector<vector<int>> dp;

int dfs(int x, int y)
{
    const static int dx[] = {1, 0, -1, 0};
    const static int dy[] = {0, -1, 0, 1};
    if (~dp[x][y])
        return dp[x][y];
    long long res = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a[x][y] < a[x + dx[i]][y + dy[i]])
        {
            res += dfs(x + dx[i], y + dy[i]);
            res %= INF;
        }
    }
    return dp[x][y] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    a.resize(h + 2, vector<int>(w + 2, -1));
    dp.resize(h + 2, vector<int>(w + 2, -1));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            ans += dfs(i, j);
            ans %= INF;
        }
    }
    cout << ans << "\n";
}