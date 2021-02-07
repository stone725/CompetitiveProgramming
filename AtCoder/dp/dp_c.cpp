#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>

using namespace std;

const int INF = 1e9 + 7;

int n;
vector<array<int, 3>> happy;
int dp[100000][4];

int dfs(int now, int before)
{
    if (now == n)
        return 0;
    if (~dp[now][before])
        return dp[now][before];
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        if (before == i)
            continue;
        res = max(res, happy[now][i] + dfs(now + 1, i));
    }
    return dp[now][before] = res;
}

int main()
{
    cin >> n;
    happy.resize(n);
    memset(dp, -1, sizeof dp);
    for (auto &&i : happy)
    {
        for (auto &&j : i)
        {
            cin >> j;
        }
    }
    cout << dfs(0, 3) << "\n";
}
