#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k, s;
    cin >> n >> k >> s;
    if (k * (n - 1) < s)
    {
        cout << "NO\n";
        return 0;
    }
    long long d = s / k;
    long long p = 1;
    if (d == 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++)
    {
        long long diff = d;
        if (i < s % k)
        {
            diff++;
        }
        if (p + diff <= n)
        {
            p += diff;
        }
        else
        {
            p -= diff;
        }
        if (i != 0)
        {
            cout << " ";
        }
        cout << p;
    }
    cout << "\n";
}