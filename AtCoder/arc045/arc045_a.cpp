#include <iostream>
#include <string>

using namespace std;

string res(string str)
{
    if (str == "Left")
    {
        return "<";
    }
    else if (str == "Right")
    {
        return ">";
    }
    else
    {
        return "A";
    }
}

int main()
{
    string str;
    cin >> str;
    cout << res(str);
    while (cin >> str)
    {
        cout << " " << res(str);
    }
    cout << "\n";
}