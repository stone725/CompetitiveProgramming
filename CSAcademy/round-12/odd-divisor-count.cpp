#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int cnt = 0;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j)
                continue;
            cnt += 1 + (j * j < i);
        }
        ans += cnt % 2;
    }
    cout << ans << "\n";
}