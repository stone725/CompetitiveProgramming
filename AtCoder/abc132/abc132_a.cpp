#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve()
{
    string str;
    cin >> str;
    sort(begin(str), end(str));
    if (str[0] == str[1] && str[2] == str[3] && str[0] != str[3])
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}