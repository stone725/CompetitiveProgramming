#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n + 1);
    for (auto &&i : a)
    {
        cin >> i;
    }
    map<long long, long long> cnt;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i - 1] + k - 1;
        if (i - k >= 0)
            cnt[b[i - k] % k]--;
        ans += cnt[b[i] % k];
        cnt[b[i] % k]++;
    }
    cout << ans << "\n";
}
