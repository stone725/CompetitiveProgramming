#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    while (cin >> str && str != "#")
    {
        int y, m, d;
        cin >> y >> m >> d;
        if (y < 31)
        {
            cout << str << " " << y << " " << m << " " << d << "\n";
        }
        else if (y == 31)
        {
            if (m <= 4)
            {
                cout << str << " " << y << " " << m << " " << d << "\n";
            }
            else
            {
                cout << "? " << y - 30 << " " << m << " " << d << "\n";
            }
        }
        else
        {
            cout << "? " << y - 30 << " " << m << " " << d << "\n";
        }
    }
}