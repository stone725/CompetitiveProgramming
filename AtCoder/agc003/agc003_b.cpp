#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] / 2;
        a[i] %= 2;
        if (i + 1 < n)
        {
            ans += a[i] && a[i + 1];
            a[i + 1] -= a[i] && a[i + 1];
        }
    }
    cout << ans << "\n";
}