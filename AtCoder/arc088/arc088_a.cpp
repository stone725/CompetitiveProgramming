#include <iostream>

using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    long long ans = 0;
    while (x <= y)
    {
        ans++;
        x *= 2;
    }
    cout << ans << "\n";
}