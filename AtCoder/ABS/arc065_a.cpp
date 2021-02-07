#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string addStrings[] = {"dream", "dreamer", "erase", "eraser"};
    for (auto &&i : addStrings)
    {
        reverse(begin(i), end(i));
    }
    reverse(begin(s), end(s));
    for (int i = 0; i < s.size();)
    {
        bool flag = true;
        for (auto &&j : addStrings)
        {
            if (s.size() < i + j.size())
                continue;
            if (s.substr(i, j.size()) == j)
            {
                i += j.size();
                flag = false;
            }
        }
        if (flag)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}