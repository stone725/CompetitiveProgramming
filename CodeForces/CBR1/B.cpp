#include <iostream>
#include <string>

using namespace std;

string query(string str)
{
    bool isRXCY = false;

    for (int i = str.size() - 1; i > 1; i--)
    {
        if (str[i] == 'C')
        {
            isRXCY = true;
            break;
        }
    }
    if (str.size() < 4 || str[0] != 'R' || !('0' <= str[1] && str[1] <= '9'))
    {
        isRXCY = false;
    }
    string res;
    if (isRXCY)
    {
        long long row = 0, i;
        for (i = 1; i < str.size(); i++)
        {
            if (str[i] == 'C')
            {
                break;
            }
            row = row * 10 + (str[i] - '0');
        }
        long long column = 0;
        for (i++; i < str.size(); i++)
        {
            column = column * 10 + (str[i] - '0');
        }
        do
        {
            column--;
            res = char(column % 26 + 'A') + res;
            column /= 26;
        } while (column);
        res += to_string(row);
        return res;
    }
    else
    {
        long long column = 0, i;
        for (i = 0; i < str.size(); i++)
        {
            if ('0' <= str[i] && str[i] <= '9')
            {
                break;
            }
            column = column * 26 + (str[i] - 'A' + 1);
        }
        res = "R" + str.substr(i) + "C" + to_string(column);
        return res;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        cout << query(str) << "\n";
    }
}