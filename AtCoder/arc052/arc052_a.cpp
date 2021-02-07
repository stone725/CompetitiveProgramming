#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int ans = 0;
    for (auto &&i : str)
    {
        if ('0' <= i && i <= '9')
        {
            ans *= 10;
            ans += i - '0';
        }
    }
    cout << ans << "\n";
}