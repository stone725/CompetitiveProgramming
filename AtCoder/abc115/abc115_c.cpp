#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &&i : h)
    {
        cin >> i;
    }
    sort(begin(h), end(h));
    int ans = 1e9;
    for (int i = 0; i + k <= n; i++)
    {
        ans = min(ans, h[i + k - 1] - h[i]);
    }
    cout << ans << "\n";
}