#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int n, w;
vector<pair<int, int>> goods;

long long dp[101][100001];

int main()
{
    cin >> n >> w;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            dp[i][j] = 1ll << 60;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        for (int j = 0; j <= 100000; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (v <= j)
            {
                dp[i + 1][j] = min(dp[i + 1][j], w + dp[i][j - v]);
            }
        }
    }

    for (int i = 100000; i >= 0; i--)
    {
        if (dp[n][i] <= w)
        {
            cout << i << "\n";
            return 0;
        }
    }
}