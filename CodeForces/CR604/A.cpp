#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        str = "D" + str + "\n";
        bool flag = false;
        for (int i = 1; i + 1 < str.size(); i++)
        {
            if (str[i] != '?' && str[i] == str[i + 1])
            {
                flag = true;
                break;
            }
            if (str[i] == '?')
            {
                for (char c = 'a'; c < 'd'; c++)
                {
                    if (c != str[i - 1] && c != str[i + 1])
                    {
                        str[i] = c;
                        break;
                    }
                }
            }
        }
        if (flag)
        {
            cout << "-1\n";
            continue;
        }
        cout << str.substr(1);
    }
}