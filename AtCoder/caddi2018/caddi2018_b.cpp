#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        check = check || (a % 2);
    }
    if (check)
    {
        cout << "first\n";
    }
    else
    {
        cout << "second\n";
    }
}