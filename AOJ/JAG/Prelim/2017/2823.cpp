#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    vector<priority_queue<int>> problems;
    while (cin >> n >> m && n && m)
    {
        problems.clear();
        problems.resize(m);
        for (int i = 0; i < n; i++)
        {
            int d, v;
            cin >> d >> v;
            problems[d - 1].push(v);
        }
        int ans = 0;
        for (auto &&i : problems)
        {
            ans += i.top();
        }
        cout << ans << "\n";
    }
}