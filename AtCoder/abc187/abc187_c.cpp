#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> check1, check2;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str[0] == '!')
        {
            if (check1.count(str.substr(1)))
            {
                cout << str.substr(1) << "\n";
                return 0;
            }
            check2.insert(str.substr(1));
        }
        else
        {
            if (check2.count(str))
            {
                cout << str << "\n";
                return 0;
            }
            check1.insert(str);
        }
    }
    cout << "satisfiable\n";
}