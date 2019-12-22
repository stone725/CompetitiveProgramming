#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (y < 0 || y % 2 == 1 || abs(x) > y / 2 || (y / 2) % 2 != abs(x) % 2)
    {
        cout << "-1\n";
        return 0;
    }
    cout << y / 2 << "\n";
}