#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << 0.5 << "\n";
    }
    else
    {
        cout << (1. * (n / 2 + 1)) / n << "\n";
    }
}