#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B, m;
    cin >> A >> B >> m;
    vector<int> a(A), b(B);
    int ans = 2e5;
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        ans = min(ans, a[x - 1] + b[y - 1] - c);
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    cout << min(ans, a[0] + b[0]) << "\n";
}