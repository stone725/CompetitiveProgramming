#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = min(b - 1, n - a);
    if ((b - a) % 2 == 0)
    {
        ans = min(ans, (b - a) / 2);
    }
    else
    {
        ans = min(ans, min(n - b + 1, a) + (b - a) / 2);
    }
    cout << ans << "\n";
}