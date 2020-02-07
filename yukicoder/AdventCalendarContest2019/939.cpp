#include <iostream>

using namespace std;

int main()
{
    unsigned int a, b;
    cin >> a >> b;
    if (a != (a & b))
    {
        cout << 0 << "\n";
        return 0;
    }
    if (a == b)
    {
        cout << 1 << "\n";
        return 0;
    }
    unsigned int c = a ^ b;
    unsigned int ans = 1;
    while (c)
    {
        if (c % 2)
        {
            ans *= 2;
        }
        c /= 2;
    }
    cout << ans / 2 << "\n";
}