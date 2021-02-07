#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 1, add = 1;
    for (int i = 0; i < n; i++)
    {
        add *= 5;
        ans += add;
    }
    cout << ans << "\n";
}