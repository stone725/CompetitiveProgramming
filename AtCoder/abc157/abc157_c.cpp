#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1);
    for (int i = 0; i < m; i++)
    {
        int s, c;
        cin >> s >> c;
        if (a[s - 1] != -1 && a[s - 1] != c)
        {
            cout << "-1\n";
            return 0;
        }
        if (s == 1 && c == 0 && n != 1)
        {
            cout << "-1\n";
            return 0;
        }
        a[s - 1] = c;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            cout << a[i];
        }
        else
        {
            if (i == 0 && n != 1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
    cout << "\n";
}