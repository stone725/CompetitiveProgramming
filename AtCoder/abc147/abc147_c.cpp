#include <iostream>
#include <bitset>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bitset<15> bits;
vector<vector<pair<int, int>>> a;

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        for (auto &&j : a[i])
        {
            cin >> j.first >> j.second;
            j.first--;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        bitset<15> info(i);
        bool check = true;
        for (int j = 0; j < n; j++)
        {
            if (!info[j])
                continue;
            for (auto &&k : a[j])
            {
                if (info[k.first] != k.second)
                {
                    check = false;
                    break;
                }
            }
            if (!check)
            {
                break;
            }
        }
        if (check)
        {
            ans = max<int>(ans, info.count());
        }
    }
    cout << ans << "\n";
}