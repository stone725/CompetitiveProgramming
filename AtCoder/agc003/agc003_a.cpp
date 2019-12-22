#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (!!count(begin(str), end(str), 'N') == !!count(begin(str), end(str), 'S'))
    {
        if (!!count(begin(str), end(str), 'W') == !!count(begin(str), end(str), 'E'))
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}