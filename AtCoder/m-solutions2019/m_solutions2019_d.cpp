#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edge(n), redge(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[min(a, b)].push_back(max(a, b));
        edge[max(a, b)].push_back(min(a, b));
    }
    for (auto &&i : edge)
    {
        sort(begin(i), end(i));
    }
    vector<int> c(n);
    for (auto &&i : c)
    {
        cin >> i;
    }
    sort(rbegin(c), rend(c));
    vector<int> cost(n);
    int p = 0;
    long long ans = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cost[now] = c[p];
        p++;
        for (auto &&i : edge[now])
        {
            if (cost[i])
                continue;
            q.push(i);
        }
    }
    vector<int> cost2 = cost;
    q.push(0);
    while (!q.empty())
    {
        int now = q.front();
        cost2[now] = 0;
        q.pop();
        p++;
        for (auto &&i : edge[now])
        {
            if (!cost2[i])
                continue;
            ans += cost2[i];
            q.push(i);
        }
    }
    q.push(0);

    cout << ans << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        cout << cost[i] << " ";
    }
    cout << cost[n - 1] << "\n";
}