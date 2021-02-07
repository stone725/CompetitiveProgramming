#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &&i : c)
    {
        cin >> i;
    }
    sort(begin(c), end(c));
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (c[i] % c[j] == 0)
                cnt++;
        }
        ans += 1. * (cnt / 2 + cnt % 2) / cnt;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}