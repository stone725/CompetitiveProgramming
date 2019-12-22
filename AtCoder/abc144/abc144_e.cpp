#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;
vector<long long> a(n), b(n);

bool check(long long x)
{
    long long num = 0;
    for (int i = 0; i < n; i++)
    {
        long long c = x / b[i];
        num += max<long long>(0, a[i] - c);
    }
    return num <= k;
}

int main()
{
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
    sort(rbegin(b), rend(b));
    long long s = -1, g = 1e12;
    while (g - s > 1)
    {
        long long mid = (s + g) / 2;
        if (check(mid))
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