#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, nmax;
    cin >> n;
    nmax = n;
    int i = 0;
    while (n != 1)
    {
        if (n % 2)
        {
            n = 3 * n + 1;
        }
        else
        {
            n /= 2;
        }
        nmax = max(nmax, n);
        i++;
    }
    cout << i << "\n"
         << nmax << "\n";
}