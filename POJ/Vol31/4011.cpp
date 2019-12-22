#include <iostream>

using namespace std;

int main()
{
    int ate;
    cin >> ate;
    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i + j == ate)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}