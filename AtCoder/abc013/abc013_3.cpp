#include <iostream>
#include <algorithm>

using namespace std;

static const long long INF = 1ll << 60;
long long n, h, a, b, c, d, e;

long long calc(int day)
{
    long long score = e * (n - day) - b * day - h;
    if (0 <= score)
        return day * a + c * (((n - day) * e - h - b * day) / (d + e) + 1);
    return day * a;
}

int main()
{
    cin >> n >> h;
    cin >> a >> b >> c >> d >> e;
    long long ans = INF;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, calc(i));
    }
    cout << ans << "\n";
}