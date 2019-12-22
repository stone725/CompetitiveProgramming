#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    vector<long long> b = a, c;
    sort(rbegin(a), rend(a));
    long long score = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            c.push_back(score ^ x);
            if (c.back() < 0)
            {
                cout << "-1\n";
                return 0;
            }
            if (x < c.back())
            {
                c[c.size() - 1] &= x;
            }
            score ^= c.back();
            continue;
        }
        score ^= a[i];
    }
    if (score != x)
    {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            b[i] = c.back();
            c.pop_back();
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << b[i] << " ";
    }
    cout << b[n - 1] << "\n";
}