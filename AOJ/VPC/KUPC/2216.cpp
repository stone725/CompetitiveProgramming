#include <iostream>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && a && b)
    {
        b -= a;
        cout << (b % 500) / 100 << " " << (b % 1000) / 500 << " " << b / 1000 << "\n";
    }
}