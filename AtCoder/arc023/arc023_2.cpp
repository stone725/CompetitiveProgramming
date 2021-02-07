#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int r, c, d;
    cin >> r >> c >> d;
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int num;
            cin >> num;
            if ((i + j) <= d && (i + j) % 2 == d % 2)
            {
                ans = max(ans, num);
            }
        }
    }
    cout << ans << "\n";
}