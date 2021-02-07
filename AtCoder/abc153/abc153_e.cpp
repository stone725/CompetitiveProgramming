#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1000][10001] = {};

int main()
{
    int h, n;
    cin >> h >> n;
    vector<pair<int, int>> magic(n);
    for (auto &&i : magic)
    {
        cin >> i.first >> i.second;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= h; j++)
        {
            if (j <= magic[i].first)
            {
                if (i)
                {
                    dp[i][j] = min(dp[i - 1][j], magic[i].second);
                }
                else
                {
                    dp[i][j] = magic[i].second;
                }
            }
            else if (i)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - magic[i].first] + magic[i].second);
            }
            else
            {
                dp[i][j] = dp[i][j - magic[i].first] + magic[i].second;
            }
        }
    }
    cout << dp[n - 1][h] << "\n";
}