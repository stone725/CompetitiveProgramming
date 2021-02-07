#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int cnt = 0;
        while (num % 10 == 0)
        {
            cnt++;
            num /= 10;
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}