#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
        return 0;
    }
    vector<int> a, b;
    for (int i = 1; i <= 2 * n; i++)
    {
        if ((i / 2) % 2 == 0)
        {
            a.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    cout << a[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << a[i];
    }
    for (auto &&i : b)
    {
        cout << " " << i;
    }
    cout << "\n";
}