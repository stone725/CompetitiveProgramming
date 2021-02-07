#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    cin >> d;
    while (d--)
    {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int catX, catY;
            cin >> catX >> catY;
            ans += x <= catX && catX <= x + w && y <= catY && catY <= y + h;
        }
        cout << ans << "\n";
    }
}