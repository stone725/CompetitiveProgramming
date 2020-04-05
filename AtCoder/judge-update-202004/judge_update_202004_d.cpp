#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), s(q), b(n + 1);
    b[0] = a[0];
    int num = -1;
    for (auto &&i : a)
    {
        cin >> i;
    }
    partial_sum(begin(a), end(a), begin(b) + 1, gcd<int, int>);
    for (auto &&i : s)
    {
        cin >> i;
    }
    for (int i = 0; i < q; i++)
    {
        int ans = gcd(s[i], b[n]);
        if (ans != 1)
        {
            cout << ans << "\n";
            continue;
        }
        b[0] = s[i];
        int ng = 0, ok = n;
        while (abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;
            if (gcd(s[i], b[mid]) == 1)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        if (ok == 0)
            ok++;
        cout << ok << "\n";
    }
}