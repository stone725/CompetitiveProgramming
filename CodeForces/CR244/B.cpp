#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, t, c;
    cin >> n >> t >> c;
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (t < a)
        {
            ans += max(0, cnt - (c - 1));
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    ans += max(0, cnt - (c - 1));
    cout << ans << "\n";
}