#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size())
    {
        cout << "UNRESTORABLE\n";
        return 0;
    }
    bool check;
    for (int i = s.size() - t.size(); i >= 0; i--)
    {
        check = true;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j] && s[i + j] != '?')
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            s = s.substr(0, i) + t + s.substr(i + t.size());
            break;
        }
    }
    if (check)
    {
        for (auto &&i : s)
        {
            if (i == '?')
            {
                cout << "a";
            }
            else
            {
                cout << i;
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "UNRESTORABLE\n";
    }
}