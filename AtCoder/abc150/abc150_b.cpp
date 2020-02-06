#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i + 3 <= n; i++)
    {
        ans += str.substr(i, 3) == "ABC";
    }
    cout << ans << "\n";
}