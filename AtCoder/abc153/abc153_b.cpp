#include <iostream>

using namespace std;

int main()
{
    int h, n;
    cin >> h >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        h -= d;
    }
    if (h <= 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}