#include <iostream>
#include <cstring>

using namespace std;

long long dp[101][10][1001];

long long dfs(int now, int select, int score)
{
    if (select == 0)
    {
        return score == 0;
    }
    if (score == 0)
    {
        return select == 1 && now == 0;
    }
    if (100 < now)
        return 0;
    if (~dp[now][select][score])
        return dp[now][select][score];
    return dp[now][select][score] = dfs(now + 1, select, score) + dfs(now + 1, select - 1, score - now);
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