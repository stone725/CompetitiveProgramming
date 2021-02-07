#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str[str.size() - 1]++;
    cout << str << "\n";
}