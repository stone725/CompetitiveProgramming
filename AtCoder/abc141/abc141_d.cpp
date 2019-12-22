#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    priority_queue<int> b(begin(a), end(a));
    for (int i = 0; i < m; i++)
    {
        b.push(b.top() / 2);
        b.pop();
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += b.top();
        b.pop();
    }
    cout << ans << "\n";
}