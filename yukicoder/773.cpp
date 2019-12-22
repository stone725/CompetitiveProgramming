#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 23; i <= 25; i++)
    {
        ans += !(a <= i && i <= b);
    }
    cout << ans << "\n";
}