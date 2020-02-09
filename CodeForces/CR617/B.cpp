#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int s;
        cin >> s;
        long long ans = 0;
        while (s / 10)
        {
            ans += s / 10 * 10;
            s = s % 10 + s / 10;
        }
        ans += s;
        cout << ans << "\n";
    }
}