#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
vector<long long> a;
map<long long, unsigned long long> dp;

unsigned long long getScore(long long mid)
{
    if (dp.count(mid))
        return dp[mid];
    unsigned long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res += abs(a[i] - (mid + i + 1));
    }
    return res;
}

int main()
{
    cin >> n;
    a.resize(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    long long s = -1000000000, g = 1000000000;
    while (s < g)
    {
        long long mid1 = (s * 2 + g) / 3;
        long long mid2 = (s + g * 2) / 3;
        unsigned long long score1 = getScore(mid1);
        unsigned long long score2 = getScore(mid2);
        if (score1 < score2)
        {
            g = mid2 - 1;
        }
        else if (score1 > score2)
        {
            s = mid1 + 1;
        }
        else
        {
            s = mid1 + 1;
            g = mid2 - 1 + (mid1 == mid2);
        }
    }
    cout << min(getScore(s), getScore(g)) << "\n";
}