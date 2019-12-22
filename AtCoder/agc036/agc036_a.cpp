#include <iostream>

using namespace std;

int main()
{
    long long s;
    cin >> s;
    if (s == 1e18)
    {
        cout << "0 0 0 1000000000 1000000000 0";
        return 0;
    }
    cout << 0 << " " << 0 << " " << static_cast<long long>(1e9) << " " << 1 << " " << static_cast<long long>(1e9 - s % static_cast<long long>(1e9)) << " " << s / static_cast<long long>(1e9) + 1 << "\n";
}