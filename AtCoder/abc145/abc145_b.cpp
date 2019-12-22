#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.substr(0, n / 2) == str.substr(n / 2))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}