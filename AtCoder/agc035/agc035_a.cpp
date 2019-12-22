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
    sort(begin(a), end(a));
    if (a.back() == 0)
    {
        cout << "Yes\n";
        return 0;
    }
    else if (n % 3)
    {
        cout << "No\n";
        return 0;
    }
    bool check = true;
    int x1, x2, x3;
    for (int i = 0; i < n / 3; i++)
    {
        if (i == 0)
        {
            if (a[0] != 0 || a[n / 3] != a[n / 3 * 2])
            {
                check = false;
                break;
            }
            else
            {
                x2 = a[n / 3];
            }
        }
        else if (0 != a[i] || x2 < a[i + n / 3 * 2])
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "Yes\n";
        return 0;
    }
    check = true;
    for (int i = 0; i < n / 3; i++)
    {
        if (i == 0)
        {
            if ((a[0] ^ a[n / 3]) != a[2 * n / 3])
            {
                check = false;
                break;
            }
            else
            {
                x1 = a[0];
                x2 = a[n / 3];
                x3 = a[n / 3 * 2];
            }
        }
        else if (x1 != a[i] || x2 != a[i + n / 3] || x3 != a[i + n / 3 * 2])
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}