#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < max(a, b); i++)
    {
        cout << min(a, b);
    }
    cout << "\n";
}