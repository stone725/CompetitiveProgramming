#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    swap(a, c);
    cout << a << " " << b << " " << c << "\n";
}
