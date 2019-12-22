#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str += '\n';
    vector<bool> check(str.size(), false);
    for (int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        check[num] = true;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (check[i])
        {
            cout << "\"";
        }
        cout << str[i];
    }
}