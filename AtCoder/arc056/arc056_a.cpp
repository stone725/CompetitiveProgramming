#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, k, l;
    cin >> a >> b >> k >> l;
    long long ans = b * (k / l);
    if (k % l)
    {
        ans += min((k % l) * a, b);
    }
    cout << ans << "\n";
}