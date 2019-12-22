#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    vector<long long> b(n + 1);
    partial_sum(begin(a), end(a), begin(b) + 1);
    unsigned long long ans = 0;
    for (int i = 0; i + k <= n; i++)
    {
        ans += b[i + k] - b[i];
    }
    cout << ans << "\n";
}