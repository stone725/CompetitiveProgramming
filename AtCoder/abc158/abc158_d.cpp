#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    bool reversed = false;
    string ans, trats, goal;
    cin >> ans;
    cin >> q;
    int t, f;
    string c;
    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            reversed = !reversed;
        }
        else
        {
            cin >> f >> c;
            if ((f == 1) == !reversed)
            {
                trats += c;
            }
            else
            {
                goal += c;
            }
        }
    }
    ans = string(rbegin(trats), rend(trats)) + ans + goal;
    if (reversed)
    {
        reverse(begin(ans), end(ans));
    }
    cout << ans << "\n";
}