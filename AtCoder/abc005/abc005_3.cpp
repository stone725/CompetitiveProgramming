#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &&i : b)
    {
        cin >> i;
    }
    if (n < m)
    {
        cout << "no\n";
        return 0;
    }
    auto p = begin(a);
    for (int i = 0; i < m; i++)
    {
        p = lower_bound(p, end(a), b[i] - t);
        if (p == end(a) || b[i] < *p)
        {
            cout << "no\n";
            return 0;
        }
        p++;
    }
    cout << "yes\n";
}