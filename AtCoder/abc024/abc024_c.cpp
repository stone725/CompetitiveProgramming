#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> days(d);
    for (auto &&i : days)
    {
        cin >> i.first >> i.second;
    }
    for (int i = 0; i < k; i++)
    {
        int s, t;
        cin >> s >> t;
        bool up = s < t;
        int p = s;
        for (int j = 0; j < d; j++)
        {
            if (days[j].first <= p && p <= days[j].second)
            {
                if (up)
                {
                    p = days[j].second;
                    if (t <= p)
                    {
                        cout << j + 1 << "\n";
                        break;
                    }
                }
                else
                {
                    p = days[j].first;
                    if (p <= t)
                    {
                        cout << j + 1 << "\n";
                        break;
                    }
                }
            }
        }
    }
}