#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>

using namespace std;

int n, x, y;
static const int INF = 1e9 + 7;
vector<vector<int>> edge;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    edge.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        edge[i].push_back(i + 1);
        edge[i + 1].push_back(i);
    }
    edge[x - 1].push_back(y - 1);
    edge[y - 1].push_back(x - 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.clear();
        for (auto &&j : edge[i])
        {
            pq.push(make_pair(1, j));
        }
        s.insert(i);
        while (pq.size())
        {
            auto info = pq.top();
            pq.pop();
            if (s.count(info.second))
            {
                continue;
            }
            ans[info.first]++;
            s.insert(info.second);
            for (auto &&j : edge[info.second])
            {
                if (s.count(j))
                {
                    continue;
                }
                pq.push(make_pair(info.first + 1, j));
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] / 2 << "\n";
    }
}
