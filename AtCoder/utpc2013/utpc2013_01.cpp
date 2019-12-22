#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int cnt[4] = {};
    bool check = true;
    for (int i = 0; i < 4; i++)
    {
        switch (str[i])
        {
        case 'B':
            cnt[i] += 2;
            break;
        case 'A':
        case 'D':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
            cnt[i]++;
            break;
        }
        switch (i)
        {
        case 2:
            check &= cnt[i] == 1;
            break;
        default:
            check &= cnt[i] == 0;
        }
    }
    if (check)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
}