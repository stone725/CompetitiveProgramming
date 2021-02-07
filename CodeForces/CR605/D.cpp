#include <iostream>
#include <vector>
#include <algorithm>

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
    if (is_sorted(begin(a), end(a)))
    {
        cout << n << "\n";
        return 0;
    }
    vector<int> b(n), c(n);
    b[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            b[i] = b[i - 1] + 1;
        }
        else
        {
            b[i] = 1;
        }
        ans = max(ans, b[i]);
    }
    c[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            c[i] = c[i + 1] + 1;
        }
        else
        {
            c[i] = 1;
        }
        ans = max(ans, c[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i + 1])
        {
            ans = max(ans, b[i - 1] + c[i + 1]);
        }
    }
    cout << ans << "\n";
}