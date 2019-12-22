#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str += ";";
    string ans[2];
    bool stringadd[2] = {};
    bool isNum = true;
    string addstr = "";
    for (auto &&i : str)
    {
        if (i == ',' || i == ';')
        {
            if (addstr == "" || (addstr[0] == '0' && 1 < addstr.size()))
                isNum = false;
            if (stringadd[1 - isNum])
            {
                ans[1 - isNum] += ",";
            }
            stringadd[1 - isNum] = true;
            ans[1 - isNum] += addstr;
            addstr = "";
            isNum = true;
        }
        else
        {
            isNum = isNum && '0' <= i && i <= '9';
            addstr += i;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (!stringadd[i])
        {
            cout << "-\n";
            continue;
        }
        cout << "\"" << ans[i] << "\"\n";
    }
}