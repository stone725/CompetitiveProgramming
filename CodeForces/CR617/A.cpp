#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        bool odd = false, even = false;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            sum += a % 2;
            if (a % 2)
            {
                odd = true;
            }
            else
            {
                even = true;
            }
        }
        if (sum % 2 || (odd && even))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}