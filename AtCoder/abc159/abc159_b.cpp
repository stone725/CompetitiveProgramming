#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string checkstr(begin(str), begin(str) + str.size() / 2);
    if (str != string(rbegin(str), rend(str)))
    {
        cout << "No\n";
        return 0;
    }
    if (checkstr != string(rbegin(checkstr), rend(checkstr)))
    {
        cout << "No\n";
        return 0;
    }
    checkstr = string(begin(str) + str.size() / 2 + 1, end(str));

    if (checkstr != string(rbegin(checkstr), rend(checkstr)))
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}