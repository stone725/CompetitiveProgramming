#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<complex<double>> c(n);
    for (auto &&i : c)
    {
        int x, y;
        cin >> x >> y;
        i = complex<double>(x, y);
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, abs(c[i] - c[j]));
        }
    }
    cout << ans << "\n";
}