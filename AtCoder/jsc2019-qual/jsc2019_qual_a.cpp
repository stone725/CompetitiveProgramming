#include <iostream>

using namespace std;

int main()
{
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 10; j <= d; j++)
        {
            ans += (j % 10 >= 2) && (j / 10 >= 2) && ((j / 10) * (j % 10) == i);
        }
    }
    cout << ans << "\n";
}