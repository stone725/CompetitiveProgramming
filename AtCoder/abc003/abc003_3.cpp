#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    sort(rbegin(a), rend(a));
    double ans = 0;
    sort(begin(a), begin(a) + k);
    for (int i = 0; i < k; i++)
    {
        ans = (ans + a[i]) / 2;
    }
    cout << setprecision(10) << ans << "\n";
}