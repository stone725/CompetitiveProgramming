#include <iostream>

using namespace std;

int main()
{
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for (int x = 0; x <= k; x++)
    {
        for (int y = 0; y <= k; y++)
        {
            if (s < x + y)
                break;
            ans += s - x - y <= k;
        }
    }
    cout << ans << "\n";
}