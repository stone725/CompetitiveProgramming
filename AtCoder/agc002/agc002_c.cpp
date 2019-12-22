#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (int i = 1; i < n; i++)
    {
        if (l <= a[i] + a[i - 1])
        {
            cout << "Possible\n";
            for (int j = 0; j < i - 1; j++)
            {
                cout << j + 1 << "\n";
            }
            for (int j = n - 1; j >= i; j--)
            {
                cout << j << "\n";
            }
            return 0;
        }
    }
    cout << "Impossible\n";
}