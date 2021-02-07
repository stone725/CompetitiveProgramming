#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (auto &&i : a)
    {
        for (auto &&j : i)
        {
            cin >> j;
        }
    }
    int ans = 1e9 + 7;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int cnt = 0;
            for (int k = 0; k < h; k++)
            {
                for (int l = 0; l < w; l++)
                {
                    cnt += min(abs(k - i), abs(l - j)) * a[k][l];
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}