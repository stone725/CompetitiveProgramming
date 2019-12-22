#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a <= 0 && 0 <= b)
    {
        cout << "Zero\n";
    }
    else if (b < 0)
    {
        if ((b - a) % 2)
        {
            cout << "Positive\n";
        }
        else
        {
            cout << "Negative\n";
        }
    }
    else
    {
        cout << "Positive\n";
    }
}