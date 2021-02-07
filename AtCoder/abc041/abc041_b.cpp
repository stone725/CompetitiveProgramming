#include <iostream>

using namespace std;

int main()
{
    const int INF = 1e9 + 7;
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = a * b % INF;
    ans *= c;
    ans %= INF;
    cout << ans << "\n";
}