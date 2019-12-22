#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n, d = 0, maxelement = 0;
vector<pair<int, int>> input;
vector<vector<int>> edge;
vector<int> deg;
map<pair<int, int>, int> mp;

void dfs(int now, int s)
{
    int cnt = 1;
    vector<bool> used(d, false);
    if (now != 0)
    {
        used[s - 1] = true;
    }
    for (auto &&i : edge[now])
    {
        for (int j = 1; j <= d; j++)
        {
            if (used[j - 1])
                continue;
            used[j - 1] = true;
            mp[make_pair(now, i)] = j;
            maxelement = max(maxelement, j);
            dfs(i, j);
            break;
        }
    }
}

int main()
{
    cin >> n;
    edge.resize(n);
    deg.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        input.push_back(make_pair(a - 1, b - 1));
        edge[a - 1].push_back(b - 1);
        deg[a - 1]++;
        deg[b - 1]++;
    }
    for (auto &&i : deg)
    {
        d = max(d, i);
    }
    dfs(0, 0);
    cout << maxelement << "\n";
    for (auto &&i : input)
    {
        cout << mp[i] << "\n";
    }
}
