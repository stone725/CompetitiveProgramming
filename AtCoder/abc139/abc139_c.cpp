#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &&i : h)
    {
        cin >> i;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (h[i] <= h[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        ans = max(cnt, ans);
    }
    cout << ans << "\n";
}