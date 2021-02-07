#include <iostream>
#include <vector>
#include <algorithm>
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
    for (int i = 1; i <= n; i++)
    {
        long long ans = b[i];
        for (int j = 1; j + i <= n; j++)
        {
            ans = max(ans, b[j + i] - b[j]);
        }
        cout << ans << "\n";
    }
}