#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    if (str[2] == str[3] && str[4] == str[5])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
