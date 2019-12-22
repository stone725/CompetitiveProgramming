#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> cake(h);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                cake[i].push_back(j + 1);
            }
        }
    }
    int cnt = 1;
    vector<vector<int>> ans(h, vector<int>(w, 0));
    vector<bool> emp(h, true);
    for (int i = 0; i < h; i++)
    {
        int p = 0;
        for (auto &&j : cake[i])
        {
            for (int k = p; k < j; k++)
            {
                ans[i][k] = cnt;
            }
            cnt++;
            p = j;
            emp[i] = false;
        }
        if (cake.size() && p <= w - 1)
        {
            for (int k = p; k < w; k++)
            {
                ans[i][k] = ans[i][k - 1];
            }
        }
    }
    for (int i = 1; i < h; i++)
    {
        if (emp[i])
        {
            ans[i] = ans[i - 1];
        }
    }
    for (int i = h - 2; i >= 0; i--)
    {
        if (emp[i])
        {
            ans[i] = ans[i + 1];
        }
    }
    for (auto &&i : ans)
    {
        cout << i[0];
        for (int j = 1; j < w; j++)
        {
            cout << " " << i[j];
        }
        cout << "\n";
    }
}