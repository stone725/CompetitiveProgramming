#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    static const int INF = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long left = 0, right = 0;
        for (int j = 0; j < i; j++)
        {
            left += a[j] < a[i];
        }
        for (int j = i + 1; j < n; j++)
        {
            right += a[j] < a[i];
        }
        unsigned long long add = (left + right);
        add *= (k - 1);
        add %= INF;
        add *= k;
        add %= INF;
        add *= modinv(2, INF);
        add %= INF;
        add += right * k;
        ans += add;
        ans %= INF;
    }
    cout << ans << "\n";
}