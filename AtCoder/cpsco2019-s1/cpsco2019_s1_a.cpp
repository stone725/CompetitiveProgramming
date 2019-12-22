#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    cout << a / 3 + !!(a % 3) << " " << min(a, n / 3) << "\n";
}