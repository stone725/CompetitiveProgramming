#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    double ans = 1. / n * (k - 1) / n * (n - k) / n * 3 * 2;
    ans += 1. / n / n * (n - k) / n * 3;
    ans += 1. / n / n * (k - 1) / n * 3;
    ans += 1. / n / n / n;
    cout << fixed << setprecision(10) << ans << "\n";
}