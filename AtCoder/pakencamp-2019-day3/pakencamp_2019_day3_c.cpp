#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &&i : a)
    {
        for (auto &&j : i)
        {
            cin >> j;
        }
    }
    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                b[i].push_back(max(a[i][j], a[i][k]));
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < b[0].size(); i++)
    {
        long long sum = 0;
        for (auto j : b)
        {
            sum += j[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}
