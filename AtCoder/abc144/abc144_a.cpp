#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (9 < a || 9 < b)
    {
        cout << "-1\n";
    }
    else
    {
        cout << a * b << "\n";
    }
}