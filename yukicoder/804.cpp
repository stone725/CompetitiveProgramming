#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i >= 0; i--)
    {
        if (i * c <= b && i * (c + 1) <= d)
        {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}