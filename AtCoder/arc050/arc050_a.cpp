#include <iostream>

using namespace std;

int main()
{
    char C, c;
    cin >> C >> c;
    if (C - 'A' == c - 'a')
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}