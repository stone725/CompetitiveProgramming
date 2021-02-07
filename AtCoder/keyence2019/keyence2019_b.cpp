#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int j = 0; j <= 7; j++)
    {
        if (s.substr(0, j) + s.substr(s.size() - 7 + j) == "keyence")
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}