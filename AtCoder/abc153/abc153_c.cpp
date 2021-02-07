#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &&i : h)
    {
        cin >> i;
    }
    sort(rbegin(h), rend(h));
    long long ans = 0;
    for (int i = k; i < n; i++)
    {
        ans += h[i];
    }
    cout << ans << "\n";
}