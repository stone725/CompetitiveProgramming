#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
        i /= 2;
    }
    sort(rbegin(a), rend(a));
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0;
    for (int i = a[0]; i <= m; i += a[0] * 2)
    {
        ans++;
        for (auto &&j : a)
        {
            if (i % j || (i / j) % 2 == 0)
            {
                ans--;
                break;
            }
        }
    }
    cout << ans << "\n";
}