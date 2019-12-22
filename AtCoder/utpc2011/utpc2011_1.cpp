#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            int solve;
            cin >> solve;
            cnt += solve;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}