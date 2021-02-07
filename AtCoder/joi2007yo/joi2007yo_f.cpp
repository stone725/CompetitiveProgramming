#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int dp[17][17];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 17; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    dp[1][1] = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x][y] = 0;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (~dp[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[a][b] << "\n";
}