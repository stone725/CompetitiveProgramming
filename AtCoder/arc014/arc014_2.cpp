#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string nowstring;
    cin >> nowstring;
    set<string> s;
    s.insert(nowstring);
    bool win = true;
    for (int i = 0; i < n - 1; i++)
    {
        string nextstring;
        cin >> nextstring;
        if (nextstring[0] != nowstring.back() || s.count(nextstring))
        {
            if (win)
            {
                cout << "WIN\n";
                return 0;
            }
            else
            {
                cout << "LOSE\n";
                return 0;
            }
        }
        win = !win;
        nowstring = nextstring;
        s.insert(nowstring);
    }
    cout << "DRAW\n";
}