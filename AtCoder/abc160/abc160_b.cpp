#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    cout << 1000 * (x / 500) + 5 * ((x % 500) / 5) << "\n";
}
