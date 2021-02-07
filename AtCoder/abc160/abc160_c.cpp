#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    vector<int> a(n), b;
    for (auto &&i : a)
    {
        cin >> i;
        b.push_back(i);
        b.push_back(i + k);
        b.push_back(i + 2 * k);
    }
    sort(begin(b), end(b));
    int ans = k * 2;
    for (int i = 0; i < 2 * n; i++)
    {
        ans = min(b[i + n - 1] - b[i], ans);
    }
    cout << ans << "\n";
}
