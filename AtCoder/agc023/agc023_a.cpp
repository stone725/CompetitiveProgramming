#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n + 1);
    for (auto &&i : a)
    {
        cin >> i;
    }
    partial_sum(begin(a), end(a), begin(b) + 1);
    long long ans = 0;
    map<long long, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
            ans++;
        ans += cnt[b[i]];
        cnt[b[i]]++;
    }
    cout << ans << "\n";
}
