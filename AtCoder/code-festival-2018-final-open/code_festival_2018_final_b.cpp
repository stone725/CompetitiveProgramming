#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

int n, m;
vector<int> r;
vector<double> dp;

int main()
{
    cin >> n >> m;
    r.resize(m);
    dp.resize(n + 1);
    for (auto &&i : r)
    {
        cin >> i;
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + log10(i);
    }
    double cnt = -dp[n];
    for (auto &&i : r)
    {
        cnt += dp[i];
    }
    int ans = ceil(cnt + log10(m) * n);
    cout << ans << "\n";
}