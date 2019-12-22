#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int num = stoi(str), div = 0;
    for (auto &&i : str)
    {
        div += i - '0';
    }
    if (num % div)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
}