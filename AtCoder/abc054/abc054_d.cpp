#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;
int n, ma, mb;
vector<tuple<int, int, int>> item;
map<tuple<int, int, int>, int> dp;

int dfs(int now, int a, int b)
{
    if (a && b && a % ma == 0 && b % mb == 0 && a / ma == b / mb)
    {
        return 0;
    }
    if (now == n)
    {
        return INF;
    }
    auto status = make_tuple(now, a, b);
    if (dp.count(status))
        return dp[status];
    return dp[status] = min(dfs(now + 1, a, b), dfs(now + 1, a + get<0>(item[now]), b + get<1>(item[now])) + get<2>(item[now]));
}

int main()
{
    cin >> n >> ma >> mb;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        item.push_back(make_tuple(a, b, c));
    }
    int ans = dfs(0, 0, 0);
    if (ans == INF)
    {
        ans = -1;
    }
    cout << ans << "\n";
}