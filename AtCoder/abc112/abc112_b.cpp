#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int ans = 1001;
    for (int i = 0; i < n; i++)
    {
        int c, ti;
        cin >> c >> ti;
        if (ti <= t)
        {
            ans = min(ans, c);
        }
    }
    if (ans == 1001)
    {
        cout << "TLE\n";
        return 0;
    }
    cout << ans << "\n";
}