#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str.back() == 'T')
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}