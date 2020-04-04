#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (auto &&i : a)
    {
        cin >> i;
        sum += i;
    }
    sort(rbegin(a), rend(a));
    for (int i = 0; i < m; i++)
    {
        if (4 * m * a[i] < sum)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
