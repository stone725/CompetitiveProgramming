#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m, f, b;
    cin >> m >> f >> b;
    if (m + f < b)
    {
        cout << "NA\n";
    }
    else
    {
        cout << max(0, b - m) << "\n";
    }
}