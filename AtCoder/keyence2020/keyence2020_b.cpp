#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> robot(n);
    vector<pair<long long, int>> arms, smra;
    for (auto &&i : robot)
    {
        cin >> i.first >> i.second;
        arms.push_back(make_pair(i.first + i.second, i.first - i.second));
        smra.push_back(make_pair(arms.back().second, arms.back().first));
    }
    sort(begin(arms), end(arms));
    sort(rbegin(smra), rend(smra));
    int x = -1e9;
    int cnt = 0;
    for (auto &&i : arms)
    {
        if (x <= i.second)
        {
            cnt++;
            x = i.first;
        }
    }
    int ans = cnt;
    x = 2e9;
    cnt = 0;
    for (auto &&i : smra)
    {
        if (i.second <= x)
        {
            cnt++;
            x = i.first;
        }
    }
    ans = max(ans, cnt);
    cout << ans << "\n";
}