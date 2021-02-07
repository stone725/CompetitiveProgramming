#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a[3];
        for (auto &&j : a)
        {
            cin >> j;
        }
        sort(begin(a), end(a));
        if (a[2] - a[0] <= 2)
        {
            cout << 0 << "\n";
            continue;
        }
        a[0]++;
        a[2]--;
        if (a[1] < a[0])
        {
            a[1]++;
        }
        else if (a[2] < a[1])
        {
            a[1]--;
        }
        int ans = 0;
        ans += a[2] - a[0];
        ans += abs(a[1] - a[0]);
        ans += abs(a[2] - a[1]);
        cout << ans << "\n";
    }
}