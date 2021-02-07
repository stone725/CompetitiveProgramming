#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < q; i++)
    {
        int l, r, t;
        cin >> l >> r >> t;
        for (int i = l - 1; i < r; i++)
        {
            a[i] = t;
        }
    }
    for (auto &&i : a)
    {
        cout << i << "\n";
    }
}