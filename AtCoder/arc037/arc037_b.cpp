#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> edge;
bool used[100];

bool dfs(int now, int before)
{
    if (used[now])
        return false;
    used[now] = true;
    for (auto &&i : edge[now])
    {
        if (i == before)
            continue;
        if (used[i])
        {
            return false;
        }
        if (!dfs(i, now))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    edge.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u - 1].push_back(v - 1);
        edge[v - 1].push_back(u - 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        ans += dfs(i, -1);
    }
    cout << ans << "\n";
}