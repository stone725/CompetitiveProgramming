#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    static const int INF = 1e9 + 7;
    int h, w;
    cin >> h >> w;
    vector<string> info(h);
    for (auto &&i : info)
    {
        cin >> i;
    }
    vector<vector<int>> dp(h + 1, vector<int>(w + 1));
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = INF;
    }
    for (int i = 0; i <= h; i++)
    {
        dp[i][0] = INF;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1)
            {
                dp[i][j] = dp[i][j - 1] + (info[i - 1][j - 2] == '#' && info[i - 1][j - 1] == '.');
                continue;
            }
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + (info[i - 2][j - 1] == '#' && info[i - 1][j - 1] == '.');
                continue;
            }
            int left = dp[i][j - 1] + (info[i - 1][j - 2] == '#' && info[i - 1][j - 1] == '.');
            int up = dp[i - 1][j] + (info[i - 2][j - 1] == '#' && info[i - 1][j - 1] == '.');
            dp[i][j] = min(left, up);
        }
    }
    cout << dp[h][w] + (info[h - 1][w - 1] == '#') << "\n";
}