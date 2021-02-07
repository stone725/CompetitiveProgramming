#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if ('A' <= n && n <= 'Z')
    {
        cout << "1\n";
    }
    else if ('a' <= n && n <= 'z')
    {
        cout << "2\n";
    }
    else
    {
        cout << "0\n";
    }
}