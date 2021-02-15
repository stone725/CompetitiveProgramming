#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long ans = max(0ll, r - l * 2 + 1) * max(0ll, r - l * 2 + 1) - max(0ll, r - l * 2 + 1) * max(0ll, r - l * 2) / 2;
        cout << ans << "\n";
    }
}