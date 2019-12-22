#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt = 0, maxcnt = 0;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '>')
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        ans += 1. / (cnt + 1);
        maxcnt = max(cnt, maxcnt);
    }
    if (maxcnt < n)
    {
        ans -= 1;
        ans += 1. / (maxcnt + 2);
    }
    cout << setprecision(15) << ans << "\n";
}