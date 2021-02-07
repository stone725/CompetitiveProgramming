#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<long long, long long>> m(n);
    for (auto &&i : m)
    {
        cin >> i.first >> i.second;
        i.second = (i.second + a - 1) / a;
    }
    sort(begin(m), end(m));
    long long ans = 0;
    vector<pair<long long, long long>> s;
    long long minus = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        while (p < s.size() && s[p].first < m[i].first)
        {
            minus -= s[p].second;
            p++;
        }
        long long check = max(0ll, m[i].second - minus);
        ans += check;
        minus += check;
        s.push_back(make_pair(m[i].first + d * 2, check));
    }
    cout << ans << "\n";
}