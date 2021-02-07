#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << (a + b) / 2 << "\n";
    }
}