#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n && m)
    {
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> p[j][i];
            }
        }
        int ans = 0;
        for (auto &&i : p)
        {
            ans = max(ans, accumulate(begin(i), end(i), 0));
        }
        cout << ans << "\n";
    }
}