#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
int dp[100000][2], score;

int dfs(int now, bool five)
{
    if (now == str.size())
    {
        return 0;
    }
    if (~dp[now][five])
        return dp[now][five];
    int res = 0;
    if (str[now] == '?')
    {
        res = 1 + dfs(now + 1, !five);
    }
    else if (str[now] == '2' && !five)
    {
        res = 1 + dfs(now + 1, !five);
    }
    else if (str[now] == '5' && five)
    {
        res = 1 + dfs(now + 1, !five);
    }
    score = max(score, dfs(now + 1, false));
    return dp[now][five] = res;
}

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> str;
    int ans = max(dfs(0, 0), score);
    cout << ans - (ans % 2) << "\n";
}