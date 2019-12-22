#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (i % 2)
        {
            if (str[i] == 'R')
            {
                cout << "No\n";
                return 0;
            }
        }
        else
        {
            if (str[i] == 'L')
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}