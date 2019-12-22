#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (count(begin(str), end(str), 'R') * 2 > n)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}