#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, checkStr = "WBWBWWBWBWBW";
    cin >> str;
    int check = 0;
    for (int i = 0; i < 7; i++)
    {
        if (str.substr(0, checkStr.size()) == checkStr)
        {
            check = i;
            break;
        }
        do
        {
            checkStr = checkStr.substr(1) + checkStr[0];
        } while (checkStr[0] != 'W');
    }
    switch (check)
    {
    case 0:
        cout << "Do\n";
        break;
    case 1:
        cout << "Re\n";
        break;
    case 2:
        cout << "Mi\n";
        break;
    case 3:
        cout << "Fa\n";
        break;
    case 4:
        cout << "So\n";
        break;
    case 5:
        cout << "La\n";
        break;
    case 6:
        cout << "Si\n";
        break;
    }
}