#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (auto &&i : str)
    {
        cout << static_cast<char>((i - 'A' + n) % 26 + 'A');
    }
    cout << "\n";
}