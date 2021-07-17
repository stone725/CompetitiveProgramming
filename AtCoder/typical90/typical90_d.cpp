#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));

    vector<int> sum_row(h), sum_column(w);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];

            sum_row[i] += a[i][j];
            sum_column[j] += a[i][j];
        }
    }

    vector<vector<int>> ans(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans[i][j] = sum_row[i] + sum_column[j] - a[i][j];
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