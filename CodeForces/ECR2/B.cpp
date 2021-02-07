#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    sort(begin(a), end(a));
    for (int i = 0; i < m - 1; i++)
    {
        cout << static_cast<int>(upper_bound(begin(a), end(a), b[i]) - begin(a)) << " ";
    }
    cout << static_cast<int>(upper_bound(begin(a), end(a), b[m - 1]) - begin(a)) << "\n";
}