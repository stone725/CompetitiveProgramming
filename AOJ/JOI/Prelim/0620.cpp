#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (int k = 1; k <= m; k++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] % k > a[j + 1] % k)
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (auto &&i : a)
    {
        cout << i << "\n";
    }
}