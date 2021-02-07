#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long maxnum = 3234566667;
vector<long long> ans;

void dfs(long long num, int n, bool check)
{
    if (n == 10)
    {
        if (check)
        {
            ans.push_back(num / 10);
        }
        return;
    }
    if (!check)
    {
        for (char i = 0; i <= 9; i++)
        {
            num += i;
            if (maxnum / pow<long long>(10, 10 - n - 1) < num)
            {
                return;
            }
            dfs(num * 10, n + 1, i);
            num -= i;
        }
        return;
    }
    for (int i = max<long long>(0, (num % 100) / 10 - 1); i <= min<long long>(9, (num % 100) / 10 + 1); i++)
    {
        num += i;
        if (maxnum / pow<long long>(10, 10 - n - 1) < num)
        {
            return;
        }
        dfs(num * 10, n + 1, true);
        num -= i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    dfs(0, 0, false);
    int k;
    cin >> k;
    sort(begin(ans), end(ans));
    cout << ans[k - 1] << "\n";
}
