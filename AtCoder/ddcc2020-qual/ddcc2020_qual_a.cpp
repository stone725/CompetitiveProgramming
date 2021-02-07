#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int ans = 0;
    switch (x)
    {
    case 1:
        ans += 100000;
    case 2:
        ans += 100000;
    case 3:
        ans += 100000;
    }
    switch (y)
    {
    case 1:
        ans += 100000;
    case 2:
        ans += 100000;
    case 3:
        ans += 100000;
    }
    ans += 400000 * (x * y == 1);
    cout << ans << "\n";
}