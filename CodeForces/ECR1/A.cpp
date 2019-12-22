#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long num;
        cin >> num;
        long long ans = num * (num + 1) / 2;
        for (long long i = 1; i <= num; i *= 2)
        {
            ans -= 2 * i;
        }
        cout << ans << "\n";
    }
}