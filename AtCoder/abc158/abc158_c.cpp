#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = b * 10; i < (b + 1) * 10; i++)
    {
        if (a == static_cast<int>(i * 0.08))
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}