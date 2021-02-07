#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = n - 1;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i)
            continue;
        ans = min(ans, i + n / i - 2);
    }
    cout << ans << "\n";
}