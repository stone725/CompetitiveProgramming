#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    int ans = 0;
    for (int i = min(x / 500, a); i >= 0; i--)
    {
        for (int j = min((x - i * 500) / 100, b); j >= 0; j--)
        {
            if ((x - i * 500 - j * 100) / 50 <= c)
                ans++;
            else
                break;
        }
    }
    cout << ans++;
}