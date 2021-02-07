#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << a / b << ".";
    for (int i = 0; i < 50; i++)
    {
        a %= b;
        a *= 10;
        cout << a / b;
    }
    cout << "\n";
}