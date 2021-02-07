#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, y;
    cin >> n >> y;
    for (int i = min(n, y / 10000); i >= 0; i--)
    {
        for (int j = min(n - i, (y - i * 10000) / 5000); j >= 0; j--)
        {
            int k = (y - i * 10000 - j * 5000) / 1000;
            if (i + j + k == n)
            {
                cout << i << " " << j << " " << k << "\n";
                return 0;
            }
        }
    }
    cout << "-1 -1 -1\n";
}