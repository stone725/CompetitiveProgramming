#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> r(n), b(n);
    for (auto &&i : r)
    {
        cin >> i.first >> i.second;
    }
    for (auto &&i : b)
    {
        cin >> i.first >> i.second;
    }
    sort(begin(r), end(r));
    sort(begin(b), end(b));
    int ans = 0;
    for (auto &&i : b)
    {
        bool check = false;
        int p;
        for (int j = 0; j < n && r[j] < i; j++)
        {
            if (r[j].second < i.second)
            {
                if (!check)
                {
                    check = true;
                    p = j;
                }
                else if (r[p].second < r[j].second)
                {
                    p = j;
                }
            }
        }
        if (check)
        {
            ans++;
            r[p].second = 2 * n;
        }
    }
    cout << ans << "\n";
}