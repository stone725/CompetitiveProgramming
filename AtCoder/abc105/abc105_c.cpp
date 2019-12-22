#include <iostream>
#include <string>

using namespace std;

long long mod(long long n, int m)
{
    return ((n % m) + m) % m;
}

int main()
{
    long long n;
    cin >> n;
    string ans = "";
    long long checkint = 1;
    do
    {
        switch (mod(n / abs(checkint), 2))
        {
        case 0:
            ans = "0" + ans;
            break;
        case 1:
            ans = "1" + ans;
            n -= checkint;
            break;
        }
        checkint *= -2;
    } while (n);
    cout << ans << "\n";
}