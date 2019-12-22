#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, mx2 = 0;
    for (auto &&i : a)
    {
        cin >> i;
        if (mx < i)
        {
            mx2 = mx;
            mx = i;
        }
        else if (mx2 < i)
        {
            mx2 = i;
        }
    }
    for (auto &&i : a)
    {
        if (mx == i)
        {
            cout << mx2 << "\n";
        }
        else
        {
            cout << mx << "\n";
        }
    }
}