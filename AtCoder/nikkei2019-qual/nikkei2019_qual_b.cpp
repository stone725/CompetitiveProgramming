#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            ans++;
        }
        if (b[i] != c[i])
        {
            ans++;
            if (a[i] == c[i])
            {
                ans--;
            }
        }
    }
    cout << ans << "\n";
}