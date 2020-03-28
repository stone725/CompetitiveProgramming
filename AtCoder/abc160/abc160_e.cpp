#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (auto &&i : p)
    {
        cin >> i;
    }
    for (auto &&i : q)
    {
        cin >> i;
    }
    for (auto &&i : r)
    {
        cin >> i;
    }
    sort(rbegin(p), rend(p));
    sort(rbegin(q), rend(q));
    sort(rbegin(r), rend(r));
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < min(a, x); i++)
    {
        pq.push(p[i]);
    }
    for (int i = 0; i < min(b, y); i++)
    {
        pq.push(q[i]);
    }
    int now = 0;
    while (pq.size() < x + y || (now < c && pq.top() < r[now]))
    {
        if (pq.size() < x + y)
        {
            pq.push(r[now]);
        }
        else
        {
            pq.pop();
            pq.push(r[now]);
        }
        now++;
    }
    long long ans = 0;
    while (pq.size())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}
