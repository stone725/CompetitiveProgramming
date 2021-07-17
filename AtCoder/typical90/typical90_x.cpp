#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long k;

    cin >> n >> k;
    vector<int> a(n), b(n);

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
        k -= abs(a[i] - b[i]);
    }

    if (k < 0 || k % 2)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
}