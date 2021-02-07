#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << string(str.size(), 'x') << "\n";
}