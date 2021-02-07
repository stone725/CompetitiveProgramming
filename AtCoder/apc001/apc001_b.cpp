#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (auto &&i : b)
    {
        cin >> i;
    }
    long long canmove = accumulate(begin(b), end(b), 0ll) - accumulate(begin(a), end(a), 0ll);
    long long aAdd = 0, bAdd = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] < a[i])
        {
            bAdd += a[i] - b[i];
            if (canmove < bAdd)
            {
                cout << "No\n";
                return 0;
            }
        }
        else if (a[i] < b[i])
        {
            aAdd += (b[i] - a[i]) / 2 + (b[i] - a[i]) % 2;
            if (canmove < aAdd)
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}