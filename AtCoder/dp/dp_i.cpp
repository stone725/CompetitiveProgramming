#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <utility>

using namespace std;

int n;
vector<long double> p;
map<pair<int, int>, long double> dp;

long double dfs(int now, int cnt)
{
    if (n < cnt * 2)
    {
        return 1;
    }
    if ((n - now + cnt) * 2 <= n)
    {
        return 0;
    }
    auto status = make_pair(now, cnt);
    if (dp.count(status))
        return dp[status];
    return dp[status] = p[now] * dfs(now + 1, cnt + 1) + (1 - p[now]) * dfs(now + 1, cnt);
}

int main()
{
    cin >> n;
    p.resize(n);
    for (auto &&i : p)
    {
        cin >> i;
    }
    cout << fixed << setprecision(10) << dfs(0, 0) << "\n";
}