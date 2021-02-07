#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = a * 1728 + b * 144 + c * 12 + d;
    cout << ans << "\n";
}