#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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
    sort(begin(a), end(a));
    long long num = a[0];
    for (auto &&i : a)
    {
        i -= num;
    }
    adjacent_difference(begin(a), end(a), begin(b));
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += b[i] * i * (n - i);
    }
    cout << ans << "\n";
}