#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    a.push_back(t + m);
    int now = 0, ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += max(0, a[i] - now - m);
        now = a[i] + m;
    }
    cout << ans << "\n";
}