#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int num1 = x / 100, num2 = x % 100;
    if (num2 <= 5 * num1)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}