#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 1, ans = 0;
    while (cnt < b)
    {
        cnt += a - 1;
        ans++;
    }
    cout << ans << "\n";
}