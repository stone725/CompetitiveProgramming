#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> a(4 * n);
        for (auto &&i : a)
        {
            cin >> i;
        }
        sort(begin(a), end(a));
        bool check = true;
        int score = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[2 * i] != a[2 * i + 1] || a[4 * n - 1 - 2 * i] != a[4 * n - 2 - 2 * i])
            {
                check = false;
                break;
            }
            if (i)
            {
                if (score != a[2 * i] * a[4 * n - 1 - 2 * i])
                {
                    check = false;
                    break;
                }
            }
            else
            {
                score = a[2 * i] * a[4 * n - 1 - 2 * i];
            }
        }
        if (check)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}