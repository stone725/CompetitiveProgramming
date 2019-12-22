#include <iostream>
#include <vector>
#include <utility>
#include <bitset>

using namespace std;

int n, m;
bool edge[50][50];
vector<pair<int, int>> input;
bitset<50> b;
bool dfs(int x)
{
    b[x] = true;
    if (b.count() == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (edge[x][i] && !b[i])
        {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    input.resize(m);
    for (auto &&i : input)
    {
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
        edge[i.first][i.second] = edge[i.second][i.first] = true;
    }
    int ans = 0;
    for (auto &&i : input)
    {
        edge[i.first][i.second] = edge[i.second][i.first] = false;
        b.reset();
        ans += !dfs(0);
        edge[i.first][i.second] = edge[i.second][i.first] = true;
    }
    cout << ans << "\n";
}