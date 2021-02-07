#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;

int w, n, k;
vector<pair<int, int>> screenshots;
int dp[50][50][10001];

int dfs(int now, int selected, int width)
{
    if (w < width)
    {
        return -INF;
    }
    if (now == n || selected == k)
    {
        return 0;
    }
    if (~dp[now][selected][width])
        return dp[now][selected][width];
    return dp[now][selected][width] = max(dfs(now + 1, selected, width), screenshots[now].second + dfs(now + 1, selected + 1, width + screenshots[now].first));
}

int main()
{
    cin >> w;
    cin >> n >> k;
    screenshots.resize(n);
    for (auto &&i : screenshots)
    {
        cin >> i.first >> i.second;
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0, 0) << "\n";
}