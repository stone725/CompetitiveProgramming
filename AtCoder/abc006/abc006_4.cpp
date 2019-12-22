#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n), dp(n, -1);
    for (auto &&i : c)
    {
        cin >> i;
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (c[j] < c[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = min(ans, n - dp[i]);
    }
    cout << ans << "\n";
}