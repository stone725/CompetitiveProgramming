#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int n, w;
vector<pair<int, int>> goods;

long long dp[100][100001];

long long dfs(int now, int weight)
{
    if (w < weight)
        return -INF;
    if (now == n)
        return 0;
    if (~dp[now][weight])
        return dp[now][weight];
    return dp[now][weight] = max(dfs(now + 1, weight), dfs(now + 1, weight + goods[now].first) + goods[now].second);
}

int main()
{
    cin >> n >> w;
    goods.resize(n);
    memset(dp, -1, sizeof dp);
    for (auto &&i : goods)
    {
        cin >> i.first >> i.second;
    }
    cout << dfs(0, 0) << "\n";
}