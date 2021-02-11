#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0, a_max = 0;
    vector<long long> a(n), b(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        a_max = max(a_max, a[i]);
        ans = max(ans, a_max * b[i]);
        cout << ans << "\n";
    }
}