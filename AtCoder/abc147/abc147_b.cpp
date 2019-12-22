#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 1; i * 2 <= str.size(); i++)
    {
        ans += str[i - 1] != str[str.size() - i];
    }
    cout << ans << "\n";
}