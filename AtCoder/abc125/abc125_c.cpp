#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int n;
vector<int> a(n);

int dp1[100000], dp2[100000];

int l(int now)
{
    if (now == 0)
    {
        return 0;
    }
    if (~dp1[now])
        return dp1[now];
    return dp1[now] = gcd(l(now - 1), a[now - 1]);
}

int r(int now)
{
    if (now == n)
    {
        return 0;
    }
    if (~dp2[now])
        return dp2[now];
    return dp2[now] = gcd(r(now + 1), a[now]);
}

int main()
{
    cin >> n;
    a.resize(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int ans = 0;
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, gcd(l(i), r(i + 1)));
    }
    cout << ans << "\n";
}