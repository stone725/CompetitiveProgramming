#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int ans = 1e9 + 7;
    for (int i = 0; i + k <= n; i++)
    {
        if (a[i + k - 1] <= 0)
        {
            ans = min(ans, abs(a[i]));
        }
        else if (0 <= a[i])
        {
            ans = min(ans, a[i + k - 1]);
        }
        else
        {
            ans = min(ans, min(-a[i], a[i + k - 1]) * 2 + max(-a[i], a[i + k - 1]));
        }
    }
    cout << ans << "\n";
}