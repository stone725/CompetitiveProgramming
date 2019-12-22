#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, long long>> bal;

bool check(long long mid)
{
    vector<long long> cost;
    for (auto &&i : bal)
    {
        if (i.first > mid)
            return false;
        cost.push_back((mid - i.first) / i.second + 1);
    }
    sort(begin(cost), end(cost));
    for (int i = 1; i <= n; i++)
    {
        if (i > cost[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    bal.resize(n);
    for (auto &&i : bal)
    {
        cin >> i.first >> i.second;
    }
    long long s = 0, g = 1e15;
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