#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <iomanip>

using namespace std;

bool check(complex<double> l, complex<double> r)
{
    if (l.real() == r.real())
    {
        return l.imag() < r.imag();
    }
    return l.real() < r.real();
}

int main()
{
    int n;
    cin >> n;
    vector<complex<double>> a(n);
    for (auto &&i : a)
    {
        int x, y;
        cin >> x >> y;
        i.real(x);
        i.imag(y);
    }
    sort(begin(a), end(a), check);
    double ans = 0;
    do
    {
        for (int i = 1; i < n; i++)
        {
            ans += abs(a[i - 1] - a[i]);
        }
    } while (next_permutation(begin(a), end(a), check));
    for (int i = 1; i <= n; i++)
    {
        ans /= i;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}