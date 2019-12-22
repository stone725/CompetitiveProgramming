#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            cnt += a;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}