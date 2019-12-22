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
    for (int i = 0; i + 1 < n; i++)
    {
        if (str[i] != str[i + 1])
        {
            i++;
            ans++;
        }
    }
    cout << ans << "\n";
}