#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = a * (n / (a + b)) + min(a, n % (a + b));
    cout << ans << "\n";
}