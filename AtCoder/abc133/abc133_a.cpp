#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    cin >> a >> b;
    cout << min(a * n, b) << "\n";
}