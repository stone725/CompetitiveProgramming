#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans += x <= a && y <= b && z <= a + b;
    }
    cout << ans << "\n";
}