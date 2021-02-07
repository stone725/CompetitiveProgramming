#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[101][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    static const int INF = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            dp[i + 1][j] = dp[i][j] + dp[i + 1][j - 1];
            dp[i + 1][j] %= INF;
            if (a[i] < j)
            {
                dp[i + 1][j] -= dp[i][j - a[i] - 1];
                if (dp[i + 1][j] < 0)
                {
                    dp[i + 1][j] += INF;
                }
            }
        }
    }
    cout << dp[n][k] << "\n";
}