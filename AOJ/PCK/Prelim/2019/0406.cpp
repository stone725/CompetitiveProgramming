#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    while (ans << 1 <= n)
    {
        ans <<= 1;
    }
    cout << ans << "\n";
}