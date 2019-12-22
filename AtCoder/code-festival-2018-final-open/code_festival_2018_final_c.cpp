#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> plan(n);
    for (auto &&i : plan)
    {
        cin >> i.first >> i.second;
    }
    sort(begin(plan), end(plan));
    int m;
    cin >> m;
    while (m--)
    {
        int t;
        cin >> t;
        auto p = lower_bound(begin(plan), end(plan), make_pair(t, 0));
        if (p == end(plan))
        {
            cout << (p - 1)->second + (t - (p - 1)->first) << "\n";
            continue;
        }
        if (p == begin(plan) || p->first == t)
        {
            cout << p->second << "\n";
            continue;
        }
        cout << min(p->second, (p - 1)->second + t - (p - 1)->first) << "\n";
    }
}