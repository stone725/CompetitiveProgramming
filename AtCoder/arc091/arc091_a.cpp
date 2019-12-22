#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    if (m < n)
        swap(n, m);
    if (n == 1)
    {
        if (m == 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << m - 2 << "\n";
        }
        return 0;
    }
    cout << (n - 2) * (m - 2) << "\n";
}