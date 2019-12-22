#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    vector<int> a;
    while (cin >> n >> m && n && m)
    {
        a.resize(n);
        for (auto &&i : a)
        {
            cin >> i;
        }
        sort(begin(a), end(a));
        int ans = -1;
        for (int i = 0; i + 1 < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] + a[j] > m)
                    break;
                ans = max(ans, a[i] + a[j]);
            }
        }
        if (~ans)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << "NONE\n";
        }
    }
}