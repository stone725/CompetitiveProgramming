#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> v(n, vector<int>(d));
    for (auto &&i : v)
    {
        for (auto &&j : i)
        {
            cin >> j;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = 0;
            for (int k = 0; k < d; k++)
            {
                num += (v[i][k] - v[j][k]) * (v[i][k] - v[j][k]);
            }
            int checknum;
            for (checknum = 1; checknum * checknum < num; checknum++)
                ;
            ans += checknum * checknum == num;
        }
    }
    cout << ans << "\n";
}