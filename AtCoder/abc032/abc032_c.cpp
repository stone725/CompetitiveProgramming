#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> s(n);
    for (auto &&i : s)
    {
        cin >> i;
        if (i == 0)
        {
            cout << n << "\n";
            return 0;
        }
    }
    if (k == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    int st = 0, go = 1, ans = 0;
    unsigned long long now = 1;
    while (go <= n && st <= go)
    {
        now *= s[go - 1];
        while (now > k && st < go)
        {
            now /= s[st];
            st++;
        }
        ans = max(ans, go - st);
        go++;
    }

    cout << ans << "\n";
}