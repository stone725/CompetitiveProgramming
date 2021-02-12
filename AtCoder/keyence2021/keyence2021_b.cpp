#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0, now = 0;
    while (0 < k)
    {
        ans += max(0, k - cnt[now]) * now;
        k = min(k, cnt[now]);
        now++;
    }
    cout << ans << "\n";
}