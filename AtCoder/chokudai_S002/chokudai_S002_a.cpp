#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        unsigned long long a, b;
        cin >> a >> b;
        cout << a * b << "\n";
    }
}