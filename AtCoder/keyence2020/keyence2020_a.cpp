#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h;
    cin >> w;
    cin >> n;
    cout << n / max(h, w) + !!(n % max(h, w)) << "\n";
}