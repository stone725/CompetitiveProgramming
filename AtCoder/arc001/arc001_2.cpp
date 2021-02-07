#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = abs(b - a) / 10 + (abs(b - a) % 10 / 5) + abs(b - a) % 5;
    for (int i = abs(b - a) / 10; i <= abs(b - a) / 10 + 1; i++)
    {
        int d = abs(abs(b - a) - i * 10);
        for (int j = d / 5; j <= d / 5 + 1; j++)
        {
            int r = abs(d - j * 5);
            ans = min(i + j + r, ans);
        }
    }
    cout << ans << "\n";
}