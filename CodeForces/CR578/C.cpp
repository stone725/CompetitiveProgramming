#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    long long n, m, q;
    cin >> n >> m >> q;
    long long _gcd = gcd(n, m), p[2] = {n / _gcd, m / _gcd};
    while (q--)
    {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if ((sy - 1) / p[sx - 1] != (ey - 1) / p[ex - 1])
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}