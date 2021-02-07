#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a)
    {
        cout << (b - a + 1) * (d - c + 1) << "\n";
        return 0;
    }
    cout << (b - a + 1) * (d - c + 1) - (min(d, b) - max(a, c) + 1) << "\n";
}