#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long k;
vector<long long> a, b;

long long cnt(long long mid)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += upper_bound(begin(b), end(b), mid / a[i]) - begin(b);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    long long s = 0, g = a.back() * b.back();
    while (g - s > 1)
    {
        long long mid = (s + g) / 2;
        if (k <= cnt(mid))
        {
            g = mid;
        }
        else
        {
            s = mid;
        }
    }
    cout << g << "\n";
}