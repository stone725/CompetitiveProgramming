#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(m);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    int t = 0, ans = 0;
    while (lower_bound(begin(a), end(a), t) != end(a))
    {
        auto p = lower_bound(begin(b), end(b), *lower_bound(begin(a), end(a), t) + x);
        if (p == end(b))
        {
            break;
        }
        t = *p + y;
        ans++;
    }
    cout << ans << "\n";
}