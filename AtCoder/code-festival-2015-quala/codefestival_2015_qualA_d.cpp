#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> x;

bool check(long long mid)
{
    long long p = 0;
    for (auto &&i : x)
    {
        long long l = max(0ll, i - p - 1);
        if (mid < l)
        {
            return false;
        }
        p = i + max(mid - 2 * l, (mid - l) / 2);
    }
    return n <= p;
}

int main()
{
    cin >> n >> m;
    x.resize(m);
    for (auto &&i : x)
    {
        cin >> i;
    }
    long long s = -1, g = n * 2;
    while (1 < (g - s))
    {
        long long mid = (g + s) / 2;
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