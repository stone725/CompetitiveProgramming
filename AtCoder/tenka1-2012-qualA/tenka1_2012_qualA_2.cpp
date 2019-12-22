#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << str;
    while (cin >> str)
    {
        cout << "," << str;
    }
    cout << "\n";
}