#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << min(b * (n / a + !!(n % a)), d * (n / c + !!(n % c))) << "\n";
}