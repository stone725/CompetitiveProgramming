#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i += 3)
    {
        if (str.size() < i + 2 || str.substr(i, 2) != "AC")
        {
            cout << "Failed...\n";
            return 0;
        }
    }
    cout << "Done!\n";
}