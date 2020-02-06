#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, k;
    cin >> a >> b >> k;
    b = max(0ll, b - max(0ll, k - a));
    a = max(0ll, a - k);
    cout << a << " " << b << "\n";
}