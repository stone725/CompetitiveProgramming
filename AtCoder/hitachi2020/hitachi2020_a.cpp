#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    if (str.size() % 2)
    {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < str.size(); i += 2)
    {
        if (str.substr(i, 2) != "hi")
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}