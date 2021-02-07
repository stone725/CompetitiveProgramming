#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int l, r;
    int mod = 2019;
    cin >> l >> r;
    int ans = 2019;
    if (l / mod < r / mod)
        ans = 0;
    l %= mod;
    r %= mod;
    for (int i = l; i <= r && i <= 2019; i++)
    {
        if (i % 2019 == 0)
        {
            ans = 0;
            break;
        }
        for (int j = i + 1; j <= r && j <= 2019; j++)
        {
            if (j % 2019 == 0 || (i % 3 == 0 && j % 673 == 0) || (j % 3 == 0 && i % 673 == 0))
            {
                ans = 0;
                break;
            }
            ans = min(ans, ((i % mod) * (j % mod)) % mod);
        }
        if (ans == 0)
        {
            break;
        }
    }
    cout << ans << "\n";
}
