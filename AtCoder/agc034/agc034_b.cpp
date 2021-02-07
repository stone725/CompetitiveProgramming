#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string s2;
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s.substr(i, 2) == "BC")
        {
            i++;
            s2 += "D";
        }
        else
        {
            s2 += s[i];
        }
    }
    long long ans = 0, a = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == 'B' || s2[i] == 'C')
        {
            a = 0;
        }
        else if (s2[i] == 'D')
        {
            if (a)
            {
                ans += a;
            }
        }
        else
        {
            a++;
        }
    }
    cout << ans << "\n";
}